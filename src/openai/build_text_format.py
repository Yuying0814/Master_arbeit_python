from typing import Any
from src.utils.build_json_schema import build_json_schema
from src.models.structuredOutputModel import StructuredOutputModel
from src.llm.common.types import ValidOutputFormat

def build_text_format(text_format:ValidOutputFormat,schema_name:str = "A json schema") -> dict[str, Any]:
    if isinstance(text_format,str):
        text_format = text_format.lower().strip()
        match text_format:
            case "text":
                return {"type":"text"}
            case "json":
                return {"type":"json_object"}
            case _:
                raise ValueError("Invalid text format，Text_format must be one of:'text', 'JSON'or a dict")

    if isinstance(text_format,dict):
        return build_json_schema(text_format,schema_name)

    if isinstance(text_format,StructuredOutputModel):
        return text_format.__class__.get_openai_format()

    if isinstance(text_format,type) and issubclass(text_format,StructuredOutputModel):
        return text_format.get_openai_format()

    raise ValueError("Invalid text_format，Text format must be one of:'text', 'JSON', a dict, or a StructuredOutputModel")