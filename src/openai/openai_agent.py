from __future__ import annotations
import warnings
import time
from collections.abc import Callable
from inspect import isclass
from openai import OpenAI
from pydantic import Field
from models.structuredOutputModel import StructuredOutputModel
from src.openai.openai_tool import OpenAITool
from src.openai.valid_format import ValidTextFormat
from openai.types.responses.parsed_response import ParsedResponse
from openai.types.responses.response_output_item import ResponseOutputItem
from typing import Any,TypeVar
T = TypeVar("T")

class OpenAIAgent:
    openai_client: OpenAI
    model: str
    instructions: str
    response_id: str | None
    tools: list[OpenAITool]
    text_format:ValidTextFormat
    timeout: int
    max_output_tokens:int
    current_response: ParsedResponse | None

    def __init__(self,api_key: str, *, model: str | None = None, instructions:str = None,
                 tools: list[OpenAITool] | None = None, text_format: ValidTextFormat | None = None,
                 max_output_tokens: int | None = None, timeout: int | None = None) -> None:

        self.openai_client = OpenAI(api_key=api_key)
        self.model = model if model is not None else "gpt-5-mini"
        self.instructions = instructions if instructions is not None else "You are a helpful assistant"
        self.tools = tools if tools is not None else []
        self.text_format = text_format if text_format is not None else "text"
        self.max_output_tokens = max_output_tokens if max_output_tokens is not None else 500
        self.timeout = timeout if timeout is not None else 2000

        self.response_id = None
        self.current_response = None

    def generate(self,user_input: str | list[Any], *, response_id: str | None = None, model: str | None=None,
                 task_instructions: str | None = None,
                 tools: list[OpenAITool] | None = None,text_format: ValidTextFormat | None = None,
                 max_output_tokens: int | None = None, timeout: int | None = None) -> ParsedResponse:

        if response_id is None:
            response_id = self.response_id
        if model is None:
            model = self.model
        if tools is None:
            tools = self.tools
        if text_format is None:
            text_format = self.text_format
        if max_output_tokens is None:
            max_output_tokens = self.max_output_tokens
        if timeout is None:
            timeout = self.timeout

        instructions = self.instructions
        if task_instructions:
            instructions += f"\n\nTask-specific instruction:\n{task_instructions}"

        user_input = _normalized_input(user_input)

        args = {
            "model":model,
            "input":user_input,
            "instructions":instructions,
            "text_format":_to_BaseModel(text_format),
            "max_output_tokens":max_output_tokens,
            "timeout":timeout
        }
        if tools:
            args["tools"] = [tool.get_openai_tool() for tool in tools]

        if response_id:
            args["previous_response_id"] = response_id

        response = self.openai_client.responses.parse(**args)
        self.current_response = response

        return response

    def update_response_id(self,response_id = None)->None:
        if response_id is None:
            response_id = getattr(self.current_response,"id",None)

        if response_id is not None:
            self.response_id = response_id

    def reset_message_history(self):
        self.response_id = None

    def has_tool_call(self,response:ParsedResponse = None) -> bool:
        if response is None:
            response = self.current_response

        output = getattr(response,"output",None)
        if output is not None:
            for item in output:
                if getattr(item,"type",None) == "function_call":
                    return True
        return False

    def has_message(self,response:ParsedResponse = None)->bool:
        if response is None:
            response = self.current_response

        output = getattr(response,"output",None)
        if output is not None:
            for item in output:
                if getattr(item,"type",None) == "message":
                    return True
        return False


    def collect_tool_calls(self,response:ParsedResponse = None)-> list[ResponseOutputItem]:
        tool_calls = []

        if response is None:
            response = self.current_response

        output = getattr(response,"output",None)

        if output is not None:
            for item in output:
                if getattr(item,"type",None) == "function_call":
                    tool_calls.append(item)
        return tool_calls

    @staticmethod
    def tool_call(item:ResponseOutputItem,tool:OpenAITool) -> Any:

        try:
            print("============================")
            print("tool call decided")

            arguments = getattr(item,"arguments",None)
            result = tool.call_with_json(arguments)
            name = getattr(item, "name", None)

            if result is None:
                if name is not None:
                    result = f"{name} call succeeded"

            print(f"{name} call succeeded")
            print("============================")
            return result

        except RuntimeError as e:
            raise RuntimeError from e

    def tool_calls(self,tool_calls:list[ResponseOutputItem],tools:list[OpenAITool] = None) -> list[dict[str,Any]]:
        if tools is None:
            tools = self.tools
        results = []
        tools_map = _tool_map(tools)

        for item in tool_calls:
            name = getattr(item,"name",None)
            if name is None:
                continue

            tool = tools_map.get(name,None)
            if tool is None:
                continue

            call_id = getattr(item,"call_id",None)
            if call_id is None:
                continue

            result = OpenAIAgent.tool_call(item,tool)

            results.append(
                {
                    "type": "function_call_output",
                    "call_id": call_id,
                    "output": result
                }
            )
        return results

    @staticmethod
    def run_with_retry(function: Callable[..., T], *args, max_retries: int = 3, base_delay: int = 2) -> T:
        for attempt in range(1, max_retries + 2):
            try:
                return function(*args)

            except Exception as error:
                if attempt > max_retries:
                    raise RuntimeError(f"Stage {function.__name__} failed") from error

                delay = base_delay * 2 ** (attempt - 1)

                warnings.warn(f"Stage {function.__name__} failed at attempt {attempt}/{max_retries + 1}",
                              RuntimeWarning, stacklevel=2)
                time.sleep(delay)
        raise RuntimeError(f"{function.__name__} failed")

# Helper
def _to_BaseModel(text_format:ValidTextFormat):
    if isinstance(text_format,str):
        if text_format.lower().strip() == "text" or text_format.lower().strip() == "json":
            return TextOutput
        else:
            raise ValueError("Invalid text_format，Text format must be one of:'text', 'JSON', a dict, or a StructuredOutputModel")
    elif isinstance(text_format,dict):
        return DictOutput
    elif isinstance(text_format,StructuredOutputModel):
        return text_format.__class__
    elif isclass(text_format) and issubclass(text_format, StructuredOutputModel):
        return text_format
    else:
        raise ValueError("Invalid text_format，Text format must be one of:'text', 'JSON', a dict, or a StructuredOutputModel")

def _tool_map(tools:list[OpenAITool]) -> dict[str,OpenAITool]:
    return{
        tool.fun_name: tool for tool in tools
    }

def _normalized_input(user_input:str|list[Any])->list[Any]:
    if isinstance(user_input,str):
        return [{
            "role": "user",
            "content": user_input
        }]
    if isinstance(user_input,list):
        return user_input
    raise ValueError("user input must be a str or a response input list")


class TextOutput(StructuredOutputModel):
    """Unified output model for text-based responses."""
    text: str = Field(
        description=(
            "The complete plain-text response shown to the user. Your plain text output should be stored here directly. "
            "JSON output should be serialized as a complete JSON string and also stored here directly."
        )
    )

class DictOutput(StructuredOutputModel):
    """Output model for dictionary data."""
    data: dict[str, Any]