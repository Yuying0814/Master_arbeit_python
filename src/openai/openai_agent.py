from __future__ import annotations
from inspect import isclass
from openai import OpenAI
from pydantic import Field
from models.structuredOutputModel import StructuredOutputModel
from src.openai.openai_tool import OpenAITool
from src.openai.valid_format import ValidTextFormat
from openai.types.responses.parsed_response import ParsedResponse
from openai.types.responses.response_output_item import ResponseOutputItem
from typing import Any

class OpenAIAgent:
    openai_client: OpenAI
    model: str
    system_instructions: str
    response_id: str | None
    tools: list[OpenAITool]
    text_format:ValidTextFormat
    timeout: int

    def __init__(self,api_key:str,*,model:str=None,system_instructions=None,
                 tools:list[OpenAITool]=None,text_format:ValidTextFormat=None,timeout:int=None)->None:

        self.openai_client = OpenAI(api_key=api_key)
        self.model = model if model is not None else "gpt-5-mini"
        self.system_instructions = system_instructions if system_instructions is not None else "You are a helpful assistant"
        self.text_format = text_format if text_format is not None else "text"
        self.timeout = timeout if timeout is not None else 2000
        self.tools = tools if tools is not None else []
        self.response_id = None

    def generate(self,user_input:str,*,model:str=None,instructions:str=None,
                 tools:list[OpenAITool]=None,response_id:str = None,text_format:ValidTextFormat=None,timeout:int=None)->ParsedResponse:
        if model is None:
            model = self.model
        if instructions is None:
            instructions = self.system_instructions
        if tools is None:
            tools = self.tools
        if text_format is None:
            text_format = self.text_format
        if timeout is None:
            timeout = self.timeout

        args = {
            "model":model,
            "input":user_input,
            "instructions":instructions,
            "text_format":_to_BaseModel(text_format),
            "timeout":timeout
        }
        if tools:
            args["tools"] = [tool.get_openai_tool() for tool in tools]

        if response_id:
            args["previous_response_id"] = response_id

        response = self.openai_client.responses.parse(**args)

        return response

    def update_response_id(self,response_id:str)->None:
        self.response_id = response_id

    def reset_message_history(self):
        self.response_id = None

    @staticmethod
    def has_tool_call(response:ParsedResponse) -> bool:
        for item in response.output:
            if item.type == "function_call":
                return True
        return False

    @staticmethod
    def has_message(response:ParsedResponse)->bool:
        for item in response.output:
            if item.type == "message":
                return True
        return False

    @staticmethod
    def collect_tool_calls(response:ParsedResponse)-> list[ResponseOutputItem]:
        tool_calls = []
        for item in response.output:
            if item.type == "function_call":
                tool_calls.append(item)
        return tool_calls

    @staticmethod
    def tool_call(item:ResponseOutputItem,tool:OpenAITool) -> Any:

        try:
            result = tool.call_with_json(item.arguments)
            if result is None:
                result = f"{item.name} call succeeded"
            return result

        except RuntimeError as e:
            raise RuntimeError from e

    def tool_calls(self,tool_calls:list[ResponseOutputItem],tools:list[OpenAITool] = None) -> list[dict[str,Any]]:
        if tools is None:
            tools = self.tools
        results = []
        tools_map = _tool_map(tools)
        for item in tool_calls:
            tool = tools_map.get(item.name)
            if tool is None:
                continue
            results.append(
                {
                    "type": "function_call_output",
                    "call_id": item.call_id,
                    "output": OpenAIAgent.tool_call(item,tool)
                }
            )
        return results

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

class TextOutput(StructuredOutputModel):
    """Unified output model for text-based responses."""
    text: str = Field(
        description=(
            "The final model output. Plain text should be stored directly. "
            "JSON output should be serialized as a complete JSON string."
        )
    )

class DictOutput(StructuredOutputModel):
    """Output model for dictionary data."""
    data: dict[str, Any]