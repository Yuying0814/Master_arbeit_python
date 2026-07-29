from __future__ import annotations
from pathlib import Path
from dataclasses import dataclass

from src.config import BaseConfig, BaseProjectPath
from src.models.page_output import PageClassification,PageDescription
from src.models.register_output import RegisterIndexOutput,RegisterMapOutput
from src.models.task_config import TaskConfig,ModelConfig,PreprocessingTaskConfigs,MistralConfig

@dataclass(frozen=True)
class ProjectPath(BaseProjectPath):
    pdf_path: Path

class PreprocessingConfig(BaseConfig):
    project_path: ProjectPath
    task_configs: PreprocessingTaskConfigs
    mistral: MistralConfig

    def __init__(self, project_path:ProjectPath, preprocessing_task_configs:PreprocessingTaskConfigs, mistral_config:MistralConfig) -> None:
        super().__init__(project_path)
        self.task_configs = preprocessing_task_configs
        self.mistral = mistral_config

    @classmethod
    def load_config(cls,pdf:str|Path,env:str|Path="") -> "PreprocessingConfig":
        pdf = Path(pdf).resolve()
        if not pdf.is_file():
            raise FileNotFoundError(f"No such PDF file: {pdf}")
        root_path = Path(__file__).resolve().parents[2]

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
            preprocessing_task_configs = _build_preprocessing_task_configs(project_path.prompt_path),
            mistral_config = _build_mistral_task_config(project_path.pdf_path),
        )

def _build_preprocessing_task_configs(prompt_path:Path) -> PreprocessingTaskConfigs:
    classify_pages = TaskConfig(
        model = ModelConfig(
            provider = "openai",
            is_batch=True,
            model_name="gpt-5-mini",
            thinking_effort="medium",
            temperature=None,
            max_tokens=2000,
        ),
        system = _read_instructions(prompt_path/"prompt_classifyPages.txt"),
        output_format = PageClassification,
    )

    verify_reg_sum_pages = TaskConfig(
        model = ModelConfig(
            provider = "openai",
            is_batch=True,
            model_name="gpt-5-mini",
            thinking_effort="medium",
            temperature=None,
            max_tokens=1000,
        ),
        system = _read_instructions(prompt_path/"prompt_verifyRegSumPages.txt"),
        output_format = "text",
    )

    verify_reg_pages = TaskConfig(
        model = ModelConfig(
            provider = "openai",
            is_batch=True,
            model_name="gpt-5-mini",
            thinking_effort="medium",
            temperature=None,
            max_tokens=2000,
        ),
        system = _read_instructions(prompt_path/"prompt_verifyRegPages.txt"),
        output_format = "text",
    )

    add_page_description = TaskConfig(
        model = ModelConfig(
            provider = "openai",
            model_name="gpt-5-mini",
            is_batch=True,
            thinking_effort="medium",
            temperature=None,
            max_tokens=2000,
        ),

        system = _read_instructions(prompt_path/"prompt_addPageDescription.txt"),
        output_format = PageDescription,
    )

    extract_reg_index = TaskConfig(
        model = ModelConfig(
            provider = "openai",
            model_name="gpt-5-mini",
            is_batch=False,
            thinking_effort="medium",
            temperature=None,
            max_tokens=2000,
        ),
        system = _read_instructions(prompt_path/"prompt_extractRegIndex.txt"),
        output_format = RegisterIndexOutput,
    )

    extract_reg_map = TaskConfig(
        model = ModelConfig(
            provider = "openai",
            model_name="gpt-5-mini",
            is_batch=False,
            thinking_effort="medium",
            temperature=None,
            max_tokens=2000,
        ),
        system = _read_instructions(prompt_path/"prompt_extractRegMap.txt"),
        output_format = RegisterMapOutput,
    )
    return PreprocessingTaskConfigs(
        classify_pages = classify_pages,
        verify_reg_sum_pages = verify_reg_sum_pages,
        verify_reg_pages = verify_reg_pages,
        add_page_description = add_page_description,
        extract_reg_index = extract_reg_index,
        extract_reg_map = extract_reg_map,
    )

def _read_instructions(prompt_path:str|Path|None) -> str:
    if not prompt_path:
        return "You are a helpful assistant."

    prompt_path = Path(prompt_path)
    return Path(prompt_path).read_text(encoding="utf-8")

def _build_mistral_task_config(pdf_path:Path)->MistralConfig:
    task:dict[str, dict] = {}
    task["ocr"] = {
        "file_path": pdf_path,
        "model_name": "mistral-ocr-latest",
        "table_format": "html",
        "include_image": True,
    }

    return MistralConfig(task=task)