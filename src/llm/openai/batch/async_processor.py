from __future__ import annotations
import warnings

from pathlib import Path
from typing import Any,TypeVar

from src.models.task_config import TaskConfig
from src.models.batch import UserRequest
from src.llm.common.common import ValidOutputFormat,HasRunWithRetry
from src.llm.openai.batch.async_client import AsyncOpenAIBatchClient
from src.llm.openai.batch.batch_job import BatchJob
from src.llm.openai.batch.input_file import BatchInputFile

T = TypeVar("T")

class OpenAIBatchTaskProcessor(HasRunWithRetry):
    name:str
    status:str
    has_valid_output:bool
    is_cleaned_up:bool

    input_path:Path

    custom_ids:list[str]
    user_inputs: list[str]

    model:str
    instructions:str
    text_format:ValidOutputFormat
    max_output_tokens:int

    batch_client:AsyncOpenAIBatchClient
    batch_job:BatchJob|None
    batch_input_file:BatchInputFile
    retries:list[dict[str,Any]]
    contents:list[dict[str,Any]]
    outputs:list[dict[str,Any]]
    records:list[dict[str,Any]]

    total_usage:dict[str,Any]
    final_usage:dict[str,Any]


    def __init__(self,
                 api_key:str,
                 input_path:Path,
                 *,model:str|None = None,
                 instructions: str|None = None,
                 text_format:ValidOutputFormat|None = None,
                 max_output_tokens:int|None = None,
                 ) -> None:

        self.name = input_path.stem
        self.status = "created"
        self.has_valid_output = False
        self.is_cleaned_up = False

        self.input_path = input_path

        self.custom_ids = []
        self.user_inputs = []

        self.model = model if model is not None else "gpt-5-mini"
        self.instructions = instructions if instructions is not None else "You are a helpful assistance"
        self.text_format = text_format if text_format is not None else "text"
        self.max_output_tokens = max_output_tokens if max_output_tokens is not None else 500

        self.batch_client = AsyncOpenAIBatchClient(api_key=api_key)
        self.batch_job = None
        self.batch_input_file = BatchInputFile(path=self.input_path)
        self.retries = []
        self.contents = []
        self.outputs = []
        self.records = []

        self.final_usage = {}
        self.total_usage = {}

    @classmethod
    def load_from_task_config(cls,api_key:str|None,input_path:Path|str|None,task_config:TaskConfig):
        if not api_key:
            raise ValueError("OpenAIBatchTaskProcessor expects a valid API key.")
        if not input_path:
            raise ValueError("OpenAIBatchTaskProcessor expects a valid input path.")

        return cls(
            api_key=api_key,
            input_path=Path(input_path),
            model = task_config.model.model_name,
            instructions=task_config.system,
            text_format=task_config.output_format,
            max_output_tokens=task_config.model.max_tokens
        )

    async def run(self):
        self.reset()
        try:
            await self.run_with_retry_async(function=self.submit_batch)
            await self.run_with_retry_async(function=self.wait_batch)
            await self.run_with_retry_async(function=self.collect_batch_output)
            await self.retry_batch()
            self._get_total_usage()
            self._get_final_usage()
            return self.contents
        finally:
            await self.cleanup()

    def add_user_inputs(self,user_requests:str | list[UserRequest]) -> None:
        """
        user_requests is a list of the user requests:
        {
            "custom_id": request_01，
            "user_input": You are a....
        }
        """
        if isinstance(user_requests, str):
            raise TypeError("OpenAIBatchTaskProcessor expects a list of UserRequest.")

        custom_ids = []
        user_inputs = []

        for user_request in user_requests:
            if len(user_request.custom_id.strip()) == 0 or len(user_request.user_input.strip()) == 0:
                raise ValueError("Custom id and user input can not be empty.")

            custom_ids.append(user_request.custom_id)
            user_inputs.append(user_request.user_input)

        self.custom_ids = custom_ids
        self.user_inputs = user_inputs

    def write_batch_input_file(self) -> None:
        self.batch_input_file.reset_JSONLs()
        self.batch_input_file.add_multiple_JSONLs(
            name = self.name,
            model=self.model,
            custom_ids=self.custom_ids,
            instructions=self.instructions,
            users=self.user_inputs,
            text_format=self.text_format,
            max_output_tokens=self.max_output_tokens,
        )
        self.batch_input_file.write_to_file()

    async def submit_batch(self) -> None:

        if not self._has_user_request():
            raise ValueError("User requests must be added before submitting the batch task.")

        self.write_batch_input_file()
        self.batch_job = await self.batch_client.submit(batch_input_file=self.batch_input_file)
        self.update_status()

    async def wait_batch(self) -> None:
        if not self.batch_job:
            raise ValueError
        self.batch_job = await self.batch_client.wait_for_completion(batch_job=self.batch_job)
        self.update_status()

    async def collect_batch_output(self) -> None:
        if not self.batch_job:
            raise ValueError
        self.update_status()
        self.contents,self.outputs,self.records = await self.batch_client.collect_batch_output(self.batch_job)
        self.check_completeness()

    def check_completeness(self) -> list[str]:
        if not self.contents:
            self.has_valid_output = False
            return self.custom_ids

        existing_ids = {content["custom_id"] for content in self.contents}
        not_completed_id = {content["custom_id"] for content in self.contents if not content["completed"]}
        retry_custom_ids = not_completed_id | (set(self.custom_ids) - existing_ids)
        self.has_valid_output = not retry_custom_ids and (len(self.custom_ids)== len(self.contents))
        return list(retry_custom_ids)

    async def retry_batch(self,max_retries:int = 3) -> None:
        for attempt in range(1,max_retries+1):
            contents = self.contents

            retry_custom_ids = self.check_completeness()
            retry_contents = []
            retry_outputs = []
            retry_records = []
            retry_job = None

            if self.has_valid_output:
                return

            input_id_map = {
                custom_id:user_input
                    for custom_id,user_input in zip(self.custom_ids,self.user_inputs)
            }
            retry_user_inputs = [input_id_map[retry_custom_id] for retry_custom_id in retry_custom_ids]

            if contents and any(content.get("incomplete_reason") == "max_output_tokens" for content in contents):
                self.max_output_tokens += 500*attempt

            input_path = self.input_path.parent / f"{self.name}_retry{attempt}.jsonl"
            retry_batch_input_file = BatchInputFile(path=input_path)
            retry_batch_input_file.add_multiple_JSONLs(
                name = self.name,
                model=self.model,
                custom_ids=retry_custom_ids,
                instructions=self.instructions,
                users=retry_user_inputs,
                text_format=self.text_format,
                max_output_tokens=self.max_output_tokens,
            )
            retry_batch_input_file.write_to_file()

            try:
                retry_job = await self.run_with_retry_async(self.batch_client.submit, retry_batch_input_file)
                retry_job = await self.run_with_retry_async(self.batch_client.wait_for_completion,retry_job)
                retry_contents,retry_outputs,retry_records = await self.run_with_retry_async(
                    self.batch_client.collect_batch_output,
                    retry_job
                )

                update_retry_result(self.contents,retry_contents)
                update_retry_result(self.outputs,retry_outputs)
                update_retry_result(self.records,retry_records)

            except Exception:
                if retry_job:
                    await self.batch_client.cancel_batch_job(retry_job)
            finally:
                if retry_job:
                    await self.batch_client.clean_up_batch_job(retry_job)

                self.retries.append(
                    {
                        "retry_custom_ids": retry_custom_ids,
                        "retry_job": retry_job,
                        "retry_contents": retry_contents,
                        "retry_outputs": retry_outputs,
                        "retry_records": retry_records,
                    }
                )
        self.check_completeness()

    async def cleanup(self) -> None:
        '''try to cancel the batch(only when status is "validating" "submitted" "in progress" "") and delete uploaded file'''
        if self.is_cleaned_up:
            return

        if not self.batch_job:
            self.is_cleaned_up = True
            return
        try:
            await self.batch_client.cancel_batch_job(self.batch_job)
            await self.batch_client.clean_up_batch_job(self.batch_job)
            self.is_cleaned_up = True
        except RuntimeError:
            warnings.warn("Cleanup failed", RuntimeWarning)

    def reset(self):
        self.status = "created"
        self.has_valid_output = False
        self.is_cleaned_up = False
        self.batch_job = None
        self.contents = []
        self.outputs = []
        self.records = []
        self.final_usage = {}
        self.total_usage = {}

    def update_status(self) -> None:
        if not self.batch_job:
            self.status = "created"
            return
        self.status = self.batch_job.status

    def _has_user_request(self):
        return len(self.custom_ids) > 0 and len(self.user_inputs) > 0

    def _get_final_usage(self) -> dict:
        usages = []

        for record in self.records:
            usage = record.get("response",{}).get("body",{}).get("usage",{})

            if usage:
                usages.append(usage)

        self.final_usage = {
            self.model: _sum_token_usage(usages)
        }

    def _get_total_usage(self):
        usages = []
        usages.append(self.batch_job.batch_info.get("usage",{}))

        for retry in self.retries:
            usage = retry["retry_job"].batch_info.get("usage",{})
            usages.append(usage)

        self.total_usage = {
            self.model: _sum_token_usage(usages)
        }





