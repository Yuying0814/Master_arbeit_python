from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path

from src.config import BaseConfig, BaseProjectPath
from src.models.task_config import ModelConfig, OcrConfig, TaskConfig,ChatTaskConfigs
from src.models.chat import DeviceIdentificationResult


@dataclass
class ChatProjectPath(BaseProjectPath):
    database_path: Path


class ChatConfig(BaseConfig):
    project_path: ChatProjectPath
    task_configs: ChatTaskConfigs
    ocr: OcrConfig

    def __init__(self,project_path: ChatProjectPath,task_configs: ChatTaskConfigs,ocr_config: OcrConfig,) -> None:
        super().__init__(project_path)
        self.task_configs = task_configs
        self.ocr = ocr_config

    @classmethod
    def load_config(cls,env: str | Path = "",database: str | Path = "",) -> "ChatConfig":

        root_path = Path(__file__).resolve().parents[2]
        env_path = _resolve_env_path(root_path, env)
        database_path = _resolve_database_path(root_path, database)

        project_path = ChatProjectPath(
            root_path=root_path,
            input_path=root_path / "data" / "input",
            output_path=root_path / "data" / "output",
            prompt_path=root_path / "prompts",
            src_dir=root_path / "src",
            env_path=env_path,
            tests_dir=root_path / "tests",
            database_path=database_path,
        )

        return cls(
            project_path=project_path,
            task_configs=_build_task_config(project_path.prompt_path),
            ocr_config=_build_ocr_config(),
        )


def _build_task_config(prompt_path: Path) -> ChatTaskConfigs:
    return ChatTaskConfigs(
        chat=TaskConfig(
            model=ModelConfig(
                provider="ollama",
                is_batch=False,
                model_name="qwen3:8b",
                thinking_effort=None,
                temperature=0.0,
                max_tokens=2000,
            ),
            system=_read_instructions(prompt_path / "prompt_chat_llm.txt"),
            output_format="text",
            memory_enabled=True,
        ),
        identify_name=TaskConfig(
            model=ModelConfig(
                provider="ollama",
                is_batch=False,
                model_name="qwen3:8b",
                thinking_effort=None,
                temperature=0.0,
                max_tokens=2000,
            ),
            system=_read_instructions(prompt_path / "prompt_identify_device.txt"),
            output_format=DeviceIdentificationResult,
        ),
    )

def _build_ocr_config() -> OcrConfig:
    return OcrConfig(
        provider="mistral",
        model_name="mistral-ocr-latest",
    )

def _resolve_env_path(root_path: Path, env: str | Path) -> Path:
    if isinstance(env, str) and not env.strip():
        env = root_path / ".env"
    else:
        env = Path(env).expanduser().resolve()

    if not env.is_file():
        raise FileNotFoundError(f"No such .env file: {env}")

    return env


def _resolve_database_path(root_path: Path,database: str | Path,) -> Path:
    if isinstance(database, str) and not database.strip():
        return root_path / "data" / "database.db"

    return Path(database).expanduser().resolve()


def _read_instructions(prompt_path: str | Path | None) -> str:
    if not prompt_path:
        return "You are a helpful assistant."

    return Path(prompt_path).read_text(encoding="utf-8")
