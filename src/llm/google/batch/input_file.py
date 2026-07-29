from __future__ import annotations

import json
import math
from dataclasses import dataclass, field
from pathlib import Path
from typing import Any

from src.llm.common.batch_utils import get_output_schema
from src.llm.common.types import ValidOutputFormat,ThinkingEffort


@dataclass
class GeminiBatchInputFile:
    path: Path
    JSONLs: list[dict[str, Any]] = field(default_factory=list)
    custom_ids: list[str] = field(default_factory=list)
    remote_file_name: str | None = None

    def add_one_JSONL(
        self,
        custom_id: str,
        user: str,
        *,
        system: str,
        output_format: ValidOutputFormat,
        thinking_effort:ThinkingEffort,
        max_output_tokens: int,

        temperature: float,
    ) -> None:

        if custom_id in self.custom_ids:
            raise ValueError(f"Duplicate custom_id in one batch: {custom_id}")

        if not user.strip():
            raise ValueError("User input must not be empty.")

        if not math.isfinite(temperature) or not 0.0 <= temperature <= 2.0:
            raise ValueError("temperature must be between 0.0 and 2.0.")

        if not system.strip():
            system = "You are a helpful assistant."

        generation_config: dict[str, Any] = {
            "maxOutputTokens": max_output_tokens,
            "temperature": temperature,
        }

        if thinking_effort is not None:
            generation_config["thinking_config"] = {
                "thinking_level": thinking_effort,
            }

        output_schema = get_output_schema(output_format)

        if output_schema is not None:
            generation_config.update(
                {
                    "response_mime_type": "application/json",
                    "response_json_schema": output_schema,
                }
            )

        request: dict[str, Any] = {
            "contents": [
                {
                    "role": "user",
                    "parts": [{"text": user}],
                }
            ],
            "generation_config": generation_config,
        }

        request["system_instruction"] = {
                "parts": [{"text": system}],
        }

        self.JSONLs.append(
            {
                "key": custom_id,
                "request": request,
            }
        )
        self.custom_ids.append(custom_id)

    def add_multiple_JSONLs(
        self,
        custom_ids: list[str],
        users: list[str],
        *,
        system: str,
        output_format: ValidOutputFormat,
        max_output_tokens: int,
        thinking_effort: ThinkingEffort,
        temperature: float,
    ) -> None:
        if not custom_ids or not users:
            raise ValueError("Custom ids and user inputs must not be empty.")

        if len(custom_ids) != len(users):
            raise ValueError(
                "custom_ids and user inputs must have the same length."
            )

        for custom_id, user in zip(custom_ids, users):
            self.add_one_JSONL(
                custom_id=custom_id,
                user=user,
                system=system,
                output_format=output_format,
                max_output_tokens=max_output_tokens,
                thinking_effort=thinking_effort,
                temperature=temperature
            )

    def write_to_file(self) -> None:
        self.path.parent.mkdir(parents=True, exist_ok=True)

        with self.path.open("w", encoding="utf-8") as file:
            for record in self.JSONLs:
                file.write(json.dumps(record, ensure_ascii=False) + "\n")

    def reset_jsonls(self) -> None:
        self.JSONLs.clear()
        self.custom_ids.clear()
        self.remote_file_name = None
