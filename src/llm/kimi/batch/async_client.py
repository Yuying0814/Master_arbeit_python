from __future__ import annotations

import json
import warnings
import asyncio
from pathlib import Path
from typing import Any

from openai import AsyncOpenAI
from openai.types import Batch,FileObject

from src.llm.kimi.batch.input_file import KimiBatchInputFile

TERMINAL_STATES = ["completed","failed","expired","cancelled"]
ACTIVE_STATES = ["validating","in_progress","finalizing"]

class AsyncKimiBatchClient:
    kimi_client: AsyncOpenAI

    def __init__(self, api_key: str) -> None:
        self.kimi_client = AsyncOpenAI(
            api_key=api_key,
            base_url="https://api.moonshot.ai/v1",
        )

    async def submit(self, batch_input_file: KimiBatchInputFile) -> Batch:
        batch_input = batch_input_file.path

        try:
            uploaded_file = await self._upload(batch_input)
        except Exception as error:
            raise RuntimeError(f"Failed to upload input file: {batch_input}") from error

        batch_input_file.input_file_id = uploaded_file.id

        try:
            batch = await self._create_batch(uploaded_file.id)
        except Exception as error:
            await self.delete_file(uploaded_file.id)
            raise RuntimeError(f"Failed to create batch : {batch_input}") from error

        return batch

    async def _upload(self, batch_input: Path) -> FileObject:
        with batch_input.open("rb") as file:
            batch_input_file = await self.kimi_client.files.create(
                file=file,
                purpose="batch",
            )
            return batch_input_file

    async def _create_batch(self, file_id: str) -> Batch:
        batch = await self.kimi_client.batches.create(
            input_file_id=file_id,
            endpoint="/v1/chat/completions",
            completion_window="24h",
        )

        return batch

    async def delete_file(self,file_id:str) -> bool:
        try:
            await self.kimi_client.files.delete(file_id=file_id)
            return True
        except Exception as error:
            warnings.warn(f"Failed to delete uploaded file: {file_id}\n{error}")
            return False

    async def wait_for_completion(
        self,
        batch_id: str,
        check_interval: float = 10.0,
        max_failures: int = 6,
    ) -> Batch:

        failed_count = 0

        while True:
            try:
                batch = await self._retrieve(batch_id)
                completed: int = batch.request_counts.completed if batch.request_counts else 0
                total: int = batch.request_counts.total if batch.request_counts else 0
                print(f"Status: {batch.status} ({completed}/{total})")

                failed_count = 0
            except Exception as error:
                failed_count += 1
                if failed_count >= max_failures:
                    raise RuntimeError(
                        f"Failed to retrieve Kimi batch {batch_id}."
                    ) from error

                await asyncio.sleep(check_interval)
                continue

            if batch.status in TERMINAL_STATES:
                return batch
            await asyncio.sleep(check_interval)

    async def _retrieve(self, batch_id:str) -> Batch:
        batch = await self.kimi_client.batches.retrieve(batch_id)
        return batch

    async def collect_results(self, batch:Batch) -> list[dict[str,Any]]:
        if batch.status != "completed":
            raise RuntimeError(
                f"Cannot collect results from batch with status={batch.status}"
            )

        if not batch.output_file_id and not batch.error_file_id:
            raise RuntimeError(
                f"Completed batch {batch.id} has no result file."
            )

        output_records = await self._parse_file(batch.output_file_id)
        error_records = await self._parse_file(batch.error_file_id)

        records = output_records + error_records

        return records

    async def _parse_file(self,file_id:str|None) -> list[dict[str, Any]]:
        if not file_id:
            return []
        file_content = await self.kimi_client.files.content(file_id)

        records = []
        for line_number,line in enumerate(file_content.text.splitlines(),start=1):

            if not line.strip():
                continue

            try:
                record = json.loads(line)
            except json.JSONDecodeError:
                warnings.warn(f"Skip invalid JSONL record at line {line_number}")
                continue

            records.append(record)
        return records

    async def cancel(self, batch: Batch) -> Batch:
        if batch.status in TERMINAL_STATES:
            return batch

        if batch.status != "cancelling":
            await self.kimi_client.batches.cancel(batch_id=batch.id)

        return await self.wait_for_completion(batch.id)
