from __future__ import annotations

import os
from dotenv import load_dotenv
from pathlib import Path
from dataclasses import dataclass

@dataclass(frozen=True)
class BaseProjectPath:
    root_path: Path
    input_path: Path
    output_path: Path
    prompt_path: Path
    src_dir: Path
    env_path: Path
    tests_dir: Path

class BaseConfig:
    project_path: BaseProjectPath

    def __init__(self,project_path:BaseProjectPath) -> None:
        self.project_path = project_path
        load_dotenv(dotenv_path=self.project_path.env_path)

    def get_apikey(self,option: str) -> str:
        option = option.lower().strip()

        match option:
            case "openai":
                api_key = os.getenv("OPENAI_API_KEY", "").strip()
            case "mistral":
                api_key = os.getenv("MISTRALAI_API_KEY", "").strip()
            case _:
                raise ValueError("Input must be one of: openai | mistral")

        if not api_key:
            raise ValueError(f"No API key found: {option}")

        return api_key