# Helper
def update_retry_result(old_items:list[dict[str,Any]],new_items:list[dict[str,Any]]) -> None:
    result_index_map = {
        old_item["custom_id"]: index
        for index, old_item in enumerate(old_items)
    }

    for new_item in new_items:
        custom_id = new_item["custom_id"]
        if custom_id in result_index_map:
            index = result_index_map[custom_id]
            old_items[index] = new_item
        else:
            old_items.append(new_item)

def _sum_token_usage(usages: list[dict[str, Any]]) -> dict[str, Any]:
    total_usage = {
        "input_tokens": 0,
        "output_tokens": 0,
        "total_tokens": 0,
        "input_tokens_details": {
            "cached_tokens": 0,
        },
        "output_tokens_details": {
            "reasoning_tokens": 0,
        },
    }

    for usage in usages:
        if not usage:
            continue

        input_tokens = usage.get("input_tokens", 0)
        output_tokens = usage.get("output_tokens", 0)
        total_tokens = usage.get("total_tokens", input_tokens + output_tokens)

        cached_tokens = (
            usage
            .get("input_tokens_details", {})
            .get("cached_tokens", 0)
        )

        reasoning_tokens = (
            usage
            .get("output_tokens_details", {})
            .get("reasoning_tokens", 0)
        )

        total_usage["input_tokens"] += input_tokens
        total_usage["output_tokens"] += output_tokens
        total_usage["total_tokens"] += total_tokens
        total_usage["input_tokens_details"]["cached_tokens"] += cached_tokens
        total_usage["output_tokens_details"]["reasoning_tokens"] += reasoning_tokens

    return total_usage













