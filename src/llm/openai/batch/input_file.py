from __future__ import annotations
import json
import math
from dataclasses import dataclass,field
from pathlib import Path
from typing import Any

from src.models.structuredOutputModel import StructuredOutputModel
from src.llm.common.types import ValidOutputFormat,ThinkingEffort

@dataclass
class OpenaiBatchInputFile:
    path:Path
    JSONLs:list[dict] = field(default_factory=list)
    custom_ids: list[str] = field(default_factory=list)

    def add_one_JSONL(
            self,
            custom_id: str,
            user: str,
            *,
            model: str | None = None,
            instructions: str | None = None,
            thinking_effort: ThinkingEffort = None,
            temperature: float|None = None,
            output_format: ValidOutputFormat,
            max_output_tokens: int | None = None,
    ) -> None:
        body: dict = {}

        if model is None:
            model =  "gpt-5-mini"

        if not isinstance(model, str):
            raise TypeError("model must be a str")

        if instructions is None:
            instructions = "You are a helpful assistant."

        if not isinstance(instructions, str):
            raise TypeError("instructions must be a str")

        if max_output_tokens is None:
            max_output_tokens = 500

        if (
                not isinstance(max_output_tokens, int)
                or isinstance(max_output_tokens, bool)
                or max_output_tokens <= 0
        ):
            raise TypeError("max_output_tokens must be a positive integer")

        body["model"] = model
        body["input"] = user
        body["instructions"] = instructions
        body["text"] = {
            "format":_build_format_value(output_format)
        }

        body["max_output_tokens"] = max_output_tokens

        if temperature is not None:
            if not math.isfinite(temperature) or not 0.0 <= temperature <= 2.0:
                raise ValueError("temperature must be between 0.0 and 2.0.")
            body["temperature"] = temperature

        if thinking_effort is not None:
            body["reasoning"] = {
                "effort": thinking_effort,
            }

        JSONL = {
            "custom_id": custom_id,
            "method": "POST",
            "url":"/v1/responses",
            "body": body,
        }

        if custom_id in self.custom_ids:
            raise ValueError(f"Duplicate custom_id in one batch: {custom_id}")
        self.JSONLs.append(JSONL)
        self.custom_ids.append(custom_id)

    def add_multiple_JSONLs(self,custom_ids:list[str],users:list[str],
                            *,
                            model: str | None = None,
                            instructions: str | None = None,
                            thinking_effort:ThinkingEffort = None,
                            temperature:float|None = None,
                            output_format: ValidOutputFormat,
                            max_output_tokens: int | None = None,
                            ) -> None:

        if len(custom_ids) == 0 or len(users) == 0:
            raise ValueError("custom ids and user prompt must not be empty ")

        if len(custom_ids) != len(users):
            raise ValueError(f"custom_ids and user prompt must have the same length")

        for custom_id,user in zip(custom_ids,users):
            self.add_one_JSONL(
                custom_id=custom_id,
                user=user,
                model=model,
                instructions=instructions,
                thinking_effort=thinking_effort,
                temperature = temperature,
                output_format=output_format,
                max_output_tokens=max_output_tokens,
            )

    def write_to_file(self) -> None:
        with self.path.open("w",encoding="utf-8") as file:
            for item in self.JSONLs:
                text = json.dumps(item,ensure_ascii=False)+"\n"
                file.write(text)

    def reset_JSONLs(self) -> None:
        self.JSONLs.clear()
        self.custom_ids.clear()

# Helper
def _build_format_value(output_format: ValidOutputFormat) -> dict[str, Any]:
    if isinstance(output_format, type) and issubclass(output_format, StructuredOutputModel):
        return {
            "type": "json_schema",
            "name": output_format.__name__,
            "strict": True,
            "schema": output_format.model_json_schema(),
        }
    else:
        return {
            "type": "text"
        }




