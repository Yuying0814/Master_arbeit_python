from __future__ import annotations

import asyncio
import json
from typing import Any

from google import genai
from google.genai.errors import APIError
from google.genai.types import BatchJob,UploadFileConfig

from src.llm.google.batch.input_file import GeminiBatchInputFile


TERMINAL_STATES = {
    "JOB_STATE_SUCCEEDED",
    "JOB_STATE_FAILED",
    "JOB_STATE_CANCELLED",
    "JOB_STATE_EXPIRED",
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
                config={
                    "display_name": f"{batch_input_file.path.stem}_create",
                },
            )
        except Exception as error:
            try:
                await self._delete_input_file(uploaded_file.name)
            except Exception as cleanup_error:
                error.add_note(
                    f"Failed to delete Gemini batch input file: {cleanup_error}"
                )
            raise

        if not batch_job.name:
            error = RuntimeError("Gemini did not return a batch job name.")

            try:
                await self._delete_input_file(uploaded_file.name)
            except Exception as cleanup_error:
                error.add_note(
                    f"Failed to delete Gemini batch input file: {cleanup_error}"
                )

            raise error

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
        failures: list[str] = []

        batch_name = batch_job.name
        if not batch_name:
            failures.append("Gemini batch job has no name.")
        else:
            try:
                await self._delete_batch_job(batch_name)
            except Exception as error:
                failures.append(
                    f"Failed to delete Gemini batch job {batch_name}: {error}"
                )

        input_file_name = batch_input_file.remote_file_name
        if input_file_name:
            try:
                await self._delete_input_file(input_file_name)
            except Exception as error:
                failures.append(
                    f"Failed to delete Gemini batch input file "
                    f"{input_file_name}: {error}"
                )

        if failures:
            raise RuntimeError(
                "Gemini batch cleanup failed:\n" + "\n".join(failures)
            )

    async def _delete_batch_job(self, batch_name: str) -> None:
        try:
            await self.async_client.batches.delete(name=batch_name)
        except APIError as error:
            if error.code != 404:
                raise

    async def _delete_input_file(self, file_name: str) -> None:
        try:
            await self.async_client.files.delete(name=file_name)
        except APIError as error:
            if error.code != 404:
                raise

    @staticmethod
    def get_state_name(batch_job: BatchJob) -> str:
        state = batch_job.state
        if state is None:
            return "JOB_STATE_UNSPECIFIED"
        return getattr(state, "name", str(state))



