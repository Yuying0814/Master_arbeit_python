from typing import Any
from langchain_ollama import ChatOllama
from langchain_core.callbacks import UsageMetadataCallbackHandler
from langchain_core.messages import AIMessage

from src.models.llm.batch import UserRequest
from src.models.llm.common import NormalizedUsage
from src.models.task_config import TaskConfig
from src.llm.common.common import HasLangChainOutput
from src.llm.common.types import ValidOutputFormat
from src.llm.common.batch_utils import sum_normalized_usage,normalize_usage_map,normalize_usage


class OllamaBatchTask(HasLangChainOutput):
    contents: list[dict[str,Any]]
    model: ChatOllama
    model_name:str
    user_requests: list[UserRequest]
    system:str
    retries:list[dict[str,Any]]
    max_concurrency:int
    has_valid_output:bool
    total_usage: dict[str, NormalizedUsage]
    final_usage: dict[str, NormalizedUsage]
    _final_usage_by_id: dict[str, NormalizedUsage]

    def __init__(self,
                 *,
                 model: ChatOllama,
                 model_name:str,
                 system:str,
                 output_format:ValidOutputFormat,
                 max_concurrency: int = 1
                 ) -> None:
        self.contents = []
        self.user_requests = []
        self.model = model
        self.model_name = model_name
        self.system = system
        self.output_format = self.validate_output_format(output_format)
        self.retries = []
        self.max_concurrency = max_concurrency
        self.has_valid_output = False
        self.total_usage = {}
        self.final_usage = {}
        self._final_usage_by_id = {}

    @classmethod
    def load_from_task_config(cls,task_config:TaskConfig) -> "OllamaBatchTask":
        model = ChatOllama(
            model=task_config.model.model_name,
            temperature=task_config.model.temperature,
            num_predict=task_config.model.max_tokens,
            base_url=task_config.model.base_url,
        )
        return cls(
            model = model,
            model_name=task_config.model.model_name,
            system = task_config.system,
            output_format = task_config.output_format,
            max_concurrency=task_config.model.ollama_batch_concurrency,
        )

    def set_concurrency(self,max_concurrency:int = 1) -> None:
        self.max_concurrency = max_concurrency


    async def run(self) -> list[dict[str,Any]]:
        if not self._has_user_request():
            raise ValueError("User requests must be added before starting the batch task.")

        callback = UsageMetadataCallbackHandler()

        config_kwargs = {
            "config":{
                "max_concurrency": self.max_concurrency,
                "callbacks": [callback],
            }
        }

        user_inputs = []

        self.reset()

        for user_request in self.user_requests:
            user_inputs.append(
                self._build_user_input(user_request)
            )
        retry_model = self._build_runnable_model()

        results = await retry_model.abatch(
            inputs=user_inputs,
            return_exceptions=True,
            **config_kwargs
        )

        contents = self._collect_results(self.user_requests,results)
        self.contents = contents
        
        final_contents = await self.retry_batch([callback])
        self.total_usage = normalize_usage_map(callback.usage_metadata or {})

        self.final_usage = {
            self.model_name: sum_normalized_usage(
                list(self._final_usage_by_id.values())
            )
        }

        return final_contents

    def add_user_inputs(self, user_requests: str| list[UserRequest]) -> None:
        if isinstance(user_requests, str):
            raise ValueError("OllamaBatchTaskProcessor expects a list of UserRequest.")

        existing_ids: set[str] = set()

        for request in user_requests:
            if request.custom_id in existing_ids:
                raise ValueError(
                    f"Duplicate custom_id: {request.custom_id}"
                )
            existing_ids.add(request.custom_id)

        self.user_requests = list(user_requests)

    async def retry_batch(self,callbacks:list[Any],max_retries:int = 3) -> list[dict[str,Any]]:

        for attempt in range(1,max_retries+1):
            retry_user_requests = [user_request for user_request, content in zip(self.user_requests, self.contents) if
                                   not content["completed"]]

            retry_inputs = [
                self._build_user_input(retry_user_request)
                for retry_user_request in retry_user_requests
            ]

            if not retry_inputs:
                self.has_valid_output = True
                return self.contents

            config_kwargs = {
                "config": {
                    "max_concurrency": self.max_concurrency,
                    "callbacks": callbacks,
                }
            }

            retry_model = self._build_runnable_model()
            retry_results = await retry_model.abatch(
                inputs=retry_inputs,
                return_exceptions=True,
                **config_kwargs
            )

            retry_contents = self._collect_results(retry_user_requests,retry_results)
            self._record_retry(retry_user_requests,retry_contents)
            self._update_contents(retry_contents)
            if all(content["completed"] for content in self.contents):
                self.has_valid_output = True
                break

        return self.contents

    def reset(self) -> None:
        self.contents = []
        self.retries = []
        self.has_valid_output = False
        self.total_usage = {}
        self.final_usage = {}
        self._final_usage_by_id = {}

    def cleanup_user_requests(self) -> None:
        self.user_requests = []

    def _build_runnable_model(self):
        if self._is_structured_format(self.output_format):
            return self.model.with_structured_output(
                self.output_format,
                include_raw=True,
            ).with_retry(
                stop_after_attempt=3,
            )

        return self.model.with_retry(
            stop_after_attempt=3
        )

    def _build_user_input(self,user_request: UserRequest) -> list:
        user_input = user_request.user_input
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
                raw_message = self._get_raw_message(result)

                if raw_message.usage_metadata:
                    self._final_usage_by_id[user_request.custom_id] = (
                        normalize_usage(raw_message.usage_metadata)
                    )

                parsed_content = self._parse_result(result)

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

    def _get_raw_message(self,result: Any,) -> AIMessage:
        if self._is_structured_format(self.output_format):
            raw_message = result.get("raw")

            if not isinstance(raw_message, AIMessage):
                raise TypeError(
                    "Structured output must contain a raw AIMessage."
                )

            return raw_message

        if not isinstance(result, AIMessage):
            raise TypeError(
                "Text output must be an AIMessage."
            )

        return result

    def _parse_result(self,result: Any,) -> Any:
        if self._is_structured_format(self.output_format):
            parsing_error = result.get("parsing_error")

            if parsing_error is not None:
                raise ValueError(
                    f"Structured output parsing failed: {parsing_error}"
                )

            parsed = result.get("parsed")

            if parsed is None:
                raise ValueError(
                    "Structured output parsing returned None."
                )

            return parsed.model_dump()

        if not isinstance(result, AIMessage):
            raise TypeError(
                "Text output must be an AIMessage."
            )

        return result.content

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


# Helper
def build_custom_id_content_map(contents: list[dict[str,Any]]) -> dict[str,dict[str,Any]]:
    return {
        content["custom_id"]: content for content in contents
    }





