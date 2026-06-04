from __future__ import annotations
import json
import time
import warnings
from inspect import isclass
from pathlib import Path
from typing import Any, TypeVar
from collections.abc import Callable
from openai import OpenAI
from src.models.structuredOutputModel import StructuredOutputModel
from src.openai.build_text_format import build_text_format
from src.openai.valid_format import ValidTextFormat
T = TypeVar("T")

class OpenAITask:
    openai_client: OpenAI
    model: str
    instructions: str
    user: str
    timeout: int
    text_format: ValidTextFormat
    response: Any

    def __init__(self,api_key: str,*,user: str = None,task_config: dict[str, Any],timeout: int = None) -> None:
        self.openai_client = OpenAI(api_key=api_key)
        self.user = user if user is not None else ""
        self.timeout = timeout if timeout is not None else 2000

        self._load_task_config(task_config)


    def run(self,user:str = None) -> Any:
        if user is None:
            user = self.user

        if not user.strip():
            raise ValueError("User input must be provided")

        if self._uses_create_api():
            self.response = self.openai_client.responses.create(
                model=self.model,
                input=user,
                instructions=self.instructions,
                text={"format": build_text_format(self.text_format)},
                timeout=self.timeout,
            )

            return self.parse_create_output(self.response.output_text)

        if self._uses_parse_api():
            self.response = self.openai_client.responses.parse(
                model=self.model,
                input=user,
                instructions=self.instructions,
                text_format=self._get_parse_text_format(),
                timeout=self.timeout,
            )
            return self.response.output_parsed.model_dump()
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

    @staticmethod
    def run_with_retry(function: Callable[..., T], *args, max_retries: int = 3, base_delay: int = 2) -> T:
        for attempt in range(1, max_retries + 2):
            try:
                return function(*args)

            except Exception as error:
                if attempt > max_retries:
                    raise RuntimeError(f"Stage {function.__name__} failed") from error

                delay = base_delay * 2 ** (attempt - 1)

                warnings.warn(f"Stage {function.__name__} failed at attempt {attempt}/{max_retries + 1}",
                              RuntimeWarning, stacklevel=2)
                time.sleep(delay)
        raise RuntimeError(f"{function.__name__} failed")

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

def _load_text_format(task_config: dict[str, Any]) -> ValidTextFormat:
    text_format = task_config.get("text_format")
    if not text_format:
        return "text"
    return text_format







