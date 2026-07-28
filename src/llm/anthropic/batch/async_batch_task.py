from __future__ import annotations

import json
import warnings
from typing import Any
from pydantic import ValidationError

from anthropic import transform_schema

from src.llm.llm_batch_task import LLMBatchTask
from src.llm.anthropic.batch.async_client import AsyncClaudeBatchClient
from src.llm.common.batch_utils import get_output_schema, merge, parse_output_text,sum_normalized_usage

from src.llm.common.common import HasRunWithRetry,HasOutputFormat
from src.llm.common.types import ValidOutputFormat,ThinkingEffort
from src.models.batch import UserRequest
from src.models.task_config import TaskConfig



class AsyncClaudeBatchTask(HasRunWithRetry,HasOutputFormat,LLMBatchTask):

    def __init__(
        self,
        *,
        api_key: str,
        model: str,
        system: str,
        output_format: ValidOutputFormat,
        thinking_effort:ThinkingEffort,
        max_output_tokens: int,
    ) -> None:

        self.model = model
        self.system = system
        self.output_format = self.validate_output_format(output_format)
        self.thinking_effort = thinking_effort
        self.max_output_tokens = max_output_tokens

        self.batch_client = AsyncClaudeBatchClient(api_key=api_key)
        self.user_requests: list[UserRequest] = []
        self.contents: list[dict[str, Any]] = []
        self.records: list[dict[str, Any]] = []
        self.retries: list[dict[str, Any]] = []
        self.batch_ids: list[str] = []

        self.has_valid_output = False
        self.is_cleaned_up = False
        self.total_usage: dict[str, Any] = {}
        self.final_usage: dict[str, Any] = {}

        self._total_usage_items: list[dict[str, Any]] = []
        self._final_usage_by_id: dict[str, dict[str, Any]] = {}

    @classmethod
    def load_from_task_config(
        cls,
        *,
        api_key: str | None,
        task_config: TaskConfig,
    ) -> "AsyncClaudeBatchTask":

        if not api_key:
            raise ValueError("AsyncClaudeBatchTask expects a valid API key.")

        return cls(
            api_key=api_key,
            model=task_config.model.model_name,
            system=task_config.system,
            output_format=task_config.output_format,
            thinking_effort=task_config.model.thinking_effort,
            max_output_tokens=task_config.model.max_tokens,
        )

    def add_user_inputs(
        self,
        user_requests: str | list[UserRequest],
    ) -> None:

        if isinstance(user_requests, str):
            raise TypeError("AsyncClaudeBatchTask expects a list of UserRequest.")

        exist_ids: set[str] = set()

        for request in user_requests:
            if (
                not request.custom_id.strip()
                or len(request.custom_id) > 64
            ):
                raise ValueError(
                    "Claude custom_id must contain between 1 and 64 characters."
                )

            if request.custom_id in exist_ids:
                raise ValueError(f"Duplicate custom_id: {request.custom_id}")

            if not request.user_input.strip():
                raise ValueError("User input must not be empty.")
            exist_ids.add(request.custom_id)

        self.user_requests = list(user_requests)

    async def run(self) -> list[dict[str, Any]]:

        if not self.user_requests:
            raise ValueError("User requests must be added before running the task.")

        self.reset()

        try:
            contents, records = await self._run_attempt(
                self.user_requests,
                max_output_tokens=self.max_output_tokens,
            )

            self.contents = contents
            self.records = records

            await self.retry_batch()

            self.has_valid_output = all(
                item["completed"]
                for item in self.contents
            )
            self._update_usage_snapshots()
            return self.contents
        finally:
            await self.cleanup()

    async def retry_batch(self, max_retries: int = 3) -> None:
        for attempt in range(1, max_retries + 1):
            retry_ids = {
                item["custom_id"]
                for item in self.contents
                if not item["completed"]
                and item["incomplete_reason"] not in {"refusal","model_context_window_exceeded"}
            }

            if not retry_ids:
                return

            retry_requests = [
                request
                for request in self.user_requests
                if request.custom_id in retry_ids
            ]

            increase_tokens = any(
                item["custom_id"] in retry_ids
                and item["incomplete_reason"] == "max_tokens"
                for item in self.contents
            )

            retry_max_tokens = self.max_output_tokens
            if increase_tokens:
                retry_max_tokens += 500 * attempt

            retry_contents, retry_records = await self._run_attempt(
                retry_requests,
                max_output_tokens=retry_max_tokens,
            )

            self.retries.append(
                {
                    "attempt": attempt,
                    "retry_custom_ids": sorted(retry_ids),
                    "retry_contents": retry_contents,
                    "retry_records": retry_records,
                }
            )
            merge(self.contents, retry_contents)
            merge(self.records,retry_records)

    async def cleanup(self) -> None:
        if self.is_cleaned_up:
            return

        failed_batch_ids: list[str] = []

        for batch_id in reversed(self.batch_ids):
            try:
                await self.batch_client.clean_up_batch(batch_id)
            except Exception as error:
                failed_batch_ids.append(batch_id)
                warnings.warn(
                    f"Failed to clean up Claude batch {batch_id}: {error}",
                    RuntimeWarning,
                )

        self.batch_ids = list(reversed(failed_batch_ids))
        self.is_cleaned_up = not self.batch_ids


    async def close(self):
        try:
            await self.batch_client.close()
        except Exception as error:
            warnings.warn(
                f"Failed to close Claude batch client: {error}",
                RuntimeWarning,
            )


    def reset(self) -> None:
        self.contents = []
        self.records = []
        self.retries = []
        self.batch_ids = []
        self.has_valid_output = False
        self.is_cleaned_up = False
        self.total_usage = {}
        self.final_usage = {}
        self._total_usage_items = []
        self._final_usage_by_id = {}

    async def _run_attempt(
        self,
        requests: list[UserRequest],
        *,
        max_output_tokens: int,
    ) -> tuple[list[dict[str, Any]], list[dict[str, Any]]]:

        payload = self._build_batch_requests(
            requests,
            max_output_tokens=max_output_tokens,
        )

        batch = await self.batch_client.submit(payload)
        self.batch_ids.append(batch.id)

        await self.run_with_retry_async(
            self.batch_client.wait_for_completion,
            batch.id,
        )

        results = await self.run_with_retry_async(
            self.batch_client.collect_results,
            batch.id,
        )

        return self._collect_results(requests, results)

    def _build_batch_requests(
        self,
        requests: list[UserRequest],
        *,
        max_output_tokens: int,
    ) -> list[dict[str, Any]]:

        output_schema = get_output_schema(
            self.output_format,
        )

        transformed_schema = (
            transform_schema(output_schema)
            if output_schema is not None
            else None
        )

        batch_requests: list[dict[str, Any]] = []

        for request in requests:
            params: dict[str, Any] = {
                "model": self.model,
                "max_tokens": max_output_tokens,
                "system": self.system,
                "messages": [
                    {
                        "role": "user",
                        "content": request.user_input,
                    }
                ],
            }

            if transformed_schema is not None:
                params["output_config"] = {
                    "format": {
                        "type": "json_schema",
                        "schema": transformed_schema,
                    }
                }

            if self.thinking_effort is not None:
                params["thinking"] = {
                    "type": "adaptive",
                }
                params["output_config"]["effort"] = self.thinking_effort

            batch_requests.append(
                {
                    "custom_id": request.custom_id,
                    "params": params,
                }
            )

        return batch_requests

    def _collect_results(
        self,
        requests: list[UserRequest],
        results: list[Any],
    ) -> tuple[list[dict[str, Any]], list[dict[str, Any]]]:

        result_map = {
            result.custom_id: result
            for result in results
        }

        contents: list[dict[str, Any]] = []
        records: list[dict[str, Any]] = []

        for request in requests:
            result = result_map.get(request.custom_id)

            if result is None:
                contents.append(
                    self._build_incomplete_content(
                        request.custom_id,
                        "missing_result",
                    )
                )
                continue

            record = result.model_dump(mode="json")
            records.append(record)

            result_type = result.result.type
            if result_type != "succeeded":
                contents.append(
                    self._build_incomplete_content(
                        request.custom_id,
                        self._build_result_error(result.result),
                    )
                )
                continue

            message = result.result.message

            usage = self._normalize_usage(message.usage.model_dump(mode="json"))
            self._total_usage_items.append(usage)
            self._final_usage_by_id[request.custom_id] = usage

            if message.stop_reason in {"max_tokens","refusal","model_context_window_exceeded",}:
                contents.append(
                    self._build_incomplete_content(
                        request.custom_id,
                        message.stop_reason,
                    )
                )
                continue

            raw_text = "".join(
                block.text
                for block in message.content
                if getattr(block, "type", None) == "text"
            )

            try:
                parsed_content = parse_output_text(
                    raw_text,
                    self.output_format,
                )
            except ValidationError as error:
                contents.append(
                    self._build_incomplete_content(
                        request.custom_id,
                        f"output_parsing_failed: {error}",
                    )
                )
                continue

            contents.append(
                {
                    "custom_id": request.custom_id,
                    "content": parsed_content,
                    "completed": True,
                    "incomplete_reason": "",
                }
            )

        return contents, records

    def _update_usage_snapshots(self) -> None:
        self.total_usage = {
            self.model: sum_normalized_usage(self._total_usage_items)
        }
        self.final_usage = {
            self.model: sum_normalized_usage(
                list(self._final_usage_by_id.values())
            )
        }

    @staticmethod
    def _build_incomplete_content(
        custom_id: str,
        reason: str,
    ) -> dict[str, Any]:
        return {
            "custom_id": custom_id,
            "content": "",
            "completed": False,
            "incomplete_reason": reason,
        }

    @staticmethod
    def _build_result_error(result: Any) -> str:
        data = result.model_dump(mode="json")
        error = data.get("error")
        if error:
            return json.dumps(error, ensure_ascii=False)
        return str(data.get("type", "unknown_error"))

    @staticmethod
    def _normalize_usage(usage: dict[str, Any]) -> dict[str, Any]:
        uncached_tokens = int(usage.get("input_tokens", 0) or 0)
        cache_creation_tokens = int(
            usage.get("cache_creation_input_tokens", 0)
            or 0
        )
        cache_read_tokens = int(
            usage.get("cache_read_input_tokens", 0)
            or 0
        )
        input_tokens = (
            uncached_tokens
            + cache_creation_tokens
            + cache_read_tokens
        )
        output_tokens = int(usage.get("output_tokens", 0) or 0)

        return {
            "input_tokens": input_tokens,
            "output_tokens": output_tokens,
            "total_tokens": input_tokens + output_tokens,
            "input_tokens_details": {
                "cached_tokens": cache_read_tokens,
            },
            "output_tokens_details": {
                "reasoning_tokens": 0,
            },
        }
