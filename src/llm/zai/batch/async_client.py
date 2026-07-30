from __future__ import annotations

import asyncio
import json
import warnings
from pathlib import Path
from typing import Any, cast

from zai import ZhipuAiClient
from zai.types.batch import Batch
from zai.types.files import FileObject

from src.llm.zai.batch.input_file import GlmBatchInputFile


BATCH_ENDPOINT = cast(Any, "/v4/chat/completions")

TERMINAL_STATES = {
    "completed",
    "failed",
    "expired",
    "cancelled",
}

ACTIVE_STATES = {
    "validating",
    "in_progress",
    "finalizing",
}


class AsyncGlmBatchClient:
    def __init__(self, api_key: str) -> None:
        self.glm_client = ZhipuAiClient(api_key=api_key)

    async def submit( self,batch_input_file: GlmBatchInputFile,) -> Batch:
        batch_input = batch_input_file.path

        try:
            uploaded_file = await self._upload(batch_input)
        except Exception as error:
            raise RuntimeError(
                f"Failed to upload GLM batch input file: "
                f"{batch_input}"
            ) from error

        batch_input_file.input_file_id = uploaded_file.id

        try:
            return await self._create_batch(uploaded_file.id)
        except Exception as error:
            await self.delete_file(uploaded_file.id)
            raise RuntimeError(
                f"Failed to create GLM batch for: {batch_input}"
            ) from error

    async def _upload(self, batch_input: Path) -> FileObject:
        return await asyncio.to_thread(
            self._upload_sync,
            batch_input,
        )

    def _upload_sync(self, batch_input: Path) -> FileObject:
        with batch_input.open("rb") as file:
            return self.glm_client.files.create(
                file=file,
                purpose="batch",
            )

    async def _create_batch(self, input_file_id: str) -> Batch:
        return await asyncio.to_thread(
            self.glm_client.batches.create,
            input_file_id=input_file_id,
            endpoint=BATCH_ENDPOINT,
            auto_delete_input_file=False,
        )

    async def retrieve(self, batch_id: str) -> Batch:
        return await asyncio.to_thread(
            self.glm_client.batches.retrieve,
            batch_id,
        )

    async def wait_for_completion(
        self,
        batch_id: str,
        *,
        check_interval: float = 10.0,
        max_failures: int = 6,
    ) -> Batch:

        failed_count = 0

        while True:
            try:
                batch = await self.retrieve(batch_id)
                failed_count = 0

                request_counts = batch.request_counts
                completed = request_counts.completed if request_counts is not None else 0
                total = request_counts.total if request_counts is not None else 0
                print(
                    f"GLM batch status: {batch.status} "
                    f"({completed}/{total})"
                )
            except Exception as error:
                failed_count += 1

                if failed_count >= max_failures:
                    raise RuntimeError(
                        f"Failed to retrieve GLM batch {batch_id}."
                    ) from error

                await asyncio.sleep(check_interval)
                continue

            if batch.status in TERMINAL_STATES:
                return batch

            await asyncio.sleep(check_interval)

    async def collect_results(self,batch: Batch,) -> list[dict[str, Any]]:
        output_records = await self._parse_file(
            batch.output_file_id
        )

        error_records = await self._parse_file(
            batch.error_file_id
        )
        return output_records + error_records

    async def _parse_file(self,file_id: str | None,) -> list[dict[str, Any]]:
        if not file_id:
            return []

        file_content = await asyncio.to_thread(
            self.glm_client.files.content,
            file_id,
        )

        try:
            raw_output = file_content.content
        finally:
            await asyncio.to_thread(file_content.close)

        text = raw_output.decode("utf-8")
        records: list[dict[str, Any]] = []

        for line_number, line in enumerate(text.splitlines(), start=1,):
            if not line.strip():
                continue

            try:
                record = json.loads(line)
            except json.JSONDecodeError:
                warnings.warn(f"Skip invalid GLM JSONL record at line "f"{line_number}",RuntimeWarning)
                continue

            records.append(record)

        return records

    async def cancel(self, batch: Batch) -> bool:
        if batch.status in TERMINAL_STATES:
            return True

        if batch.status == "cancelling":
            return True

        try:
            await asyncio.to_thread(
                self.glm_client.batches.cancel,
                batch.id,
            )
            return True
        except Exception as error:
            warnings.warn(f"Failed to cancel GLM batch {batch.id}: {error}",RuntimeWarning,)
            return False

    async def delete_file(self, file_id: str) -> bool:
        if not file_id:
            return True

        try:
            await asyncio.to_thread(
                self.glm_client.files.delete,
                file_id,
            )
            return True
        except Exception as error:
            warnings.warn(f"Failed to delete GLM file {file_id}: {error}",RuntimeWarning,)
            return False

    async def close(self) -> None:
        await asyncio.to_thread(self.glm_client.close)
