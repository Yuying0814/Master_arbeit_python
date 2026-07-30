from __future__ import annotations

import json
import math
from dataclasses import dataclass, field
from pathlib import Path
from typing import Any

from src.llm.common.types import ThinkingEffort, ValidOutputFormat


@dataclass
class GlmBatchInputFile:
    path: Path
    input_file_id: str = ""
    JSONLs: list[dict[str, Any]] = field(default_factory=list)
    custom_ids: list[str] = field(default_factory=list)

    def add_one_JSONL(
        self,
        custom_id: str,
        user: str,
        *,
        model: str | None = None,
        instructions: str | None = None,
        thinking_effort: ThinkingEffort = None,
        temperature: float | None = None,
        output_format: ValidOutputFormat,
        max_output_tokens: int = 5000,
    ) -> None:

        model = model or "glm-4-flash"
        instructions = instructions or "You are a helpful assistant."

        if custom_id in self.custom_ids:
            raise ValueError(
                f"Duplicate custom_id in one batch: {custom_id}"
            )

        if not isinstance(user, str) or not user.strip():
            raise ValueError("User input must be a non-empty string.")

        if not isinstance(instructions, str):
            raise TypeError("instructions must be a string.")

        if  max_output_tokens <= 0:
            raise TypeError(
                "max_output_tokens must be a positive integer."
            )

        if temperature is not None:

            if not math.isfinite(temperature)or not 0.0 <= temperature <= 1.0:
                raise ValueError(
                    "temperature must be between 0.0 and 1.0."
                )

        system = instructions.strip()
        output_schema = (
            None
            if output_format in {None, "text"}
            else output_format.model_json_schema()
        )

        body: dict[str, Any] = {
            "model": model,
            "messages": [
                {
                    "role": "system",
                    "content": system,
                },
                {
                    "role": "user",
                    "content": user,
                },
            ],
            "max_tokens": max_output_tokens,
            "stream": False,
        }

        if temperature is not None:
            body["temperature"] = temperature

        if thinking_effort is not None:
            body["thinking"] = {"type": "enabled"}
            body["reasoning_effort"] = thinking_effort

        if output_schema is not None:
            body["response_format"] = {"type": "json_object"}
            body["messages"][0]["content"] = (
                f"{system}\n\n"
                "Return only one JSON object that conforms to the "
                "following JSON Schema:\n"
                f"{json.dumps(output_schema, ensure_ascii=False)}"
            )

        self.JSONLs.append(
            {
                "custom_id": custom_id,
                "method": "POST",
                "url": "/v4/chat/completions",
                "body": body,
            }
        )
        self.custom_ids.append(custom_id)

    def add_multiple_JSONLs(
        self,
        custom_ids: list[str],
        users: list[str],
        *,
        model: str | None = None,
        instructions: str | None = None,
        thinking_effort: ThinkingEffort = None,
        temperature: float | None = None,
        output_format: ValidOutputFormat,
        max_output_tokens: int,
    ) -> None:
        if not custom_ids or not users:
            raise ValueError(
                "custom_ids and user inputs must not be empty."
            )

        if len(custom_ids) != len(users):
            raise ValueError(
                "custom_ids and user inputs must have the same length."
            )

        for custom_id, user in zip(custom_ids, users):
            self.add_one_JSONL(
                custom_id=custom_id,
                user=user,
                model=model,
                instructions=instructions,
                thinking_effort=thinking_effort,
                temperature=temperature,
                output_format=output_format,
                max_output_tokens=max_output_tokens,
            )

    def write_to_file(self) -> None:
        self.path.parent.mkdir(parents=True, exist_ok=True)

        with self.path.open("w", encoding="utf-8") as file:
            for item in self.JSONLs:
                file.write(
                    json.dumps(item, ensure_ascii=False) + "\n"
                )

    def reset_JSONLs(self) -> None:
        self.input_file_id = ""
        self.JSONLs.clear()
        self.custom_ids.clear()