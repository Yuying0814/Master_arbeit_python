from __future__ import annotations
import warnings

from pathlib import Path
from typing import Any

from pydantic import ValidationError

from src.models.task_config import TaskConfig
from src.models.llm.batch import UserRequest
from src.models.llm.common import NormalizedUsage

from src.llm.llm_batch_task import LLMBatchTask
from src.llm.common.common import HasRunWithRetry,HasOutputFormat
from src.llm.common.types import ValidOutputFormat,ThinkingEffort
from src.llm.common.batch_utils import parse_output_text,merge,sum_normalized_usage

from src.llm.kimi.batch.async_client import AsyncKimiBatchClient
from src.llm.kimi.batch.input_file import KimiBatchInputFile


NOT_RETRIABLE_REASONS = {
    "content_filter",
    "invalid_request_error",
    "invalid_authentication_error",
    "incorrect_api_key_error",
    "permission_denied_error",
    "resource_not_found_error",
    "exceeded_current_quota_error",
}


class AsyncKimiBatchTask(HasRunWithRetry,HasOutputFormat,LLMBatchTask):

    def __init__(self,
                 api_key:str,
                 input_path:Path,
                 *,model:str|None = None,
                 instructions: str|None = None,
                 thinking_effort:ThinkingEffort = None,
                 text_format:ValidOutputFormat|None = None,
                 max_output_tokens:int|None = None,
                 ) -> None:

        self.name = input_path.stem
        self.has_valid_output = False
        self.is_cleaned_up = False

        self.input_path = input_path

        self.user_requests = []

        self.model = model if model is not None else "kimi-k2.6"
        self.instructions = instructions if instructions is not None else "You are a helpful assistant"
        self.thinking_effort = thinking_effort
        self.output_format = self.validate_output_format(text_format)
        self.max_output_tokens = max_output_tokens if max_output_tokens is not None else 5000

        self.batch_client = AsyncKimiBatchClient(api_key=api_key)
        self.batches = []
        self.batch_input_file = KimiBatchInputFile(path=self.input_path,input_file_id="")
        self.batch_input_files = []

        self.retries = []
        self.contents = []
        self.records = []

        self.final_usage: dict[str, NormalizedUsage] = {}
        self.total_usage: dict[str, NormalizedUsage] = {}

        self._total_usage_items: list[NormalizedUsage] = []
        self._final_usage_by_id: dict[str, NormalizedUsage] = {}


    @classmethod
    def load_from_task_config(cls,api_key:str|None,input_path:Path|str|None,task_config:TaskConfig) -> "AsyncKimiBatchTask":
        if not api_key:
            raise ValueError("KimiBatchTask expects a valid API key.")
        if not input_path:
            raise ValueError("KimiBatchTask expects a valid input path.")

        return cls(
            api_key=api_key,
            input_path=Path(input_path),
            model = task_config.model.model_name,
            instructions=task_config.system,
            thinking_effort=task_config.model.thinking_effort,
            text_format=task_config.output_format,
            max_output_tokens=task_config.model.max_tokens
        )

    async def run(self):
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

    async def _run_attempt(
            self, requests: list[UserRequest],
            *,
            batch_input_file: KimiBatchInputFile,
            max_output_tokens
    ) -> tuple[list[dict[str, Any]],list[dict[str, Any]],]:

        self._write_batch_input_file(
            requests,
            batch_input_file=batch_input_file,
            max_output_tokens=max_output_tokens,
        )

        batch = await self.batch_client.submit(batch_input_file)

        self.batches.append(batch)
        self.batch_input_files.append(batch_input_file)
        completed_batch = await self.run_with_retry_async(self.batch_client.wait_for_completion, batch.id)
        self.batches[-1] = completed_batch

        records = await self.run_with_retry_async(self.batch_client.collect_results, completed_batch)
        contents = self._collect_results(requests, records)

        return contents,records

    async def retry_batch(self, max_retries: int = 3) -> None:

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
                and item["incomplete_reason"].strip().lower() == "length"
                for item in self.contents
            )

            retry_max_tokens = self.max_output_tokens
            if increase_tokens:
                retry_max_tokens += 500 * attempt

            retry_input_file = KimiBatchInputFile(
                path=(
                        self.input_path.parent
                        / f"{self.name}_retry{attempt}.jsonl"
                ),
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

    def _update_usage_snapshots(self) -> None:
        self.total_usage = {
            self.model: sum_normalized_usage(self._total_usage_items)
        }
        self.final_usage = {
            self.model: sum_normalized_usage(
                list(self._final_usage_by_id.values())
            )
        }


    def add_user_inputs(self,user_requests:str | list[UserRequest]) -> None:
        """
        user_requests is a list of the user requests:
        {
            "custom_id": request_01，
            "user_input": You are a....
        }
        """
        exist_ids: set[str] = set()

        if isinstance(user_requests, str):
            raise TypeError("KimiBatchTask expects a list of UserRequest.")

        for user_request in user_requests:
            if len(user_request.custom_id.strip()) == 0 or len(user_request.user_input.strip()) == 0:
                raise ValueError("Custom id and user input can not be empty.")

            if user_request.custom_id in exist_ids:
                raise ValueError(f"Duplicate custom_id: {user_request.custom_id}")

            exist_ids.add(user_request.custom_id)

        self.user_requests = list(user_requests)

    def _collect_results(self,requests:list[UserRequest],records:list[dict[str,Any]]) -> list[dict[str, Any]]:

        records_map = {
            record.get("custom_id"): record
            for record in records
            if record.get("custom_id")
        }

        contents = []

        for request in requests:
            record = records_map.get(request.custom_id,{}) or {}
            custom_id = record.get("custom_id", "") or ""
            batch_error = record.get("error",{}) or {}

            if not custom_id:
                content = self._build_incomplete_content(request.custom_id,"incomplete_response")
                contents.append(content)
                continue

            if batch_error:
                content = self._build_incomplete_content(request.custom_id,self._get_error(batch_error))
                contents.append(content)
                continue

            response = record.get("response", {}) or {}
            body = response.get("body", {}) or {}
            body_error = body.get("error",{}) or {}
            if body_error:
                content = self._build_incomplete_content(request.custom_id,self._get_error(body_error))
                contents.append(content)
                continue

            choices = body.get("choices", []) or []
            usage = self._normalize_usage(body.get("usage", {}) or {})
            self._total_usage_items.append(usage)
            self._final_usage_by_id[request.custom_id] = usage

            if len(choices) == 0:
                content = self._build_incomplete_content(request.custom_id,"incomplete_response")
                contents.append(content)
                continue

            text_fragments: list[str] = []
            content_invalid = False

            for choice in choices:
                finish_reason = choice.get("finish_reason", "") or ""
                if finish_reason and finish_reason.strip().lower() != "stop":
                    content = self._build_incomplete_content(request.custom_id,finish_reason)
                    contents.append(content)
                    content_invalid = True
                    break

                message = choice.get("message", {}) or {}
                message_content = message.get("content", "") or ""

                if not message_content:
                    content = self._build_incomplete_content(request.custom_id,"incomplete_content")
                    contents.append(content)
                    content_invalid = True
                    break

                text_fragments.append(message_content)

            if content_invalid:
                continue

            raw_text = "".join(text_fragments)
            try:
                contents.append(
                    {
                        "custom_id": custom_id,
                        "content": parse_output_text(raw_text,self.output_format),
                        "completed": True,
                        "incomplete_reason": "",
                    }
                )
            except ValidationError as error:
                content = self._build_incomplete_content(custom_id,"output_parsing_failed")
                contents.append(content)

        return contents

    @staticmethod
    def _build_incomplete_content(custom_id:str,reason:str) -> dict[str,Any]:
        return {
            "custom_id": custom_id,
            "content": "",
            "completed": False,
            "incomplete_reason": reason,
        }

    @staticmethod
    def _get_error(error:dict[str,Any]) -> str:
        err_msg = error.get("type","") or ""
        if not err_msg:
            err_msg = error.get("code","Unknown error") or "Unknown error"

        return err_msg

    def _write_batch_input_file(self,requests:list[UserRequest],*,batch_input_file:KimiBatchInputFile,max_output_tokens) -> None:
        batch_input_file.reset_JSONLs()
        batch_input_file.add_multiple_JSONLs(
            model=self.model,
            custom_ids=[request.custom_id for request in requests],
            instructions=self.instructions,
            users=[request.user_input for request in requests],
            thinking_effort = self.thinking_effort,
            output_format=self.output_format,
            max_output_tokens=max_output_tokens,
        )
        batch_input_file.write_to_file()

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
                    f"Failed to clean up Kimi batch "f"{batch.id} and {batch_input_file.input_file_id}:\n {error}",
                    RuntimeWarning,
                )

        self.is_cleaned_up = all(cleanup_results)

    def reset(self):
        self.batch_input_file.reset_JSONLs()
        self.contents = []
        self.records = []
        self.retries = []
        self.batches = []
        self.batch_input_files = []
        self.has_valid_output = False
        self.is_cleaned_up = False
        self.total_usage = {}
        self.final_usage = {}
        self._total_usage_items = []
        self._final_usage_by_id = {}

    @staticmethod
    def _normalize_usage(
            usage: dict[str, Any],
    ) -> NormalizedUsage:
        input_tokens = int(usage.get("prompt_tokens", 0) or 0)

        output_tokens = int(usage.get("completion_tokens", 0) or 0)

        cached_tokens = int(usage.get("cached_tokens", 0) or 0)

        total_tokens = input_tokens + output_tokens

        return NormalizedUsage(
            input_tokens=input_tokens,
            output_tokens=output_tokens,
            total_tokens=total_tokens,
            input_token_details={
                "cache_read": cached_tokens,
            },
            output_token_details={},
        )











