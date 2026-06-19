from __future__ import annotations
from pydantic import BaseModel, Field
from dataclasses import dataclass
from src.llm.common.types import ValidOutputFormat,LLMProvider


class ModelConfig(BaseModel):
    provider:LLMProvider = "openai"
    is_batch: bool = False
    model_name:str = "gpt-5-mini"
    temperature:float = 0.0
    max_tokens:int = 4000

class TaskConfig(BaseModel):
    model: ModelConfig = Field(default_factory=ModelConfig)
    system: str = "You are a helpful assistant"
    output_format: ValidOutputFormat = "text"
    memory_enabled: bool = False

class CodingTaskConfigs(BaseModel):
    retrieval: TaskConfig
    planning:TaskConfig
    coding:TaskConfig
    verification_semantic:TaskConfig
    verification_test_coder:TaskConfig