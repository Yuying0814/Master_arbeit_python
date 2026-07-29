from __future__ import annotations

import asyncio
import json
from typing import Any
from warnings import warn

from google import genai
from google.genai.types import BatchJob,UploadFileConfig

from src.llm.google.batch.input_file import GeminiBatchInputFile


TERMINAL_STATES = {
    "JOB_STATE_SUCCEEDED",
    "JOB_STATE_FAILED",
    "JOB_STATE_CANCELLED",
    "JOB_STATE_EXPIRED",
}

ACTIVE_STATES = {
    "JOB_STATE_PENDING",
    "JOB_STATE_RUNNING",
}


class AsyncGeminiBatchClient:

    def __init__(self, api_key: str) -> None:
        self.client = genai.Client(api_key=api_key)
        self.async_client = self.client.aio

    async def upload(self,batch_input_file: GeminiBatchInputFile):
        uploaded_file = await self.async_client.files.upload(
            file=str(batch_input_file.path),
            config=UploadFileConfig(
                display_name=f"{batch_input_file.path.stem}_upload",
                mime_type="jsonl",
            ),
        )

        if not uploaded_file.name:
            raise RuntimeError("Gemini did not return an uploaded file name.")

        batch_input_file.remote_file_name = uploaded_file.name
        return uploaded_file

    async def submit(self,batch_input_file: GeminiBatchInputFile,model: str,) -> BatchJob:
        uploaded_file = await self.upload(batch_input_file)

        try:
            batch_job = await self.async_client.batches.create(
                model=model,
                src=uploaded_file.name,
                config={"display_name": f"{batch_input_file.path.stem}_create"},
            )
        except Exception:
            await self.delete(uploaded_file.name)
            raise

        if not batch_job.name:
            await self.delete(uploaded_file.name)
            raise RuntimeError("Gemini did not return a batch job name.")

        return batch_job

    async def retrieve(self, batch_name: str) -> BatchJob:
        return await self.async_client.batches.get(name=batch_name)

    async def wait_for_completion(
        self,batch_name: str,
        *,
        check_interval: float = 10.0,
        max_failures: int = 6,
    ) -> BatchJob:
        failed_count = 0

        while True:
            try:
                batch_job = await self.retrieve(batch_name)
                failed_count = 0
            except Exception as error:
                failed_count += 1
                if failed_count > max_failures:
                    raise RuntimeError(
                        f"Failed to retrieve Gemini batch {batch_name}."
                    ) from error

                await asyncio.sleep(check_interval)
                continue

            if self.get_state_name(batch_job) in TERMINAL_STATES:
                return batch_job

            await asyncio.sleep(check_interval)

    async def collect_results(
        self,
        batch_job: BatchJob,
    ) -> list[dict[str, Any]]:

        state = self.get_state_name(batch_job)

        if state != "JOB_STATE_SUCCEEDED":
            error = getattr(batch_job,"error",None)
            if error is not None:
                error_msg = error.model_dump(mode="json")
            else:
                error_msg = ""

            raise ValueError(
                f"Gemini batch {batch_job.name} ended with {state}: {error_msg}"
            )

        output_file_name = getattr(batch_job.dest, "file_name", None)

        if not output_file_name:
            raise RuntimeError(
                f"Gemini batch {batch_job.name} has no result file."
            )

        raw_output = await self.async_client.files.download(
            file=output_file_name,
        )
        return self.parse_raw_output(raw_output)

    @staticmethod
    def parse_raw_output(raw_output: bytes) -> list[dict[str, Any]]:

        text = raw_output.decode("utf-8")

        records: list[dict[str, Any]] = []

        for line_number, line in enumerate(text.splitlines(), start=1):
            if not line.strip():
                continue
            try:
                record = json.loads(line)
            except json.JSONDecodeError as error:
                raise ValueError(
                    f"Invalid Gemini result JSONL at line {line_number}."
                ) from error

            records.append(record)

        return records

    async def clean_up_batch_job(
        self,
        batch_job: BatchJob,
        batch_input_file: GeminiBatchInputFile,
    ) -> None:


        if self.get_state_name(batch_job) in ACTIVE_STATES:
            try:
                await self.async_client.batches.cancel(name=batch_job.name)

            except Exception as error:
                warn(f"Failed to clean up Gemini batch {batch_job.name}: {error}")

        current_job = await self.wait_for_completion(batch_job.name)

        output_file_name = getattr(current_job.dest, "file_name", None)
        file_names = [
            output_file_name,
            batch_input_file.remote_file_name,
        ]

        for file_name in dict.fromkeys(name for name in file_names if name):
            await self.delete(file_name)

    async def delete(self, file_name: str) -> None:
        try:
            await self.async_client.files.delete(name=file_name)
        except Exception as error:
            warn(f"Failed to delete file {file_name}:\n{error}")

    @staticmethod
    def get_state_name(batch_job: BatchJob) -> str:
        state = batch_job.state
        if state is None:
            return "JOB_STATE_UNSPECIFIED"
        return getattr(state, "name", str(state))



