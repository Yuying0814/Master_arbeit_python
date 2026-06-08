from __future__ import annotations
import json
from dataclasses import dataclass,field
from pathlib import Path
from src.openai.build_text_format import build_text_format
from src.utils.build_json_schema import build_tools_schema

@dataclass
class BatchInputFile:
    path:Path
    JSONLs:list[dict] = field(default_factory=list)
    custom_ids: list[str] = field(default_factory=list)

    def add_one_JSONL(self, custom_id:str, user:str, model:str = None, instructions:str = None,
                      text_format:str = None, max_output_tokens:int = None,):
        body: dict = {}

        if model is None:
            model =  "gpt-5-mini"

        if instructions is None:
            instructions = "You are a helpful assistance"

        if text_format is None:
            text_format = "text"

        if max_output_tokens is None:
            max_output_tokens = 500


        body["model"] = model
        body["input"] = user
        body["instructions"] = instructions
        body["text_format"] = text_format
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

    def add_multiple_JSONLs(self,custom_ids:list[str],users:list[str],**opts):
        if len(custom_ids) == 0 or len(users) == 0:
            raise ValueError("custom ids and user prompt must not be empty ")

        if len(custom_ids) != len(users):
            raise ValueError(f"custom_ids and user prompt must have the same length")
        for custom_id,user in zip(custom_ids,users):
            self.add_one_JSONL(custom_id=custom_id,user=user,**opts)

    def write_to_file(self):
        with self.path.open("w",encoding="utf-8") as file:
            for item in self.JSONLs:
                text = json.dumps(item,ensure_ascii=False)+"\n"
                file.write(text)

    def reset_JSONLs(self):
        self.JSONLs.clear()
        self.custom_ids.clear()



