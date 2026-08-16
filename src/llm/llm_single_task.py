from __future__ import annotations

import json
from typing import Any

from langchain_core.callbacks import UsageMetadataCallbackHandler
from langchain_core.language_models.chat_models import BaseChatModel
from langchain_core.runnables import RunnableLambda

from src.models.llm.batch import UserRequest
from src.models.llm.common import NormalizedUsage
from src.models.task_config import TaskConfig
from src.llm.model_factory import build_chat_model
from src.llm.common.common import HasOutputFormat, ValidOutputFormat
from src.llm.common.types import LLMProvider
from src.llm.common.batch_utils import normalize_usage,normalize_usage_map


class LLMSingleTask(HasOutputFormat):
    user_input: str
    has_valid_output: bool
    model_name:str
    total_usage: dict[str, NormalizedUsage]
    final_usage: dict[str, NormalizedUsage]

    def __init__(
        self,
        *,
        model: BaseChatModel,
        provider: LLMProvider,
        model_name: str,
        system: str,
        output_format: ValidOutputFormat = None,
    ) -> None:

        self.model = model
        self.model_name = model_name
        self.provider = provider
        self.system = system
        self.output_format = self.validate_output_format(output_format)
        self.user_input = ""
        self.has_valid_output = False
        self.total_usage = {}
        self.final_usage = {}

    @classmethod
    def load_from_task_config(cls,task_config: TaskConfig,api_key: str | None = None,) -> "LLMSingleTask":

        if task_config.model.provider != "ollama" and not api_key:
            raise ValueError(f"{task_config.model.provider} expects a valid API key.")

        model = build_chat_model(
            api_key=api_key,
            provider=task_config.model.provider,
            model_name=task_config.model.model_name,
            thinking_effort=task_config.model.thinking_effort,
            temperature=task_config.model.temperature,
            max_output_tokens=task_config.model.max_tokens,
        )

        return cls(
            model=model,
            provider=task_config.model.provider,
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
            if self.provider == "zai":
                output_schema = self.output_format.model_json_schema()

                messages = [
                    (
                        "system",
                        (
                            f"{self.system}\n\n"
                            "Return only one JSON object that conforms to the "
                            "following JSON Schema:\n"
                            f"{json.dumps(output_schema, ensure_ascii=False)}"
                        ),
                    ),
                    ("human", self.user_input),
                ]

                structured_model = self.model.with_structured_output(
                    self.output_format,
                    method="json_mode",
                    include_raw=True,
                )

            else:
                structured_model = self.model.with_structured_output(
                    self.output_format,
                    method="json_schema",
                    include_raw=True,
                )

            checked_model = structured_model | RunnableLambda(
                _raise_if_structured_output_invalid
            )

            response = await checked_model.ainvoke(messages, **invoke_kwargs)

            result = response["parsed"]
            raw_message = response["raw"]

            self.total_usage = normalize_usage_map(callback.usage_metadata or {})
            self.final_usage = {
                self.model_name: NormalizedUsage.model_validate(
                    raw_message.usage_metadata or {}
                )
            }
            self.has_valid_output = True

            return result

        response = await self.model.ainvoke(messages, **invoke_kwargs)

        self.total_usage = normalize_usage_map(callback.usage_metadata or {})

        self.final_usage = {
            self.model_name: normalize_usage(
                response.usage_metadata or {}
            )
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
        raw_message = response.get("raw")

        if raw_message is not None:
            print(f"Response metadata: {raw_message.response_metadata}")
            print(f"Usage metadata: {raw_message.usage_metadata}")

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