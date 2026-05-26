from __future__ import annotations

import os
from dotenv import load_dotenv
from pathlib import Path
from dataclasses import dataclass


def _build_openai_task_config(prompt_path:Path)->OpenaiConfig:
    task:dict[str, dict] ={}

    task["classify_pages"] = {
        "model": "gpt-5-mini",
        "prompt_path": prompt_path/"prompt_classifyPages.txt",
        "text_format": "",
        "max_output_tokens": 2000,
    }
    task["verify_reg_sum_pages"] = {
        "model": "gpt-5-mini",
        "prompt_path": prompt_path/"prompt_verifyRegSumPages.txt",
        "text_format": "text",
        "max_output_tokens": 1000,
    }

    task["verify_reg_pages"] = {
        "model": "gpt-5-mini",
        "prompt_path": prompt_path/"prompt_verifyRegPages.txt",
        "text_format": "text",
        "max_output_tokens": 1000,
    }

    task["add_page_description"] = {
        "model": "gpt-5-mini",
        "prompt_path": prompt_path/"prompt_addPageDescription.txt",
        "text_format": "",
        "max_output_tokens": 2000,
    }

    task["extract_reg_index"] = {
        "model": "gpt-5-mini",
        "prompt_path": prompt_path/"prompt_extractRegIndex.txt",
        "text_format": "",
    }

    task["extract_reg_map"] = {
        "model": "gpt-5-mini",
        "prompt_path": prompt_path/"prompt_extractRegMap.txt",
        "text_format": "",
    }

    return OpenaiConfig(task=task)

def _build_mistral_task_config()->MistralConfig:
    task:dict[str, dict] = {}
    task["ocr"] = {
        "model": "mistral-ocr-latest",
        "table_format": "html",
        "include_image": True,
    }

    return MistralConfig(task=task)

@dataclass(frozen=True)
class ProjectPath:
    root_path: Path
    pdf_path: Path
    input_path: Path
    output_path: Path
    prompt_path: Path
    src_dir: Path
    env_path: Path
    tests_dir: Path

@dataclass(frozen=True)
class OpenaiConfig:
    task:dict[str, dict]

@dataclass(frozen=True)
class MistralConfig:
    task:dict[str, dict]

class Config:
    project_path: ProjectPath
    openai: OpenaiConfig
    mistral: MistralConfig

    def __init__(self,project_path:ProjectPath,openai_config:OpenaiConfig,mistral_config:MistralConfig):
        self.project_path = project_path
        self.openai = openai_config
        self.mistral = mistral_config
        self.load_env()

    @classmethod
    def load_config(cls,pdf:str|Path,env:str|Path="",) -> "Config":
        pdf = Path(pdf).resolve()
        if not pdf.is_file():
            raise FileNotFoundError(f"No such PDF file: {pdf}")
        root_path = Path(__file__).resolve().parents[1]

        if isinstance(env,str):
            if len(env.strip()) == 0:
                env = root_path / ".env"
                if not env.is_file():
                    raise FileNotFoundError(f"No env file input, must provide an env path or at default path: {env}")
            else:
                env=Path(env).resolve()

        if not env.is_file():
            raise FileNotFoundError(f"No such .env file: {env}")

        env_path = env

        project_path = ProjectPath(
            root_path=root_path,
            pdf_path=pdf,
            input_path=root_path /"data"/ "input",
            output_path=root_path /"data"/ "output",
            prompt_path=root_path / "prompts",
            src_dir=root_path / "src",
            env_path=env_path,
            tests_dir=root_path / "tests",
        )


        return cls(
            project_path = project_path,
            openai_config = _build_openai_task_config(project_path.prompt_path),
            mistral_config = _build_mistral_task_config(),
        )

    def load_env(self):
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