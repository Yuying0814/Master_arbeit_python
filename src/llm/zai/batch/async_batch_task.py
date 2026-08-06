from __future__ import annotations

import warnings
from pathlib import Path
from typing import Any

from pydantic import ValidationError
from zai.types.batch import Batch

from src.llm.common.batch_utils import (
    merge,
    parse_output_text,
    sum_normalized_usage,
)
from src.llm.common.common import HasOutputFormat, HasRunWithRetry
from src.llm.common.types import ThinkingEffort, ValidOutputFormat
from src.llm.zai.batch.async_client import AsyncGlmBatchClient
from src.llm.zai.batch.input_file import GlmBatchInputFile
from src.llm.llm_batch_task import LLMBatchTask
from src.models.batch import UserRequest
from src.models.task_config import TaskConfig

NOT_RETRIABLE_REASONS = [
    "sensitive","model_context_window_exceeded",
    "1000","1001","1003","1005", # Authentication Failed
    "1210","1211","1212","1213","1214","1215","1221","1222", # Invalid parameter
    "1220", # No permission
    "1261", # Prompt too long
    "1301", # Sensitive content
    "1113","1308","1309","1310","1311","1313","1314","1315","1316","1317","1318","1319","1320","1321"
    # Usage limit reached or Insufficient balance
]

