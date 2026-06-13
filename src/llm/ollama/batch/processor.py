import json

from pathlib import Path
from typing import Any
from langchain_ollama import ChatOllama

from src.models.batch import UserRequest
from src.models.task_config import TaskConfig
from src.llm.common.common import HasLangChainResultParser,ValidOutputFormat


class OllamaBatchTaskProcessor(HasLangChainResultParser):
    contents: list[dict[str,Any]]
    model: ChatOllama
    user_requests: list[UserRequest]
    system:str
    retries:list[dict[str,Any]]
    max_concurrency:int

    def __init__(self, *, model: ChatOllama, system:str, output_format:ValidOutputFormat) -> None:
        self.contents = []
        self.user_requests = []
        self.model = model
        self.system = system
        self.output_format = output_format
        self.retries = []
        self.max_concurrency = 1

    @classmethod
    def load_from_task_config(cls,api_key:str,task_config:TaskConfig):
        model = ChatOllama(
            model=task_config.model.model_name,
            temperature=task_config.model.temperature,
            num_predict=task_config.model.max_tokens,
        )
        return cls(
            model = model,
            system = task_config.system,
            output_format = task_config.output_format,
        )

    def set_concurrency(self,max_concurrency:int = 1) -> None:
        self.max_concurrency = max_concurrency


    async def run(self) -> list[dict[str,Any]]:
        if self._has_user_request():
            raise ValueError("User requests must be added before starting the batch task.")
        user_inputs = []

        for user_request in self.user_requests:
            user_inputs.append(
                self._build_user_input(user_request)
            )
        retry_model = self._build_runnable_model()

        results = await retry_model.abatch(
            inputs=user_inputs,
            config={"max_concurrency":self.max_concurrency},
            return_exceptions=True,
        )

        contents = self._collect_results(self.user_requests,results)
        self.contents = contents
        return await self.retry_batch()

    def add_user_inputs(self, user_requests: str| list[UserRequest]) -> None:
        if isinstance(user_requests, str):
            raise ValueError("OllamaBatchTaskProcessor expects a list of UserRequest.")
        self.user_requests.extend(user_requests)

    async def retry_batch(self,max_retries:int = 3) -> list[dict[str,Any]]:

        for attempt in range(1,max_retries+1):
            retry_user_requests = [user_request for user_request, content in zip(self.user_requests, self.contents) if
                                   not content["completed"]]

            retry_inputs = [
                self._build_user_input(retry_user_request)
                for retry_user_request in retry_user_requests
            ]

            if not retry_inputs:
                return self.contents

            retry_model = self._build_runnable_model()

            retry_results = await retry_model.abatch(
                inputs=retry_inputs,
                config={"max_concurrency":self.max_concurrency},
                return_exceptions=True,
            )

            retry_contents = self._collect_results(retry_user_requests,retry_results)
            self._record_retry(retry_user_requests,retry_contents)
            self._update_contents(retry_contents)
            if all(content["completed"] for content in self.contents):
                break

        return self.contents

    def reset(self):
        self.contents = []
        self.user_requests = []
        self.retries = []

    def _build_runnable_model(self):
        if self._is_structured_format(self.output_format):
            return self.model.with_structured_output(self.output_format).with_retry(
                stop_after_attempt=3
            )

        return self.model.with_retry(
            stop_after_attempt=3
        )

    def _build_user_input(self,user_request: UserRequest) -> list:
        user_input = json.loads(user_request.user_input)
        return[
            ("system", self.system),
            ("human", user_input),
        ]

    def _collect_results(self,user_requests: list[UserRequest],results: list[Any],) -> list[dict[str, Any]]:
        contents = []

        for user_request, result in zip(user_requests, results):
            if isinstance(result, Exception):
                contents.append(
                    {
                        "custom_id": user_request.custom_id,
                        "content": "",
                        "completed": False,
                        "incomplete_reason": str(result),
                    }
                )
                continue

            try:
                parsed_content = self.parse_result(result)

                contents.append(
                    {
                        "custom_id": user_request.custom_id,
                        "content": parsed_content,
                        "completed": True,
                        "incomplete_reason": "",
                    }
                )

            except Exception as error:
                contents.append(
                    {
                        "custom_id": user_request.custom_id,
                        "content": "",
                        "completed": False,
                        "incomplete_reason": str(error),
                    }
                )

        return contents

    def _record_retry(self,retry_user_requests: list[UserRequest],retry_contents: list[dict[str,Any]]) -> None:
            self.retries.append(
                {
                    "retry_custom_ids":[user_request.custom_id for user_request in retry_user_requests],
                    "retry_contents":retry_contents,
                }
            )

    def _update_contents(self, retry_contents: list[dict[str, Any]]) -> None:
        custom_id_retry_content_map = build_custom_id_content_map(retry_contents)

        for index, content in enumerate(self.contents):
            if content["custom_id"] in custom_id_retry_content_map:
                self.contents[index] = custom_id_retry_content_map[content["custom_id"]]

    def _has_user_request(self) -> bool:
        return len(self.user_requests) > 0


#
def build_custom_id_content_map(contents: list[dict[str,Any]]) -> dict[str,dict[str,Any]]:
    return {
        content["custom_id"]: content for content in contents
    }





