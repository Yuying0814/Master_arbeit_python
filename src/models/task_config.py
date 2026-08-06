from __future__ import annotations

from dataclasses import dataclass
from pydantic import BaseModel, Field
from typing import Literal

from src.llm.common.types import ValidOutputFormat,LLMProvider,ThinkingEffort

class ModelConfig(BaseModel):
    provider:LLMProvider = "openai"
    is_batch: bool = False
    model_name:str = "gpt-5-mini"
    thinking_effort: ThinkingEffort = None
    temperature:float|None = None
    max_tokens:int = 4000

class TaskConfig(BaseModel):
    model: ModelConfig = Field(default_factory=ModelConfig)
    system: str = "You are a helpful assistant"
    output_format: ValidOutputFormat = None
    memory_enabled: bool = False

class CodingTaskConfigs(BaseModel):
    retrieval: TaskConfig
    planning:TaskConfig
    coding:TaskConfig
    verification_semantic:TaskConfig
    verification_test_coder:TaskConfig

@dataclass(frozen=True)
class PreprocessingTaskConfigs:
    classify_pages:TaskConfig
    verify_reg_sum_pages:TaskConfig
    verify_reg_pages:TaskConfig
    add_page_description:TaskConfig
    extract_reg_index:TaskConfig
    extract_reg_map:TaskConfig

@dataclass(frozen=True)
class MistralConfig:
    task:dict[str, dict]

class OcrConfig(BaseModel):
    provider: Literal["mistral","glm"]
    model_name: str
    include_image: bool = True
    table_format: Literal["html","markdown"] = "html"
    url:str = "http://localhost:11434"
    layout_device:str = "cpu"
    connection_poor_size: int = 1
    max_workers: int = 1
    batch_size: int = 1