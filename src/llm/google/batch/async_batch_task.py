from __future__ import annotations

import json
import warnings
from pathlib import Path
from typing import Any

from google.genai import types
from pydantic import ValidationError

from src.llm.common.batch_utils import (
    merge,
    parse_output_text,
    sum_normalized_usage,
)
from src.llm.common.common import HasOutputFormat, HasRunWithRetry
from src.llm.common.types import ValidOutputFormat,ThinkingEffort
from src.llm.google.batch.async_client import AsyncGeminiBatchClient
from src.llm.google.batch.input_file import GeminiBatchInputFile
from src.llm.llm_batch_task import LLMBatchTask
from src.models.batch import UserRequest
from src.models.task_config import TaskConfig


NON_RETRYABLE_REASONS = {
    "safety",
    "recitation",
    "language",
    "blocklist",
    "prohibited_content",
    "spii",
}


class AsyncGeminiBatchTask(HasRunWithRetry,HasOutputFormat,LLMBatchTask):

    def __init__(
        self,
        *,
        api_key: str,
        input_path: Path,
        model: str,
        system: str,
        output_format: ValidOutputFormat,
        max_output_tokens: int,
        thinking_effort: ThinkingEffort,
        temperature: float,
    ) -> None:
        self.name = input_path.stem
        self.input_path = input_path
        self.model = model
        self.system = system
        self.output_format = self.validate_output_format(output_format)
        self.max_output_tokens = max_output_tokens
        self.thinking_effort = thinking_effort
        self.temperature = temperature

        self.batch_client = AsyncGeminiBatchClient(api_key=api_key)
        self.batch_input_file = GeminiBatchInputFile(path=input_path)
        self.user_requests: list[UserRequest] = []
        self.contents: list[dict[str, Any]] = []
        self.records: list[dict[str, Any]] = []
        self.retries: list[dict[str, Any]] = []
        self.batch_jobs: list[types.BatchJob] = []
        self.batch_input_files: list[GeminiBatchInputFile] = []

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
        input_path: Path | str | None,
        task_config: TaskConfig,
    ) -> "AsyncGeminiBatchTask":
        if not api_key:
            raise ValueError("AsyncGeminiBatchTask expects a valid API key.")

        if not input_path:
            raise ValueError("AsyncGeminiBatchTask expects a valid input path.")

        return cls(
            api_key=api_key,
            input_path=Path(input_path),
            model=task_config.model.model_name,
            system=task_config.system,
            output_format=task_config.output_format,
            max_output_tokens=task_config.model.max_tokens,
            thinking_effort=task_config.model.thinking_effort,
            temperature=task_config.model.temperature,
        )

    def add_user_inputs(
        self,
        user_requests: str | list[UserRequest],
    ) -> None:
        if isinstance(user_requests, str):
            raise TypeError("AsyncGeminiBatchTask expects a list of UserRequest.")

        existing_ids: set[str] = set()

        for request in user_requests:

            if request.custom_id in existing_ids:
                raise ValueError(f"Duplicate custom_id: {request.custom_id}")

            if not request.user_input.strip():
                raise ValueError("User input must not be empty.")

            existing_ids.add(request.custom_id)

        self.user_requests = list(user_requests)

    async def run(self) -> list[dict[str, Any]]:
        if not self.user_requests:
            raise ValueError("User requests must be added before running the task.")

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
                item["completed"] for item in self.contents
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
                and item["incomplete_reason"].strip().lower()
                not in NON_RETRYABLE_REASONS
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
                == "max_tokens"
                for item in self.contents
            )

            retry_max_tokens = self.max_output_tokens
            if increase_tokens:
                retry_max_tokens += 500 * attempt

            retry_input_file = GeminiBatchInputFile(
                path=(
                    self.input_path.parent
                    / f"{self.name}_retry{attempt}.jsonl"
                )
            )
            retry_contents, retry_records = await self._run_attempt(
                retry_requests,
                batch_input_file=retry_input_file,
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
            merge(self.records, retry_records)

    async def cleanup(self) -> None:
        if self.is_cleaned_up:
            return

        resources = list(zip(self.batch_jobs, self.batch_input_files))
        failed_resources = []

        for batch_job, batch_input_file in reversed(resources):
            try:
                await self.batch_client.clean_up_batch_job(batch_job, batch_input_file)
            except Exception as error:
                failed_resources.append((batch_job, batch_input_file))
                warnings.warn(f"Failed to clean up Gemini batch "f"{batch_job.name}: {error}",RuntimeWarning,)

        self.is_cleaned_up = not failed_resources

    def reset(self) -> None:
        self.batch_input_file.reset_jsonls()
        self.contents = []
        self.records = []
        self.retries = []
        self.batch_jobs = []
        self.batch_input_files = []
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
        batch_input_file: GeminiBatchInputFile,
        max_output_tokens: int,
    ) -> tuple[list[dict[str, Any]], list[dict[str, Any]]]:
        self._write_batch_input_file(
            requests,
            batch_input_file=batch_input_file,
            max_output_tokens=max_output_tokens,
        )

        batch_job = await self.run_with_retry_async(
            self.batch_client.submit,
            batch_input_file,
            self.model,
        )

        self.batch_jobs.append(batch_job)
        self.batch_input_files.append(batch_input_file)

        completed_job = await self.batch_client.wait_for_completion(batch_job.name)
        self.batch_jobs[-1] = completed_job

        results = await self.run_with_retry_async(
            self.batch_client.collect_results,
            completed_job,
        )
        return self._collect_results(requests, results)

    def _write_batch_input_file(
        self,
        requests: list[UserRequest],
        *,
        batch_input_file: GeminiBatchInputFile,
        max_output_tokens: int,
    ) -> None:
        batch_input_file.reset_jsonls()
        batch_input_file.add_multiple_JSONLs(
            custom_ids=[request.custom_id for request in requests],
            users=[request.user_input for request in requests],
            system=self.system,
            output_format=self.output_format,
            max_output_tokens=max_output_tokens,
            thinking_effort=self.thinking_effort,
            temperature=self.temperature
        )

        batch_input_file.write_to_file()

    def _collect_results(
        self,
        requests: list[UserRequest],
        results: list[dict[str, Any]],
    ) -> tuple[list[dict[str, Any]], list[dict[str, Any]]]:

        result_map: dict[str, dict[str, Any]] = {}
        records: list[dict[str, Any]] = []

        for result in results:
            custom_id = self._get_result_custom_id(result)
            record = result
            record["custom_id"] = custom_id
            records.append(record)

            if custom_id:
                result_map[custom_id] = result

        contents: list[dict[str, Any]] = []

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

            error = result.get("error",None)
            if error:
                contents.append(
                    self._build_incomplete_content(
                        request.custom_id,
                        self._build_result_error(error),
                    )
                )
                continue

            response_data = result.get("response")
            if not response_data:
                contents.append(
                    self._build_incomplete_content(
                        request.custom_id,
                        "missing_response",
                    )
                )
                continue

            try:
                response = types.GenerateContentResponse.model_validate(
                    response_data
                )
            except ValidationError as error:
                contents.append(
                    self._build_incomplete_content(
                        request.custom_id,
                        f"invalid_response: {error}",
                    )
                )
                continue

            if response.usage_metadata is not None:
                usage = self._normalize_usage(
                    response.usage_metadata.model_dump(mode="json")
                )
                self._total_usage_items.append(usage)
                self._final_usage_by_id[request.custom_id] = usage

            blocked_reason = self._get_blocked_reason(response)

            if blocked_reason:
                contents.append(
                    self._build_incomplete_content(
                        request.custom_id,
                        blocked_reason,
                    )
                )
                continue

            candidate = response.candidates[0] if response.candidates else None

            if candidate is None:
                contents.append(
                    self._build_incomplete_content(
                        request.custom_id,
                        "missing_candidate",
                    )
                )
                continue

            finish_reason = candidate.finish_reason
            if finish_reason and finish_reason.name.strip().lower() != "stop":
                contents.append(
                    self._build_incomplete_content(
                        request.custom_id,
                        finish_reason,
                    )
                )
                continue

            raw_text = self._extract_text(candidate)
            if not raw_text:
                contents.append(
                    self._build_incomplete_content(
                        request.custom_id,
                        "empty_output",
                    )
                )
                continue

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
    def _extract_text(candidate: Any) -> str:
        content = getattr(candidate, "content", None)
        parts = getattr(content, "parts", None) or []
        
        return "".join(
            part.text
            for part in parts
            if getattr(part, "text", None)
            and not getattr(part, "thought", False)
        )

    @staticmethod
    def _get_blocked_reason(response: types.GenerateContentResponse,) -> str:

        prompt_feedback = response.prompt_feedback
        if prompt_feedback is None:
            return ""
        return prompt_feedback.block_reason.name

    @staticmethod
    def _get_result_custom_id(result: dict[str, Any]) -> str:
        custom_id = result.get("key", "") or ""
        if custom_id:
            return str(custom_id)

        metadata = result.get("metadata", {}) or {}
        return str(metadata.get("key", "") or "")

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
    def _build_result_error(error: dict[str, Any]|None) -> str:
        if error:
            return json.dumps(error,ensure_ascii=False)
        return "Unknown error"

    @staticmethod
    def _normalize_usage(usage: dict[str, Any]) -> dict[str, Any]:
        input_tokens = int(usage.get("prompt_token_count", 0) or 0)
        output_tokens = int(
            usage.get("candidates_token_count", 0) or 0
        )
        total_tokens = int(
            usage.get(
                "total_token_count",
                input_tokens + output_tokens,
            )
            or input_tokens + output_tokens
        )
        cached_tokens = int(
            usage.get("cached_content_token_count", 0) or 0
        )
        reasoning_tokens = int(
            usage.get("thoughts_token_count", 0) or 0
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
