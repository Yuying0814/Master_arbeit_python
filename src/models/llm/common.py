from typing import Any

from pydantic import Field

from src.models.structuredOutputModel import StructuredOutputModel

class NormalizedUsage(StructuredOutputModel):
    input_tokens:int  = Field(default=0)
    output_tokens:int = Field(default=0)
    total_tokens:int = Field(default=0)
    input_token_details: dict[str, Any] = Field(default_factory=dict)
    output_token_details: dict[str, Any] = Field(default_factory=dict)

class NormalizedTokenConsumption(StructuredOutputModel):
    final_usage: dict[str, NormalizedUsage] = Field(default_factory=dict)
    total_usage: dict[str, NormalizedUsage] = Field(default_factory=dict)