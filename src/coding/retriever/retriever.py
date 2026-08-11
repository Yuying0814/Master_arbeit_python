import copy

from pathlib import Path
from typing import Any


from src.llm.llm_task_runner import LLMTaskRunner
from src.models.task_config import TaskConfig
from src.models.coding.retriever import RetrievalTopic, RetrievalResponse, RetrievalResult, RetrieverLog, RetrieverUserInput
from src.models.llm.batch import UserRequest
from src.models.data_manager import DocumentRecord
from src.models.coding.coding_common import InputDocument
from src.coding.retriever.build_batch_request import build_user_requests
from src.coding.retriever.parse_binary_classifier_output import parse_binary_classifier_output

class PageRetriever:
    binary_classifier:LLMTaskRunner
    documents: list[DocumentRecord]
    request_id:int
    logs: list

    def __init__(self,binary_classifier:LLMTaskRunner, documents:list[DocumentRecord]) -> None:
        self.binary_classifier = binary_classifier
        self.documents = documents
        self.request_id = 0
        self.logs = []
        print("retriever created")

    async def run(self,topics: list[RetrievalTopic]) -> RetrievalResponse:
        if not topics:
            response = RetrievalResponse(
                request_id=self.request_id,
                results=[],
            )
            self._update_logs(topics,[])
            self.request_id += 1
            return response

        retrieval_requests = build_user_requests(request_id=self.request_id, topics=topics, documents=self.documents)

        text = "\n".join(str(topic.topic_keywords) for topic in topics)
        print(
            f" -> start retrieving pages related to:\n"
            f"{text}\n"
        )
        page_indices_by_pdf= await self._run_classification_llm_task(retrieval_requests, len(topics))

        lines = [
            " -> retrieving pages completed",
            "==================",
        ]

        for pdf_sha256, page_indices_by_topics in page_indices_by_pdf.items():
            lines.append(f"pdf_sha256: {pdf_sha256}")
            lines.append("page indices for every topic:")
            lines.extend(str(page_indices) for page_indices in page_indices_by_topics)

        lines.append("==================")

        print("\n".join(lines))

        result = self._generate_retrieval_response(page_indices_by_pdf, topics)
        self._update_logs(topics, result.results)
        self.request_id += 1

        return result

    @classmethod
    def load_from_task_config(
            cls,
            documents:list[DocumentRecord],
            task_config: TaskConfig,
            api_key:str = None,
            input_path:str|Path = None
    ) -> "PageRetriever":

        classifier = LLMTaskRunner.load_from_task_config(
            task_config,
            api_key,
            input_path
        )
        return cls(
            binary_classifier=classifier,
            documents=documents
        )

    async def _run_classification_llm_task(
            self,
            retrieval_requests:RetrieverUserInput,
            len_topics:int
    ) -> dict[str, list[list[int]]]:

        contents = await self._run_classifier(
            retrieval_requests.user_requests,
        )

        return parse_binary_classifier_output(
            contents,
            retrieval_requests,
            len_topics
        )

    async def _run_classifier(
            self,
            retrieval_requests:list[UserRequest]
    ) -> list[dict[str,Any]]:

        return await self.binary_classifier.run(
            retrieval_requests
        )

    def _generate_retrieval_response(
            self,
            page_indices_by_pdfs:dict[str,list[list[int]]],
            topics:list[RetrievalTopic]
    ) -> RetrievalResponse:

        results = []
        for topic_index,topic in enumerate(topics):
            documents = []
            for pdf_sha256, page_indices_by_topics in page_indices_by_pdfs.items():
                documents.append(
                    InputDocument(
                        pdf_sha256 = pdf_sha256,
                        pages = self._get_page_by_index(pdf_sha256, page_indices_by_topics[topic_index]),
                    )
                )
            results.append(
                RetrievalResult(
                    topic=topic,
                    documents=documents,
                )
            )

        response = RetrievalResponse(
            request_id=self.request_id,
            results=results
        )

        return response

    def _get_page_by_index(
            self,
            pdf_sha256:str,
            page_indices:list[int]
    ) -> list[dict[str,Any]]:
        pages = None
        for document in self.documents:
            if document.pdf_sha256 == pdf_sha256:
                pages = document.pages
                break

        if pages is None:
            raise ValueError(
                f"No document found for pdf_sha256: {pdf_sha256}"
            )

        pages_by_index = {
            page["index"]: page
            for page in pages
        }

        return [
            pages_by_index[index]
            for index in page_indices
        ]

    def _update_logs(
            self,
            topics: list[RetrievalTopic],
            retrieval_results: list[RetrievalResult],
    ) -> None:

        self.logs.append(
            RetrieverLog(
                request_id=self.request_id,
                topics=[topic.model_copy(deep=True) for topic in topics],
                retrieval_results=[
                    result.model_copy(deep=True) for result in retrieval_results
                ],
                token_consumption=self.binary_classifier.token_consumption.model_dump(
                    mode="json"
                ) if topics else{
                    "total_usage": {},
                    "final_usage": {},
                },
            )
        )
