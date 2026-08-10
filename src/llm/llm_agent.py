from collections.abc import Callable
from typing import Any
from pydantic import BaseModel

from langchain_core.tools import BaseTool
from langchain.agents import create_agent
from langgraph.checkpoint.memory import InMemorySaver
from langgraph.checkpoint.serde.jsonplus import JsonPlusSerializer
from langchain_core.language_models.chat_models import BaseChatModel
from langchain_core.callbacks import UsageMetadataCallbackHandler


from src.models.structuredOutputModel import StructuredOutputModel
from src.models.task_config import TaskConfig
from src.llm.model_factory import build_chat_model
from src.llm.common.types import ValidOutputFormat


class LLMAgent:
    agent: Any
    check_pointer: Any
    has_structured_output: bool
    total_tokens: dict[str, Any]
    memory_enabled: bool
    thread_id: str | None

    def __init__(
        self,
        model: BaseChatModel,
        *,
        tools: list[Callable | BaseTool | dict] | None = None,
        system_prompt: str | None = None,
        output_format: ValidOutputFormat = None,
        memory_enabled: bool = False,
        thread_id: str | None = None,
    ) -> None:
        if tools is None:
            tools = []

        if system_prompt is None:
            system_prompt = "You are a helpful assistant"

        response_format = None
        if output_format is not None:
            response_format = _build_response_format(output_format)

        self.memory_enabled = memory_enabled
        self.thread_id = thread_id if memory_enabled else None

        self.total_tokens = {}

        if memory_enabled:
            allowed_msgpack_modules = _build_allowed_msgpack_modules(output_format)

            serializer = JsonPlusSerializer(
                allowed_msgpack_modules=allowed_msgpack_modules,
            )

            self.check_pointer = InMemorySaver(serde=serializer)
        else:
            self.check_pointer = None

        self.agent = create_agent(
            model=model,
            tools=tools,
            system_prompt=system_prompt,
            response_format=response_format,
            checkpointer=self.check_pointer,
        )

        self.has_structured_output = _is_structured_output(response_format)

    @classmethod
    def load_from_task_config(
        cls,
        task_config: TaskConfig,
        *,
        api_key: str | None = None,
        tools: list[Callable | BaseTool | dict] | None = None,
        thread_id: str | None = None,
    ) -> "LLMAgent":
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
            tools=tools,
            system_prompt=task_config.system,
            output_format=task_config.output_format,
            memory_enabled=task_config.memory_enabled,
            thread_id=thread_id,
        )

    def run(self, user_input: str) -> Any:

        usage_callback = UsageMetadataCallbackHandler()

        response = self.agent.invoke(
            _build_messages(user_input),
            config=self._build_invoke_config(),
        )

        self._update_total_tokens()

        return self._parse_response(response)

    def run_with_retry(self, user_input: str) -> Any:

        usage_callback = UsageMetadataCallbackHandler()

        retry_agent = self.agent.with_retry(
            stop_after_attempt=3,
            wait_exponential_jitter=True,
        )

        response = retry_agent.invoke(
            _build_messages(user_input),
            config=self._build_invoke_config(),
        )

        self._update_total_tokens()

        return self._parse_response(response)

    def _build_invoke_config(self,usage_callback: UsageMetadataCallbackHandler) -> dict[str, Any]:

        config: dict[str, Any] = {
            "callbacks": [usage_callback],
        }

        if self.memory_enabled:
            if self.thread_id is None:
                raise ValueError("thread_id is required when memory is enabled.")

            config["configurable"] = {
                "thread_id": self.thread_id,
            }

        return config

    def _parse_response(self, response: dict[str, Any]) -> Any:
        try:
            if self.has_structured_output:
                return response["structured_response"]

            return response["messages"][-1].content

        except Exception as e:
            raise RuntimeError("Failed to parse response") from e

    def _update_total_tokens(self,usage_callback:UsageMetadataCallbackHandler) -> None:
        self.total_tokens = dict(usage_callback.usage_metadata)

# Helper
def _build_response_format(output_format: ValidOutputFormat) -> Any | None:
    if output_format is None:
        return None

    if isinstance(output_format, str) and output_format.lower().strip() == "text":
        return None

    if isinstance(output_format, type) and issubclass(output_format, StructuredOutputModel):
        return output_format

    raise TypeError("Invalid output format")


def _build_messages(user_request: str) -> dict[str, Any]:
    return {
        "messages": [
            {
                "role": "user",
                "content": user_request,
            }
        ]
    }


def _is_structured_output(response_format: Any) -> bool:
    return (
        isinstance(response_format, dict)
        or (
            isinstance(response_format, type)
            and issubclass(response_format, StructuredOutputModel)
        )
    )

def _get_pydantic_model_class(output_format: ValidOutputFormat|None) -> type[BaseModel] | None:
    if isinstance(output_format, BaseModel):
        return output_format.__class__

    if isinstance(output_format, type) and issubclass(output_format, BaseModel):
        return output_format

    return None

def _build_allowed_msgpack_modules(
    output_format: ValidOutputFormat|None,
) -> list[tuple[str, str]]:
    model_cls = _get_pydantic_model_class(output_format)

    if model_cls is None:
        return []

    return [
        (model_cls.__module__, model_cls.__name__),
    ]