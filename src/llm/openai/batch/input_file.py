from __future__ import annotations
import json
from dataclasses import dataclass,field
from pathlib import Path
from src.llm.common.common import ValidOutputFormat
from src.llm.openai.build_text_format import build_text_format

@dataclass
class BatchInputFile:
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
            text_format: ValidOutputFormat | None = None,
            max_output_tokens: int | None = None,
            name: str | None = None,
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

        if text_format is None:
            text_format = "text"

        if max_output_tokens is None:
            max_output_tokens = 500

        if (
                not isinstance(max_output_tokens, int)
                or isinstance(max_output_tokens, bool)
                or max_output_tokens <= 0
        ):
            raise TypeError("max_output_tokens must be a positive integer")

        text_format_args = (text_format,)

        if name is not None:
            if not isinstance(name, str):
                raise TypeError("name must be a str")

            if len(name.strip()) > 0:
                text_format_args += (name,)


        body["model"] = model
        body["input"] = user
        body["instructions"] = instructions
        body["text"] = {"format": build_text_format(*text_format_args)}
        body["max_output_tokens"] = max_output_tokens

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
                            text_format: ValidOutputFormat | None = None,
                            max_output_tokens: int | None = None,
                            name: str | None = None,) -> None:

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
                text_format=text_format,
                max_output_tokens=max_output_tokens,
                name=name
            )

    def write_to_file(self) -> None:
        with self.path.open("w",encoding="utf-8") as file:
            for item in self.JSONLs:
                text = json.dumps(item,ensure_ascii=False)+"\n"
                file.write(text)

    def reset_JSONLs(self) -> None:
        self.JSONLs.clear()
        self.custom_ids.clear()



