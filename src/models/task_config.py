from __future__ import annotations
from typing import Literal
from pydantic import BaseModel, Field

LLMProvider = Literal["openai", "ollama"]

class ModelConfig(BaseModel):
    provider:LLMProvider = "openai"
    model_name:str = "gpt-5-mini"
    api_key:str | None = None
    temperature:float = 0.0
    max_tokens:int = 4000

class TaskConfig(BaseModel):
    model: ModelConfig = Field(default_factory=ModelConfig)
    system: str = "You are a helpful assistant"
    output_format: str = "text"


