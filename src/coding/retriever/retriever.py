from pathlib import Path
from typing import Any

from src.llm.llm_task_runner import LLMTaskRunner
from src.models.task_config import TaskConfig
from src.models.retriever import RetrievalTopic, RetrievalRequest, RetrievalResponse, RetrievalResult,BinaryClassifierOutput
from src.models.batch import UserRequest
from src.coding.retriever.build_batch_request import build_user_requests
from src.coding.retriever.parse_binary_classifier_output import parse_binary_classifier_output

class PageRetriever:
    binary_classifier:LLMTaskRunner
    pages: list[dict[str,Any]]
    request_id:int
    log: list

    def __init__(self,binary_classifier:LLMTaskRunner, pages:list[dict[str,Any]]) -> None:
        self.binary_classifier = binary_classifier
        self.pages = pages
        self.request_id = 0

    async def run(self,topics: list[RetrievalTopic]) -> RetrievalResponse:
        retrieval_requests = build_user_requests(request_id=self.request_id, topics=topics, pages=self.pages)

        page_indices = await self._run_classification_llm_task(retrieval_requests,len(topics))
        result = self._generate_retrieval_response(page_indices, topics)
        self.request_id += 1
        return result

    async def _run_classification_llm_task(self,retrieval_requests:list[UserRequest],len_topics:int) -> list[list[int]]:
        contents = await self._run_classifier(retrieval_requests)
        return parse_binary_classifier_output(contents,retrieval_requests,len_topics)

    async def _run_classifier(self,retrieval_requests) -> list[dict[str,Any]]:
        return await self.binary_classifier.run(retrieval_requests)

    def _generate_retrieval_response(self,page_indices:list[list[int]], topics:list[RetrievalTopic]) -> RetrievalResponse:
        return RetrievalResponse(
            request_id=self.request_id,
            results=[
                RetrievalResult(
                    topic=topic,
                    pages = self._get_page_by_index(page_index)
                ) for page_index,topic in zip(page_indices, topics)
            ],
        )

    def _get_page_by_index(self,page_index:list[int]) -> list[dict[str,Any]]:
        return [self.pages[index] for index in page_index]

    @classmethod
    def load_from_task_config(cls,pages:list[dict[str,Any]] ,task_config: TaskConfig, api_key:str = None, input_path:str|Path = None) -> "PageRetriever":
        classifier = LLMTaskRunner.load_from_task_config(task_config, api_key, input_path)
        return cls(binary_classifier=classifier,pages=pages)