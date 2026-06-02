from __future__ import annotations

import json
import warnings
import time
from pathlib import Path
from typing import Any
from openai import OpenAI
from src.openai.batch_job import BatchJob
from src.openai.batch_input_file import BatchInputFile


class OpenAIBatchClient:
    openai_client:OpenAI

    def __init__(self, api_key:str) -> None:
        self.openai_client = OpenAI(api_key=api_key)

    def batch_run(self,batch_input_file:BatchInputFile) -> tuple[list[dict[str, Any]], list[dict[str, Any]], list[dict[str, Any]]]:

        batch_job = self.submit(batch_input_file)
        batch_job = self.wait_for_completion(batch_job)
        contents,outputs,records = self.collect_batch_output(batch_job)
        return contents,outputs,records


    def upload(self,batch_input:Path) -> str:
        try:
            with batch_input.open("rb") as file:
                batch_input_file = self.openai_client.files.create(
                    file=file,
                    purpose="batch"
                )
                return batch_input_file.id
        except Exception as error:
            raise RuntimeError(f"Failed to upload batch input file: {batch_input}") from error

    def get_batch_id(self,input_file_id:str) -> str:
        try:
            batch = self.openai_client.batches.create(
                input_file_id=input_file_id,
                endpoint="/v1/responses",
                completion_window="24h",
            )
            return batch.id
        except Exception as error:
            raise RuntimeError(f"Failed to get batch id: {input_file_id}") from error

    def get_batch_info(self,batch_id:str) -> dict:
        try:
            batch = self.openai_client.batches.retrieve(batch_id=batch_id)
            return batch.model_dump()
        except Exception as error:
            raise RuntimeError(f"Failed to get batch info: {batch_id}") from error

    def get_batch_output(self,output_file_id:str) -> str:
        try:
            file_response = self.openai_client.files.content(file_id=output_file_id)
            return file_response.text
        except Exception as error:
            raise RuntimeError(f"Failed to get batch output: {output_file_id}") from error

    def parse_batch_output(self,raw_output: str,) -> tuple[list[dict[str, Any]], list[dict[str, Any]], list[dict[str, Any]]]:
        records: list[dict[str, Any]] = []
        outputs: list[dict[str, Any]] = []
        contents: list[dict[str, Any]] = []

        for line in raw_output.splitlines():
            if not line.strip():
                continue

            try:
                record = json.loads(line)
            except json.JSONDecodeError:
                continue

            records.append(record)

            custom_id = record.get("custom_id", "") or ""
            response = record.get("response", {}) or {}
            response_body = response.get("body", {}) or {}

            status = response_body.get("status", "") or ""
            output_items = response_body.get("output", []) or []
            error = record.get("error")

            is_completed = (
                    status == "completed"
                    and bool(output_items)
                    and bool(custom_id)
                    and error is None
            )

            if not is_completed:
                incomplete_details = response_body.get("incomplete_details", {}) or {}
                incomplete_reason = incomplete_details.get("reason", "") or ""

                outputs.append(
                    {
                        "custom_id": custom_id,
                        "output": [],
                        "completed": False,
                        "incomplete_reason": incomplete_reason,
                    }
                )
                contents.append(
                    {
                        "custom_id": custom_id,
                        "content": "",
                        "completed": False,
                        "incomplete_reason": incomplete_reason,
                    }
                )
                continue

            text_fragments: list[str] = []

            for item in output_items:
                item_type = item.get("type", "") or ""
                item_content = item.get("content", []) or []
                if item_type != "message":
                    continue

                for content in item_content:
                    if content.get("type", "") == "output_text":
                        text_fragments.append(content.get("text", "") or "")
            outputs.append(
                {
                    "custom_id": custom_id,
                    "output": output_items,
                    "completed": True,
                    "incomplete_reason": "",
                }
            )
            raw_content = "\n".join(text_fragments)
            try:
                content = json.loads(raw_content)
            except json.JSONDecodeError:
                content = raw_content

            contents.append(
                {
                    "custom_id": custom_id,
                    "content": content,
                    "completed": True,
                    "incomplete_reason": "",
                }
            )
        return contents, outputs, records

    def delete_uploaded_file(self,input_file_id:str) -> None:
        try:
            self.openai_client.files.delete(file_id=input_file_id)
        except Exception as error:
            warnings.warn(f"Failed to delete uploaded file: {input_file_id}\n{error}")

    def cancel(self,batch_id:str) -> None:
        try:
            self.openai_client.batches.cancel(batch_id=batch_id)
        except Exception as error:
            warnings.warn(f"Failed to cancel batch: {batch_id}\n{error}")

    def submit(self,batch_input_file:BatchInputFile) -> BatchJob:
        batch_input = batch_input_file.path
        name = batch_input.stem

        try:
            input_file_id = self.upload(batch_input)
            batch_job = BatchJob(name=name, input_path=batch_input)
            batch_job.update(input_file_id=input_file_id,status="uploaded")
        except Exception as error:
            raise RuntimeError(f"Failed to submit batch: {batch_input}") from error

        try:
            batch_id = self.get_batch_id(input_file_id)
            batch_job.update(batch_id=batch_id,status="submitted")
        except Exception as error:
            self.delete_uploaded_file(input_file_id)
            raise RuntimeError(f"Failed to submit batch: {batch_input}") from error
        return batch_job

    def wait_for_completion(self,batch_job: BatchJob,check_interval: int = 10,max_retries: int = 6) -> BatchJob:
        failed_count = 0
        try:
            while True:
                try:
                    batch_info = self.get_batch_info(batch_job.batch_id)
                    batch_job.update(batch_info=batch_info)
                    print(f"Name: {batch_job.name}\nStatus: {batch_job.status}")
                    failed_count = 0

                except Exception as error:
                    failed_count += 1
                    if failed_count > max_retries:
                        raise RuntimeError(f"Failed to retrieve batch status after {max_retries} retries.") from error

                if batch_job.is_terminal():
                    break

                time.sleep(check_interval)

            if not batch_job.is_completed():
                raise RuntimeError(
                    f"Batch job ended with status: {batch_job.status}"
                )

            return batch_job

        except Exception:
            try:
                if not batch_job.is_terminal():
                    self.cancel(batch_job.batch_id)
            except Exception as cancel_error:
                warnings.warn(f"failed to cancel batch job: {cancel_error}")

            try:
                self.delete_uploaded_file(batch_job.input_file_id)
            except Exception as delete_error:
                warnings.warn(f"Warning: failed to delete input file: {delete_error}")
            raise

    def collect_batch_output(self,batch_job:BatchJob) -> tuple[list[dict[str, Any]], list[dict[str, Any]], list[dict[str, Any]]]:
        if not batch_job.is_completed():
            raise RuntimeError(f"Batch job is not completed,ended with status: {batch_job.status}")

        if not batch_job.has_output():
            raise RuntimeError(f"Batch job has no output file id")

        output_file_id = batch_job.output_file_id
        raw_output = self.get_batch_output(output_file_id)
        contents,outputs,records = self.parse_batch_output(raw_output)
        return contents,outputs,records

    def clean_up_batch_job(self,batch_job:BatchJob) -> None:
        if batch_job.input_file_id:
            self.delete_uploaded_file(input_file_id=batch_job.input_file_id)

    def cancel_batch_job(self,batch_job:BatchJob) -> None:
        batch_job.update_batch_info(batch_info=self.get_batch_info(batch_job.batch_id))
        if batch_job.status in {"validating","submitted","in_progress"}:
            self.cancel(batch_id=batch_job.batch_id)










