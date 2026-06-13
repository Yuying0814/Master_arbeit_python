from __future__ import annotations

from typing import Any
from langchain_core.language_models.chat_models import BaseChatModel
from pydantic import BaseModel

from src.models.batch import UserRequest
from src.models.task_config import TaskConfig
from src.llm.model_factory import build_chat_model
from src.llm.common.common import HasLangChainResultParser,ValidOutputFormat


class LLMTaskProcessor(HasLangChainResultParser):
    user_input: str

    def __init__(
        self,
        *,
        model: BaseChatModel,
        system: str,
        output_format: ValidOutputFormat = "text",
    ) -> None:
        self.model = model
        self.system = system
        self.output_format = output_format
        self.user_input = ""

    @classmethod
    def load_from_task_config(cls, task_config:TaskConfig, api_key:str = None) -> "LLMTaskProcessor":

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

    async def run(self) -> Any:
        if not self._has_valid_user_input():
            raise ValueError("User input must be provided.")

        messages = [
            ("system", self.system),
            ("human", self.user_input),
        ]

        if self._is_structured_format(self.output_format):
            structured_model = self.model.with_structured_output(self.output_format)
            result = await structured_model.ainvoke(messages)

            if isinstance(result, BaseModel):
                return result.model_dump()

            return result
        
        response = await self.model.ainvoke(messages)

        if self.output_format == "json":
            return self._parse_json(response.content)

        if self.output_format == "text":
            return response.content

        raise ValueError(f"Unsupported text_format: {self.output_format}")

    def add_user_inputs(self, user_input: str | list[UserRequest]) -> None:
        if not isinstance(user_input, str):
            raise ValueError("LLMTaskProcessor expects a single string input.")
        self.user_input = user_input

    def _has_valid_user_input(self) -> bool:
        return len(self.user_input.strip()) > 0
