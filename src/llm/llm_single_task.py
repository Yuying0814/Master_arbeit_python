from __future__ import annotations

import json
from typing import Any

from langchain_core.callbacks import UsageMetadataCallbackHandler
from langchain_core.language_models.chat_models import BaseChatModel
from langchain_core.runnables import RunnableLambda

from src.models.batch import UserRequest
from src.models.task_config import TaskConfig
from src.llm.model_factory import build_chat_model
from src.llm.common.common import HasOutputFormat, ValidOutputFormat


class LLMSingleTask(HasOutputFormat):
    user_input: str
    has_valid_output: bool
    model_name:str
    total_usage: dict[str, Any]
    final_usage: dict[str, Any]

    def __init__(
        self,
        *,
        model: BaseChatModel,
        model_name: str,
        system: str,
        output_format: ValidOutputFormat = None,
    ) -> None:

        self.model = model
        self.model_name = model_name
        self.system = system
        self.output_format = self.validate_output_format(output_format)
        self.user_input = ""
        self.has_valid_output = False
        self.total_usage = {}
        self.final_usage = {}

    @classmethod
    def load_from_task_config(
        cls,
        task_config: TaskConfig,
        api_key: str | None = None,
    ) -> "LLMSingleTask":

        if task_config.model.provider != "ollama" and not api_key:
            raise ValueError(f"{task_config.model.provider} expects a valid API key.")

        model = build_chat_model(
            api_key=api_key,
            provider=task_config.model.provider,
            model_name=task_config.model.model_name,
            temperature=task_config.model.temperature,
            max_output_tokens=task_config.model.max_tokens,
        )

        return cls(
            model=model,
            model_name=task_config.model.model_name,
            system=task_config.system,
            output_format=task_config.output_format,
        )

    async def run(self) -> Any:
        self.reset()

        if not self._has_valid_user_input():
            raise ValueError("User input must be provided.")

        messages = [
            ("system", self.system),
            ("human", self.user_input),
        ]

        callback = UsageMetadataCallbackHandler()
        invoke_kwargs = {
            "config": {
                "callbacks": [callback],
            }
        }

        if self._is_structured_format(self.output_format):
            structured_model = self.model.with_structured_output(
                self.output_format,
                include_raw=True,
            )

            checked_model = structured_model | RunnableLambda(
                _raise_if_structured_output_invalid
            )

            retry_model = _with_langchain_retry(checked_model)
            response = await retry_model.ainvoke(messages, **invoke_kwargs)

            result = response["parsed"]
            raw_message = response["raw"]

            self.total_usage = callback.usage_metadata or {}
            self.final_usage = {
                                   self.model_name:raw_message.usage_metadata or {}
                               }
            self.has_valid_output = True

            return result.model_dump()

        retry_model = _with_langchain_retry(self.model)
        response = await retry_model.ainvoke(messages, **invoke_kwargs)

        self.total_usage = callback.usage_metadata or {}
        self.final_usage = {
            self.model_name:response.usage_metadata or {}
                           }

        self.has_valid_output = True
        return response.content

    def add_user_inputs(self, user_inputs: str | list[UserRequest]) -> None:
        if not isinstance(user_inputs, str):
            self.user_input = _user_request_to_str(user_inputs)
        else:
            self.user_input = user_inputs

    def _has_valid_user_input(self) -> bool:
        return len(self.user_input.strip()) > 0

    def reset(self) -> None:
        self.has_valid_output = False
        self.total_usage = {}
        self.final_usage = {}


def _raise_if_structured_output_invalid(response: dict[str, Any]) -> dict[str, Any]:
    parsing_error = response.get("parsing_error")

    if parsing_error is not None:
        raise ValueError(f"Structured output parsing failed: {parsing_error}")

    if response.get("parsed") is None:
        raise ValueError("Structured output parsing returned None.")

    return response


def _user_request_to_str(user_requests: list[UserRequest]) -> str:
    data = {
        "requests": [
            request.model_dump()
            for request in user_requests
        ]
    }

    return json.dumps(data, ensure_ascii=False, indent=2)


def _with_langchain_retry(runnable):
    return runnable.with_retry(
        stop_after_attempt=3,
        wait_exponential_jitter=True,
    )