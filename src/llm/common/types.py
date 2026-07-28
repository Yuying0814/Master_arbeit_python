from typing import TypeAlias, Literal
from src.models.structuredOutputModel import StructuredOutputModel

ValidOutputFormat: TypeAlias = type[StructuredOutputModel] | None | Literal["text"]

LLMProvider = Literal["openai", "ollama", "anthropic", "google"]

ThinkingEffort = Literal["low","medium","high","xhigh","max"] | None