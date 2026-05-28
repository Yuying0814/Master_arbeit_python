from __future__ import annotations
import json
from inspect import isclass
from pathlib import Path
from typing import Any, TypeAlias
from openai import OpenAI
from src.models.structuredOutputModel import StructuredOutputModel
from src.openai.build_text_format import build_text_format
from src.openai.valid_format import ValidTextFormat


class OpenAITask:
    openai_client: OpenAI
    model: str
    instructions: str
    user: str
    timeout: int
    text_format: ValidTextFormat
    response: Any

    def __init__(self,api_key: str,user: str,task_config: dict[str, Any],timeout: int = 3000) -> None:
        self.openai_client = OpenAI(api_key=api_key)
        self.user = user
        self._load_task_config(task_config)
        self.timeout = timeout


    def run(self) -> Any:
        if self._uses_create_api():
            self.response = self.openai_client.responses.create(
                model=self.model,
                input=self.user,
                instructions=self.instructions,
                text={"format": build_text_format(self.text_format)},
                timeout=self.timeout,
            )

            return self.parse_create_output(self.response.output_text)

        if self._uses_parse_api():
            self.response = self.openai_client.responses.parse(
                model=self.model,
                input=self.user,
                instructions=self.instructions,
                text_format=self._get_parse_text_format(),
                timeout=self.timeout,
            )
            return self.response.output_parsed
        raise TypeError(
            "Invalid text_format. Expected 'text', 'json', dict, "
            "StructuredOutputModel class, or StructuredOutputModel instance."
        )

    def _uses_create_api(self) -> bool:
        return isinstance(self.text_format, str) or isinstance(self.text_format, dict)

    def _uses_parse_api(self) -> bool:
        return isinstance(self.text_format, StructuredOutputModel) or (isclass(self.text_format)
            and issubclass(self.text_format, StructuredOutputModel))

    def _get_parse_text_format(self) -> type[StructuredOutputModel]:
        if isinstance(self.text_format, StructuredOutputModel):
            return self.text_format.__class__

        if isclass(self.text_format) and issubclass(self.text_format,StructuredOutputModel,):
            return self.text_format

        raise TypeError("text_format is not a valid StructuredOutputModel.")

    def _load_task_config(self, task_config: dict[str, Any]) -> None:
        self.model = _load_model(task_config)
        self.instructions = _load_instructions(task_config)
        self.text_format = _load_text_format(task_config)

    @staticmethod
    def  parse_create_output(output):
        try:
            return json.loads(output)
        except json.JSONDecodeError:
            return output


def _load_model(task_config: dict[str, Any]) -> str:
    model = task_config.get("model")
    if not model:
        return "gpt-5-mini"
    return model

def _load_instructions(task_config: dict[str, Any]) -> str:
    prompt_path = task_config.get("prompt_path")
    if not prompt_path:
        return "You are a helpful assistant."
    return Path(prompt_path).read_text(encoding="utf-8")

def _load_text_format(task_config: dict[str, Any]) -> str:
    text_format = task_config.get("text_format")
    if not text_format:
        return "text"
    return text_format







