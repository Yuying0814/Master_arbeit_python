from __future__ import annotations

from langchain_core.language_models.chat_models import BaseChatModel
from langchain_openai import ChatOpenAI
from langchain_ollama import ChatOllama
from langchain_anthropic import ChatAnthropic
from langchain_google_genai import ChatGoogleGenerativeAI
from langchain_moonshot import ChatMoonshot

from src.llm.common.types import LLMProvider,ThinkingEffort


def build_chat_model(
    *,
    provider: LLMProvider,
    model_name: str,
    api_key: str | None = None,
    thinking_effort:ThinkingEffort = None,
    temperature: float|None = None,
    max_output_tokens: int|None = None,
) -> BaseChatModel:

    if max_output_tokens is None:
        max_output_tokens = 4000

    match provider:
        case "openai":
            if not api_key:
                raise ValueError("OpenAI API key is required for provider='openai'.")

            return ChatOpenAI(
                model=model_name,
                api_key=api_key,
                temperature=temperature,
                max_tokens= max_output_tokens,
                reasoning_effort=thinking_effort,
            )

        case "anthropic":
            if not api_key:
                raise ValueError("Anthropic API key is required for provider='anthropic'.")

            return ChatAnthropic(
                model_name=model_name,
                api_key=api_key,
                max_tokens_to_sample= max_output_tokens,
                thinking = {
                    "type":"adaptive"
                },
                effort=thinking_effort,
            )

        case "google":
            if not api_key:
                raise ValueError("Google API key is required for provider='google'")
            return ChatGoogleGenerativeAI(
                model=model_name,
                api_key=api_key,
                max_tokens=max_output_tokens,
                thinking_level = thinking_effort,
            )

        case "kimi":
            if not api_key:
                raise ValueError("Kimi API key is required for provider='kimi'")
            return ChatMoonshot(
                model=model_name,
                api_key=api_key,
                thinking=True if model_name == "kimi-k2.5" else None,
                temperature=1.0 if model_name == "kimi-k2.5" else None,
                max_completion_tokens=max_output_tokens,
                reasoning_effort=thinking_effort if model_name=="kimi-k3" else None,
            )

        case "ollama":
            return ChatOllama(
                model=model_name,
                temperature=temperature,
                num_predict=max_output_tokens,
            )
        case _:
            raise ValueError(f"Unsupported LLM provider: {provider}")