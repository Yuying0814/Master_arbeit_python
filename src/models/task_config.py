from __future__ import annotations


from pydantic import BaseModel, ConfigDict, Field, field_validator
from typing import Literal

from src.llm.common.types import ValidOutputFormat,LLMProvider,ThinkingEffort

class ModelConfig(BaseModel):
    model_config = ConfigDict(validate_assignment=True)

    provider:LLMProvider = "openai"
    is_batch: bool = False
    model_name:str = "gpt-5-mini"
    thinking_effort: ThinkingEffort = None
    temperature:float|None = None
    max_tokens:int = 4000
    timeout: int | None = 1800
    base_url: str | None = None
    ollama_batch_concurrency: int = Field(default=1, ge=1)

    @field_validator("base_url", "thinking_effort", mode="before")
    @classmethod
    def normalize_optional_strings(cls, value):
        if isinstance(value, str):
            value = value.strip()
            if not value:
                return None
        return value

class TaskConfig(BaseModel):
    model: ModelConfig = Field(default_factory=ModelConfig)
    system: str = "You are a helpful assistant"
    output_format: ValidOutputFormat = None
    memory_enabled: bool = False

class OcrConfig(BaseModel):
    provider: Literal["mistral","glm"]
    model_name: str
    include_image: bool = True
    table_format: Literal["html","markdown"] = "html"
    url:str = "http://localhost:11434"
    layout_device:str = "cpu"
    connection_pool_size: int = 1
    max_workers: int = 1
    batch_size: int = 1

class PreprocessingTaskConfigs(BaseModel):
    classify_pages:TaskConfig
    verify_reg_sum_pages:TaskConfig
    verify_reg_pages:TaskConfig
    extract_reg_index:TaskConfig
    extract_reg_map:TaskConfig
    identify_function: TaskConfig

class CodingTaskConfigs(BaseModel):
    retrieval: TaskConfig
    planning:TaskConfig
    coding:TaskConfig
    verification_semantic:TaskConfig
    verification_test_coder:TaskConfig

class ChatTaskConfigs(BaseModel):
    chat: TaskConfig
    identify_name:TaskConfig




