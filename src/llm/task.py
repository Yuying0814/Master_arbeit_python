from __future__ import annotations

import json
from typing import Any
from langchain_core.language_models.chat_models import BaseChatModel
from pydantic import BaseModel

from src.llm.model_factory import build_chat_model
from src.models.task_config import TaskConfig


class LLMTask:

    def __init__(
        self,
        *,
        model: BaseChatModel,
        system: str,
        output_format: type[BaseModel] | str | dict[str, Any] = "text",
    ) -> None:
        self.model = model
        self.system = system
        self.output_format = output_format

    @ classmethod
    def load_from_task_config(cls,api_key:str, task_config:TaskConfig) -> LLMTask:

        model = build_chat_model(
            api_key=api_key,
            provider=task_config.model.provider,
            model_name=task_config.model.model_name,
            temperature=task_config.model.temperature,
            max_output_tokens=task_config.model.max_tokens,
        )

        return cls(
            model=model,
            system=task_config.system,
            output_format=task_config.output_format,
        )

    def run(self, user_input: str) -> Any:
        if not user_input.strip():
            raise ValueError("User input must be provided.")

        messages = [
            ("system", self.system),
            ("human", user_input),
        ]

        if self._is_structured_format(self.output_format):
            structured_model = self.model.with_structured_output(self.output_format)
            result = structured_model.invoke(messages)

            if isinstance(result, BaseModel):
                return result.model_dump()

            return result
        
        response = self.model.invoke(messages)

        if self.output_format == "json":
            return self._parse_json(response.content)

        if self.output_format == "text":
            return response.content

        raise ValueError(f"Unsupported text_format: {self.output_format}")

    @staticmethod
    def _parse_json(content: str) -> Any:
        try:
            return json.loads(content)
        except json.JSONDecodeError as error:
            raise ValueError("Model output is not valid JSON.") from error

    @staticmethod
    def _is_structured_format(text_format: Any) -> bool:
        if isinstance(text_format, dict):
            return True

        return isinstance(text_format, type) and issubclass(text_format, BaseModel)