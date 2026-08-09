from typing import Any

from pydantic import Field
from pygments.styles import default

from src.models.structuredOutputModel import StructuredOutputModel

class NormalizedUsage(StructuredOutputModel):
    input_tokens:int  = Field(default=0)
    output_tokens:int = Field(default=0)
    total_tokens:int = Field(default=0)
    input_tokens_details: dict[str, Any] = Field(default={})
    output_tokens_details: dict[str, Any] = Field(default={})

class NormalizedTokenConsumption(StructuredOutputModel):
    final_usage:NormalizedUsage
