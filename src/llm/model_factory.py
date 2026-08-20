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
                temperature=temperature if temperature is not None else None,
                max_tokens= max_output_tokens,
                reasoning_effort=thinking_effort,
                use_responses_api=True,
            )

        case "anthropic":
            if not api_key:
                raise ValueError("Anthropic API key is required for provider='anthropic'.")

            model_kwargs = {
                "model_name": model_name,
                "api_key": api_key,
                "max_tokens_to_sample": max_output_tokens,
            }

            if thinking_effort is not None:
                model_kwargs["thinking"] = {"type": "adaptive"}
                model_kwargs["effort"] = thinking_effort

            return ChatAnthropic(**model_kwargs)

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

            return ChatOpenAI(
                model=model_name,
                api_key=api_key,
                base_url="https://api.moonshot.ai/v1",
                max_tokens= max_output_tokens,
                reasoning_effort=thinking_effort,
            )

        case "zai":
            if not api_key:
                raise ValueError(
                    "ZAI API key is required for provider='zai'."
                )

            extra_body = {}

            if thinking_effort is not None:
                extra_body["thinking"] = {
                    "type": "enabled",
                }

                if model_name == "glm-5.2":
                    extra_body["reasoning_effort"] = thinking_effort

            return ChatOpenAI(
                model=model_name,
                api_key=api_key,
                base_url="https://api.z.ai/api/paas/v4/",
                temperature=temperature if temperature is not None else None,
                max_tokens=max_output_tokens,
                extra_body=extra_body or None,
            )

        case "ollama":
            return ChatOllama(
                model=model_name,
                temperature=temperature if temperature is not None else None,
                num_predict=max_output_tokens,
            )
        case _:
            raise ValueError(f"Unsupported LLM provider: {provider}")