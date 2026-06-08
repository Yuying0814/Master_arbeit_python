from __future__ import annotations

from typing import Literal

from langchain_core.language_models.chat_models import BaseChatModel
from langchain_openai import ChatOpenAI
from langchain_ollama import ChatOllama


LLMProvider = Literal["openai", "ollama"]


def build_chat_model(
    *,
    provider: LLMProvider,
    model_name: str,
    api_key: str | None = None,
    temperature: float = 0.0,
    max_output_tokens: int|None = None,
    use_responses_api: bool = True
) -> BaseChatModel:

    if max_output_tokens is None:
        max_output_tokens = 4000

    if provider == "openai":
        if not api_key:
            raise ValueError("OpenAI API key is required for provider='openai'.")

        return ChatOpenAI(
            model=model_name,
            api_key=api_key,
            temperature=temperature,
            max_tokens= max_output_tokens,
            use_responses_api= use_responses_api,
        )

    if provider == "ollama":
        return ChatOllama(
            model=model_name,
            temperature=temperature,
            num_predict=max_output_tokens,
        )

    raise ValueError(f"Unsupported LLM provider: {provider}")