class AsyncGlmBatchTask(HasRunWithRetry,HasOutputFormat,LLMBatchTask,):

    def __init__(
        self,
        *,
        api_key: str,
        input_path: Path,
        model: str | None = None,
        instructions: str | None = None,
        thinking_effort: ThinkingEffort = None,
        temperature: float | None = None,
        output_format: ValidOutputFormat = None,
        max_output_tokens: int | None = None,
    ) -> None:

        self.name = input_path.stem
        self.input_path = input_path
        self.model = model or "glm-4-flash"
        self.instructions = instructions if instructions is not None else "You are a helpful assistant."
        self.thinking_effort = thinking_effort
        self.temperature = temperature
        self.output_format = self.validate_output_format(output_format)
        self.max_output_tokens = max_output_tokens if max_output_tokens is not None else 5000

        self.batch_client = AsyncGlmBatchClient(api_key=api_key)
        self.batch_input_file = GlmBatchInputFile(path=self.input_path)
        self.batches: list[Batch] = []
        self.batch_input_files: list[GlmBatchInputFile] = []

        self.user_requests: list[UserRequest] = []
        self.contents: list[dict[str, Any]] = []
        self.records: list[dict[str, Any]] = []
        self.retries: list[dict[str, Any]] = []

        self.has_valid_output = False
        self.is_cleaned_up = False
        self.total_usage: dict[str, Any] = {}
        self.final_usage: dict[str, Any] = {}
        self._total_usage_items: list[dict[str, Any]] = []
        self._final_usage_by_id: dict[str, dict[str, Any]] = {}

    @classmethod
    def load_from_task_config(cls,*,api_key: str | None,input_path: Path | str | None,task_config: TaskConfig,) -> "AsyncGlmBatchTask":

        if not api_key:
            raise ValueError("AsyncGlmBatchTask expects a valid API key.")

        if not input_path:
            raise ValueError("AsyncGlmBatchTask expects a valid input path.")

        return cls(
            api_key=api_key,
            input_path=Path(input_path),
            model=task_config.model.model_name,
            instructions=task_config.system,
            thinking_effort=task_config.model.thinking_effort,
            temperature=task_config.model.temperature,
            output_format=task_config.output_format,
            max_output_tokens=task_config.model.max_tokens,
        )

    def add_user_inputs(self,user_requests: str | list[UserRequest],) -> None:

        if isinstance(user_requests, str):
            raise TypeError("AsyncGlmBatchTask expects a list of UserRequest.")

        existing_ids: set[str] = set()

        for request in user_requests:
            if not request.custom_id.strip():
                raise ValueError("custom_id must not be empty.")

            if request.custom_id in existing_ids:
                raise ValueError(f"Duplicate custom_id: {request.custom_id}")

            existing_ids.add(request.custom_id)

        self.user_requests = list(user_requests)

    async def run(self) -> list[dict[str, Any]]:
        self.reset()

        try:
            contents, records = await self._run_attempt(
                self.user_requests,
                batch_input_file=self.batch_input_file,
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

    async def _run_attempt(
        self,
        requests: list[UserRequest],
        *,
        batch_input_file: GlmBatchInputFile,
        max_output_tokens: int,
    ) -> tuple[list[dict[str, Any]],list[dict[str, Any]],]:

        self._write_batch_input_file(
            requests,
            batch_input_file=batch_input_file,
            max_output_tokens=max_output_tokens,
        )

        batch = await self.run_with_retry_async(
            self.batch_client.submit,
            batch_input_file,
        )
        self.batches.append(batch)
        self.batch_input_files.append(batch_input_file)

        completed_batch = await self.run_with_retry_async(
            self.batch_client.wait_for_completion,
            batch.id,
        )
        if completed_batch.status == "failed":
            batch_errors = (
                completed_batch.errors.data
                if completed_batch.errors is not None
                else []
            )
            raise RuntimeError(
                f"GLM batch validation failed: {batch_errors}"
            )
        self.batches[-1] = completed_batch

        records = await self.run_with_retry_async(
            self.batch_client.collect_results,
            completed_batch,
        )

        contents = self._collect_results(requests, records)
        return contents, records

    async def retry_batch(self,max_retries: int = 3,) -> None:

        for attempt in range(1, max_retries + 1):
            retry_ids = {
                item["custom_id"]
                for item in self.contents
                if not item["completed"]
                and item["incomplete_reason"].strip().lower() not in NOT_RETRIABLE_REASONS
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
                and item["incomplete_reason"].strip().lower()
                == "length"
                for item in self.contents
            )

            retry_max_tokens = self.max_output_tokens
            if increase_tokens:
                retry_max_tokens += 500 * attempt

            retry_input_file = GlmBatchInputFile(
                path=(
                    self.input_path.parent
                    / f"{self.name}_retry{attempt}.jsonl"
                )
            )

            retry_contents, retry_records = (
                await self._run_attempt(
                    retry_requests,
                    batch_input_file=retry_input_file,
                    max_output_tokens=retry_max_tokens,
                )
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
            merge(self.records, retry_records)

    def _write_batch_input_file(self,
        requests: list[UserRequest],
        *,
        batch_input_file: GlmBatchInputFile,
        max_output_tokens: int,
    ) -> None:

        batch_input_file.reset_JSONLs()
        batch_input_file.add_multiple_JSONLs(
            custom_ids=[request.custom_id for request in requests],
            users=[request.user_input for request in requests],
            model=self.model,
            instructions=self.instructions,
            thinking_effort=self.thinking_effort,
            temperature=self.temperature,
            output_format=self.output_format,
            max_output_tokens=max_output_tokens,
        )
        batch_input_file.write_to_file()

    def _collect_results(self,requests: list[UserRequest],records: list[dict[str, Any]],) -> list[dict[str, Any]]:

        records_map = {
            record.get("custom_id"): record
            for record in records
            if record.get("custom_id")
        }

        contents: list[dict[str, Any]] = []

        for request in requests:
            record = records_map.get(request.custom_id)

            if record is None:
                contents.append(
                    self._build_incomplete_content(
                        request.custom_id,
                        "missing_result",
                    )
                )
                continue

            batch_error = record.get("error") or {}
            if batch_error:
                contents.append(
                    self._build_incomplete_content(
                        request.custom_id,
                        self._get_error_reason(batch_error),
                    )
                )
                continue

            response = record.get("response") or {}
            status_code = int(
                response.get("status_code", 0) or 0
            )
            body = response.get("body") or {}
            body_error = body.get("error") or {}

            if body_error:
                contents.append(
                    self._build_incomplete_content(
                        request.custom_id,
                        self._get_error_reason(body_error),
                    )
                )
                continue

            if status_code != 200:
                contents.append(
                    self._build_incomplete_content(
                        request.custom_id,
                        f"http_{status_code or 'unknown'}",
                    )
                )
                continue

            usage = self._normalize_usage(
                body.get("usage") or {}
            )
            self._total_usage_items.append(usage)
            self._final_usage_by_id[request.custom_id] = usage

            choices = body.get("choices") or []
            if not choices:
                contents.append(
                    self._build_incomplete_content(
                        request.custom_id,
                        "missing_choice",
                    )
                )
                continue

            text_fragments: list[str] = []
            incomplete_reason = ""

            for choice in choices:
                finish_reason = choice.get("finish_reason", "") or ""

                if finish_reason and finish_reason.strip().lower() != "stop":
                    incomplete_reason = finish_reason
                    break

                message = choice.get("message") or {}
                message_content = message.get("content")

                if  not message_content:
                    incomplete_reason = "empty_output"
                    break

                text_fragments.append(message_content)

            if incomplete_reason:
                contents.append(
                    self._build_incomplete_content(
                        request.custom_id,
                        incomplete_reason,
                    )
                )
                continue

            raw_text = "".join(text_fragments)

            try:
                parsed_content = parse_output_text(raw_text,self.output_format,)
            except ValidationError:
                contents.append(
                    self._build_incomplete_content(
                        request.custom_id,
                        "output_parsing_failed",
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

        return contents

    async def cleanup(self) -> None:
        if self.is_cleaned_up:
            return

        cleanup_results: list[bool] = []
        resources = list(zip(self.batches, self.batch_input_files))

        for batch, batch_input_file in reversed(resources):
            try:
                is_canceled = await self.batch_client.cancel(batch)
                is_deleted = await self.batch_client.delete_file(batch_input_file.input_file_id)
                cleanup_results.append(is_canceled and is_deleted)
            except Exception as error:
                cleanup_results.append(False)
                warnings.warn(
                    f"Failed to clean up GLM batch "
                    f"{batch.id}: {error}",
                    RuntimeWarning,
                )

        self.is_cleaned_up = all(cleanup_results)

    async def close(self) -> None:
        try:
            await self.batch_client.close()
        except Exception as error:
            warnings.warn(f"Failed to close GLM batch client: {error}",RuntimeWarning,)

    def reset(self) -> None:
        self.batch_input_file.reset_JSONLs()
        self.batches = []
        self.batch_input_files = []
        self.contents = []
        self.records = []
        self.retries = []
        self.has_valid_output = False
        self.is_cleaned_up = False
        self.total_usage = {}
        self.final_usage = {}
        self._total_usage_items = []
        self._final_usage_by_id = {}

    def _update_usage_snapshots(self) -> None:
        self.total_usage = {
            self.model: sum_normalized_usage(
                self._total_usage_items
            )
        }
        self.final_usage = {
            self.model: sum_normalized_usage(
                list(self._final_usage_by_id.values())
            )
        }

    @staticmethod
    def _build_incomplete_content(custom_id: str,reason: str,
    ) -> dict[str, Any]:
        return {
            "custom_id": custom_id,
            "content": "",
            "completed": False,
            "incomplete_reason": reason,
        }

    @staticmethod
    def _get_error_reason(error: dict[str, Any]) -> str:
        code = str(error.get("code", "") or "")
        if code:
            return code

        error_type = str(error.get("type", "") or "")
        if error_type:
            return error_type

        return "unknown_error"

    @staticmethod
    def _normalize_usage(
        usage: dict[str, Any],
    ) -> dict[str, Any]:
        input_tokens = int(
            usage.get("prompt_tokens", 0) or 0
        )
        output_tokens = int(
            usage.get("completion_tokens", 0) or 0
        )
        total_tokens = int(
            usage.get(
                "total_tokens",
                input_tokens + output_tokens,
            )
            or input_tokens + output_tokens
        )

        prompt_details = (
            usage.get("prompt_tokens_details") or {}
        )
        completion_details = (
            usage.get("completion_tokens_details") or {}
        )

        cached_tokens = int(
            prompt_details.get("cached_tokens", 0) or 0
        )
        reasoning_tokens = int(
            completion_details.get("reasoning_tokens", 0) or 0
        )

        return {
            "input_tokens": input_tokens,
            "output_tokens": output_tokens,
            "total_tokens": total_tokens,
            "input_tokens_details": {
                "cached_tokens": cached_tokens,
            },
            "output_tokens_details": {
                "reasoning_tokens": reasoning_tokens,
            },
        }
