from __future__ import annotations

import time
from collections import defaultdict
from typing import Any

from langchain_core.tools import StructuredTool

from src.coding.retriever.retriever import PageRetriever
from src.llm.common.batch_utils import sum_normalized_usage
from src.models.coding.retriever import RetrievalResult, RetrievalTopic, RetrieverLog
from src.models.llm.common import NormalizedUsage


class RetrieverTool:
    def __init__(self, retriever: PageRetriever) -> None:
        self.retriever = retriever
        self._attempt_logs: list[RetrieverLog] = []
        self._attempt_results: list[RetrievalResult] = []
        self._elapsed_time = 0.0

    def begin_attempt(self) -> None:
        self._attempt_logs.clear()
        self._attempt_results.clear()
        self._elapsed_time = 0.0

    async def retrieve_pages(self, topics: list[RetrievalTopic]) -> dict[str, Any]:
        print(f" -> start retrieve_datasheet_pages ({len(topics)} topics)")
        start_time = time.perf_counter()
        try:
            response = await self.retriever.run(topics)
        finally:
            print(" -> retrieve_datasheet_pages completed")
        self._elapsed_time += time.perf_counter() - start_time

        self._attempt_logs.append(self.retriever.logs[-1].model_copy(deep=True))
        self._attempt_results.extend(
            result.model_copy(deep=True)
            for result in response.results
        )
        return response.model_dump(mode="json")

    def as_tool(self) -> StructuredTool:
        return StructuredTool.from_function(
            coroutine=self.retrieve_pages,
            name="retrieve_datasheet_pages",
            description=(
                "Retrieve datasheet pages for focused topics. Call this tool "
                "when the register map is insufficient for implementation or verification."
            ),
        )

    def get_results(self) -> list[RetrievalResult]:
        return [result.model_copy(deep=True) for result in self._attempt_results]

    def get_log(self) -> RetrieverLog | None:
        if not self._attempt_logs:
            return None

        return RetrieverLog(
            request_id=self._attempt_logs[-1].request_id,
            topics=[topic for log in self._attempt_logs for topic in log.topics],
            retrieval_results=self.get_results(),
            token_consumption=self._merge_token_consumption(),
        )

    def get_elapsed_time(self) -> float:
        elapsed_time = self._elapsed_time
        self._elapsed_time = 0.0
        return elapsed_time

    def _merge_token_consumption(self) -> dict[str, dict[str, dict[str, Any]]]:
        usage_by_kind: dict[str, dict[str, list[NormalizedUsage]]] = defaultdict(
            lambda: defaultdict(list)
        )

        for log in self._attempt_logs:
            for usage_kind, usage_by_model in log.token_consumption.items():
                for model_name, usage in usage_by_model.items():
                    usage_by_kind[usage_kind][model_name].append(
                        NormalizedUsage.model_validate(usage)
                    )

        return {
            usage_kind: {
                model_name: sum_normalized_usage(usages).model_dump(mode="json")
                for model_name, usages in usage_by_model.items()
            }
            for usage_kind, usage_by_model in usage_by_kind.items()
        }
