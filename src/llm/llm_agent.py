import json

from collections.abc import Callable
from typing import Any

from langchain_core.tools import BaseTool
from langchain.agents import create_agent
from langgraph.checkpoint.memory import InMemorySaver
from langchain_core.language_models.chat_models import BaseChatModel
from langchain_core.callbacks import UsageMetadataCallbackHandler

from src.models.batch import UserRequest
from src.models.structuredOutputModel import StructuredOutputModel
from src.models.task_config import TaskConfig
from src.llm.model_factory import build_chat_model
from src.llm.common.types import ValidOutputFormat


class LLMAgent:
    task_name:str
    agent: Any
    check_pointer:Any
    is_structured_output:bool
    total_tokens:dict[str,Any]
    usage_callback:Any

    def __init__(self,
                 model:BaseChatModel,
                 task_name:str,
                 *,
                 tools:list[Callable | BaseTool | dict]=None,
                 system_prompt:str|None = None,
                 output_format: ValidOutputFormat=None) -> None:
        if tools is None:
            tools = []
        if system_prompt is None:
            system_prompt = "You are a helpful assistant"

        response_format = None
        if output_format is not None:
            response_format = _build_response_format(output_format)

        self.task_name = task_name
        self.usage_callback = UsageMetadataCallbackHandler()
        self.check_pointer = InMemorySaver()

        self.agent = create_agent(
            model = model,
            tools = tools,
            system_prompt=system_prompt,
            response_format=response_format,
            checkpointer=self.check_pointer,
        )

        self.is_structured_output = _is_structured_output(response_format)

    @classmethod
    def load_from_task_config(
            cls,
            task_config:TaskConfig,
            task_name:str,
            *,
            api_key:str|None=None,
            tools:list[Callable | BaseTool | dict]=None) -> 'LLMAgent':
        model = build_chat_model(
            api_key=api_key,
            provider=task_config.model.provider,
            model_name=task_config.model.model_name,
            temperature=task_config.model.temperature,
            max_output_tokens=task_config.model.max_tokens,
        )

        return cls(
            model=model,
            task_name=task_name,
            tools=tools,
            system_prompt=task_config.system,
            output_format=task_config.output_format,
        )

    def run(self,user_input:str) -> Any:
        config = {
            "configurable": {
                "thread_id": self.task_name
            },
            "callbacks":[self.usage_callback],
        }

        response = self.agent.invoke(
            _build_messages(user_input),
            config = config,
        )

        self._update_total_tokens()

        return self._parse_response(response)

    def run_with_retry(self,user_input:str) -> Any:

        config = {
            "configurable": {
                "thread_id": self.task_name
            },
            "callbacks":[self.usage_callback],
        }

        retry_agent = self.agent.with_retry(
            stop_after_attempt=3,
            wait_exponential_jitter=True,
        )

        response = retry_agent.invoke(
            _build_messages(user_input),
            config = config,
        )

        self._update_total_tokens()

        return self._parse_response(response)

    def _parse_response(self,response: dict[str, Any]) -> Any:
        try:
            if self.is_structured_output:
                return response["structured_response"]
            else:
                return response["messages"][-1].content
        except Exception as e:
            raise RuntimeError("Failed to parse response") from e

    def _update_total_tokens(self):
        self.total_tokens = self.usage_callback.usage_metadata

#Helper
def _build_response_format(output_format:ValidOutputFormat):
    if isinstance(output_format,str) and (output_format == "text" or output_format == "json"):
        return None
    elif isinstance(output_format,dict):
        return output_format
    elif isinstance(output_format,StructuredOutputModel):
        return output_format.__class__
    elif isinstance(output_format,type) and issubclass(output_format,StructuredOutputModel):
        return output_format
    else:
        raise TypeError("Invalid output format")

def _build_messages(user_request:str):
    return {
        "messages": [
            {
                "role": "user",
                "content": user_request,
            }
        ]
    }

def _is_structured_output(response_format):
    return (isinstance(response_format, type) and issubclass(response_format, StructuredOutputModel)) or\
    isinstance(response_format,StructuredOutputModel) or isinstance(response_format,dict)