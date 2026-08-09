from typing import Any

from src.models.structuredOutputModel import StructuredOutputModel

class NormalizedUsage(StructuredOutputModel):
    input_tokens:int
    output_tokens:int
    total_tokens:int
    input_tokens_details: dict
    output_tokens_details: dict

class NormalizedTokenConsumption(StructuredOutputModel):
    final_usage:dict[str, Any]
    total_usage:dict[str, Any]
