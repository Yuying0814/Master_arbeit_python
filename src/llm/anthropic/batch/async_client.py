from __future__ import annotations

import asyncio
from typing import Any, Iterable

from anthropic import AsyncAnthropic
from anthropic.types.messages import MessageBatch, MessageBatchIndividualResponse


class AsyncClaudeBatchClient:
    def __init__(self, api_key: str) -> None:
        self.client = AsyncAnthropic(api_key=api_key)

    async def submit(self,requests: Iterable[dict[str, Any]],) -> MessageBatch:
        return await self.client.messages.batches.create(requests=requests)

    async def retrieve(self, batch_id: str) -> MessageBatch:
        return await self.client.messages.batches.retrieve(batch_id)

    async def wait_for_completion(
        self,
        batch_id: str,
        *,
        check_interval: float = 10.0,
        max_retries: int = 6,
    ) -> MessageBatch:

        failed_count = 0

        while True:
            try:
                batch = await self.retrieve(batch_id)
                failed_count = 0
            except Exception as error:
                failed_count += 1
                if failed_count > max_retries:
                    raise RuntimeError(
                        f"Failed to retrieve Claude batch {batch_id}."
                    ) from error
                await asyncio.sleep(check_interval)
                continue

            if batch.processing_status == "ended":
                return batch

            await asyncio.sleep(check_interval)

    async def collect_results(
        self,
        batch_id: str,
    ) -> list[MessageBatchIndividualResponse]:
        results = await self.client.messages.batches.results(batch_id)
        return [result async for result in results]

    async def cancel(self, batch_id: str) -> MessageBatch:
        return await self.client.messages.batches.cancel(batch_id)

    async def delete(self, batch_id: str) -> None:
        await self.client.messages.batches.delete(batch_id)

    async def clean_up_batch(self, batch_id: str) -> None:
        try:
            batch = await self.retrieve(batch_id)
        except Exception:
            return

        if batch.processing_status != "ended":
            await self.cancel(batch_id)
            batch = await self.wait_for_completion(batch_id)

        if batch.processing_status == "ended":
            await self.delete(batch_id)

    async def close(self) -> None:
        await self.client.close()

