from __future__ import annotations
import warnings

from pathlib import Path
from typing import Any,TypeVar

from src.models.task_config import TaskConfig
from src.models.batch import UserRequest
from src.llm.common.common import ValidOutputFormat,HasRunWithRetry
from src.llm.openai.batch.client import OpenAIBatchClient
from src.llm.openai.batch.batch_job import BatchJob
from src.llm.openai.batch.input_file import OpenaiBatchInputFile

T = TypeVar("T")

class OpenAIBatchTaskProcessor(HasRunWithRetry):
    name:str
    status:str
    has_valid_output:bool

    input_path:Path

    custom_ids:list[str]
    user_inputs: list[str]

    model:str
    instructions:str
    text_format:ValidOutputFormat
    max_output_tokens:int

    batch_client:OpenAIBatchClient
    batch_job:BatchJob|None
    batch_input_file:OpenaiBatchInputFile
    retries:list[dict[str,Any]]
    contents:list[dict[str,Any]]
    outputs:list[dict[str,Any]]
    records:list[dict[str,Any]]

    def __init__(self,
                 api_key:str,
                 input_path:Path,
                 *,model:str|None = None,
                 instructions: str|None = None,
                 text_format:ValidOutputFormat,
                 max_output_tokens:int|None = None,
                 ) -> None:

        self.name = input_path.stem
        self.status = "created"
        self.has_valid_output = False

        self.input_path = input_path

        self.custom_ids = []
        self.user_inputs = []

        self.model = model if model is not None else "gpt-5-mini"
        self.instructions = instructions if instructions is not None else "You are a helpful assistance"
        self.text_format = text_format
        self.max_output_tokens = max_output_tokens if max_output_tokens is not None else 500

        self.batch_client = OpenAIBatchClient(api_key=api_key)
        self.batch_job = None
        self.batch_input_file = OpenaiBatchInputFile(path=self.input_path)
        self.retries = []
        self.contents = []
        self.outputs = []
        self.records = []

    @classmethod
    def load_from_task_config(cls,api_key:str,input_path:Path|str,task_config:TaskConfig):
        return cls(
            api_key=api_key,
            input_path=Path(input_path),
            model = task_config.model.model_name,
            instructions=task_config.system,
            text_format=task_config.output_format,
            max_output_tokens=task_config.model.max_tokens
        )

    def run_batch(self):
        self.reset()
        try:
            self.run_with_retry(function=self.submit_batch)
            self.run_with_retry(function=self.wait_batch)
            self.run_with_retry(function=self.collect_batch_output)
            self.retry_batch()
        finally:
            self.cleanup()

    def build_user_requests(self) -> list[UserRequest]:
        raise NotImplementedError("Subclasses must implement build_user_requests().")

    def add_user_requests(self,user_requests:list[UserRequest]) -> None:
        """
        user_requests is a list of the user requests:
        {
            "custom_id": request_01，
            "user_input": You are a....
        }
        """

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
            model=self.model,
            custom_ids=self.custom_ids,
            instructions=self.instructions,
            users=self.user_inputs,
            text_format=self.text_format,
            max_output_tokens=self.max_output_tokens,
        )
        self.batch_input_file.write_to_file()

    def submit_batch(self) -> None:
        if not self.custom_ids or not self.user_inputs:
            self.build_user_requests()

        if not self.custom_ids or not self.user_inputs:
            raise ValueError("User requests must be added before submitting the batch task.")

        self.write_batch_input_file()
        self.batch_job = self.batch_client.submit(batch_input_file=self.batch_input_file)
        self.update_status()

    def wait_batch(self) -> None:
        if not self.batch_job:
            raise ValueError
        self.batch_job = self.batch_client.wait_for_completion(batch_job=self.batch_job)
        self.update_status()

    def collect_batch_output(self) -> None:
        if not self.batch_job:
            raise ValueError
        self.update_status()
        self.contents,self.outputs,self.records = self.batch_client.collect_batch_output(self.batch_job)
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

    def retry_batch(self,max_retries:int = 3) -> None:
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
            retry_batch_input_file = OpenaiBatchInputFile(path=input_path)
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
                retry_job = self.run_with_retry(self.batch_client.submit, retry_batch_input_file)
                retry_job = self.run_with_retry(self.batch_client.wait_for_completion,retry_job)
                retry_contents,retry_outputs,retry_records = self.run_with_retry(
                    self.batch_client.collect_batch_output,
                    retry_job
                )

                update_retry_result(self.contents,retry_contents)
                update_retry_result(self.outputs,retry_outputs)
                update_retry_result(self.records,retry_records)

            except RuntimeError:
                if retry_job:
                    self.batch_client.cancel_batch_job(retry_job)
            finally:
                if retry_job:
                    self.batch_client.clean_up_batch_job(retry_job)

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

    def cleanup(self) -> None:
        '''try to cancel the batch(only when status is "validating" "submitted" "in progress" "") and delete uploaded file'''
        if not self or not self.batch_job:
            return
        try:
            self.batch_client.cancel_batch_job(self.batch_job)
            self.batch_client.clean_up_batch_job(self.batch_job)
        except RuntimeError:
            warnings.warn("Cleanup failed", RuntimeWarning)

    def reset(self):
        self.status = "created"
        self.has_valid_output = False
        self.batch_job = None
        self.contents = []
        self.outputs = []
        self.records = []

    def update_status(self) -> None:
        if not self.batch_job:
            self.status = "created"
            return
        self.status = self.batch_job.status

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















