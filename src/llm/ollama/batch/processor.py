import json

from typing import Any
from langchain_ollama import ChatOllama

from src.models.batch import UserRequest
from src.llm.common.common import HasLangChainResultParser,ValidOutputFormat


class OllamaBatchTaskProcessor(HasLangChainResultParser):
    contents: list[dict[str,Any]]
    model: ChatOllama
    user_requests: list[UserRequest]
    system:str
    retries:list[dict[str,Any]]

    def __init__(self, *, model: ChatOllama, system:str, output_format:ValidOutputFormat) -> None:
        self.contents = []
        self.user_requests = []
        self.model = model
        self.system = system
        self.output_format = output_format

    def build_user_requests(self) -> list[UserRequest]:
        raise NotImplementedError("Subclasses must implement build_user_requests().")

    def add_user_request(self, user_requests: list[UserRequest]) -> None:
        self.user_requests.extend(user_requests)

    def _build_user_input(self,user_request: UserRequest) -> list:
        user_input = json.loads(user_request.user_input)
        return[
            ("system", self.system),
            ("human", user_input),
        ]

    def _collect_results(self,results:list[Any]) -> list[dict[str,Any]]:
        contents = []
        for index, result in enumerate(results):
            if isinstance(result, Exception):
                contents.append(
                    {
                        "custom_id": self.user_requests[index].custom_id,
                        "content": "",
                        "completed": False,
                        "incomplete_reason": str(result),

                    }
                )
                continue

            contents.append(
                {
                    "custom_id": self.user_requests[index].custom_id,
                    "content": self.parse_result(result),
                    "completed": True,
                    "incomplete_reason": "",
                }
            )

        return contents

    async def run_batch(self,max_concurrency:int = 1) -> list[dict[str,Any]]:
        user_inputs = []

        for user_request in self.user_requests:
            user_inputs.append(
                self._build_user_input(user_request)
            )
        retry_model = self.model.with_retry(
            stop_after_attempt=3
        )

        results = await retry_model.abatch(
            inputs=user_inputs,
            max_concurrency=max_concurrency,
            return_exceptions=True,
        )

        contents = self._collect_results(results)
        self.contents = contents
        return contents

    async def retry_batch(self,max_retries:int = 3,max_concurrency:int = 1):
        retry_inputs = [
            self._build_user_input(user_request)
            for user_request, contents in zip(self.user_requests, self.contents)
            if not contents["completed"]
        ]
        if not retry_inputs:
            return self.contents

        for attempt in range(1,max_retries+1):
            retry_model = self.model.with_retry(
                stop_after_attempt=3
            )

            retry_results = await retry_model.abatch(
                inputs=retry_inputs,
                max_concurrency={"max_concurrency":max_concurrency},
                return_exceptions=True,
            )

            retry_contents = self._collect_results(retry_results)
            self.update_contents(retry_contents)
            if all(content["completed"] for content in self.contents):
                break

    def update_contents(self, retry_contents: list[dict[str, Any]]) -> None:
        retry_index = 0

        for index, content in enumerate(self.contents):
            if content["completed"]:
                continue

            self.contents[index] = retry_contents[retry_index]
            retry_index += 1







