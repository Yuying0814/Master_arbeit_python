from __future__ import annotations

from pathlib import Path

from pydantic.dataclasses import dataclass

from src.config import BaseConfig, BaseProjectPath
from src.models.page_output import PageClassification, PageDescription
from src.models.register_output import RegisterIndexOutput, RegisterMapOutput
from src.models.task_config import ModelConfig,OcrConfig,PreprocessingTaskConfigs,TaskConfig


class PreprocessingConfig(BaseConfig):
    task_configs: PreprocessingTaskConfigs
    ocr: OcrConfig

    def __init__(
        self,
        project_path: BaseProjectPath,
        preprocessing_task_configs: PreprocessingTaskConfigs,
        ocr_config: OcrConfig,
    ) -> None:
        super().__init__(project_path)
        self.task_configs = preprocessing_task_configs
        self.ocr = ocr_config

    @classmethod
    def load_config(
        cls,
        pdf: str | Path = "",
        env: str | Path = "",
    ) -> "PreprocessingConfig":

        root_path = Path(__file__).resolve().parents[2]

        if isinstance(env, str):
            if len(env.strip()) == 0:
                env = root_path / ".env"
                if not env.is_file():
                    raise FileNotFoundError(
                        "No env file input, must provide an env path or at "
                        f"default path: {env}"
                    )
            else:
                env = Path(env).resolve()

        if not env.is_file():
            raise FileNotFoundError(f"No such .env file: {env}")

        project_path = BaseProjectPath(
            root_path=root_path,
            input_path=root_path / "data" / "input",
            output_path=root_path / "data" / "output",
            prompt_path=root_path / "prompts",
            src_dir=root_path / "src",
            env_path=env,
            tests_dir=root_path / "tests",
        )

        return cls(
            project_path=project_path,
            preprocessing_task_configs=_build_preprocessing_task_configs(
                project_path.prompt_path
            ),
            ocr_config=_build_ocr_config(),
        )


def _build_preprocessing_task_configs(prompt_path: Path,) -> PreprocessingTaskConfigs:

    classify_pages = TaskConfig(
        model=ModelConfig(
            provider="openai",
            is_batch=True,
            model_name="gpt-5-mini",
            thinking_effort="medium",
            temperature=None,
            max_tokens=2000,
        ),
        system=_read_instructions(prompt_path / "prompt_classifyPages.txt"),
        output_format=PageClassification,
    )

    verify_reg_sum_pages = TaskConfig(
        model=ModelConfig(
            provider="openai",
            is_batch=True,
            model_name="gpt-5-mini",
            thinking_effort="medium",
            temperature=None,
            max_tokens=1000,
        ),
        system=_read_instructions(prompt_path / "prompt_verifyRegSumPages.txt"),
        output_format="text",
    )

    verify_reg_pages = TaskConfig(
        model=ModelConfig(
            provider="openai",
            is_batch=True,
            model_name="gpt-5-mini",
            thinking_effort="medium",
            temperature=None,
            max_tokens=2000,
        ),
        system=_read_instructions(prompt_path / "prompt_verifyRegPages.txt"),
        output_format="text",
    )

    add_page_description = TaskConfig(
        model=ModelConfig(
            provider="openai",
            model_name="gpt-5-mini",
            is_batch=True,
            thinking_effort="medium",
            temperature=None,
            max_tokens=2000,
        ),
        system=_read_instructions(prompt_path / "prompt_addPageDescription.txt"),
        output_format=PageDescription,
    )

    extract_reg_index = TaskConfig(
        model=ModelConfig(
            provider="openai",
            model_name="gpt-5-mini",
            is_batch=False,
            thinking_effort="medium",
            temperature=None,
            max_tokens=2000,
        ),
        system=_read_instructions(prompt_path / "prompt_extractRegIndex.txt"),
        output_format=RegisterIndexOutput,
    )

    extract_reg_map = TaskConfig(
        model=ModelConfig(
            provider="openai",
            model_name="gpt-5-mini",
            is_batch=False,
            thinking_effort="medium",
            temperature=None,
            max_tokens=2000,
        ),
        system=_read_instructions(prompt_path / "prompt_extractRegMap.txt"),
        output_format=RegisterMapOutput,
    )

    return PreprocessingTaskConfigs(
        classify_pages=classify_pages,
        verify_reg_sum_pages=verify_reg_sum_pages,
        verify_reg_pages=verify_reg_pages,
        add_page_description=add_page_description,
        extract_reg_index=extract_reg_index,
        extract_reg_map=extract_reg_map,
    )


def _read_instructions(prompt_path: str | Path | None) -> str:
    if not prompt_path:
        return "You are a helpful assistant."

    return Path(prompt_path).read_text(encoding="utf-8")


def _build_ocr_config() -> OcrConfig:
    return OcrConfig(
        provider="mistral",
        model_name="mistral-ocr-latest",
    )
