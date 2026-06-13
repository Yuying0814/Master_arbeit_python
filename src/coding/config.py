from __future__ import annotations
from dataclasses import dataclass
from pathlib import Path
from pydantic import BaseModel

from src.config import BaseConfig,BaseProjectPath
from src.models.retriever import RetrievalResponse
from src.models.task_config import TaskConfig,ModelConfig,CodingTaskConfigs


def _build_task_config(prompt_path:Path)->CodingTaskConfigs:
    retrieval = TaskConfig(
        model = ModelConfig(
            provider = "openai",
            model_name="gpt-5-mini",
            temperature=0.0,
            max_tokens=2000,
        ),
        system = _read_instructions(prompt_path/"prompt_retriever.txt"),
        output_format = RetrievalResponse,
    )

    return CodingTaskConfigs(
        Retrieval=retrieval,
    )

def _read_instructions(prompt_path:str|Path|None) -> str:
    if not prompt_path:
        return "You are a helpful assistant."

    prompt_path = Path(prompt_path)
    return Path(prompt_path).read_text(encoding="utf-8")

@dataclass(frozen=True)
class CodingProjectPath(BaseProjectPath):
    code_dir: Path

class CodingConfig(BaseConfig):
    project_path: CodingProjectPath
    task_configs: CodingTaskConfigs

    def __init__(self,project_path:BaseProjectPath,task_configs:CodingTaskConfigs) -> None:
        super().__init__(project_path)
        self.task_configs = task_configs

    @classmethod
    def load_config(cls,code_dir:str|Path,env:str|Path=""):
        code_dir = Path(code_dir)
        code_dir.mkdir(parents=True, exist_ok=True)

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

        project_path = CodingProjectPath(
            root_path=root_path,
            input_path=root_path /"data"/ "input",
            output_path=root_path /"data"/ "output",
            prompt_path=root_path / "prompts",
            src_dir=root_path / "src",
            env_path=env_path,
            tests_dir=root_path / "tests",
            code_dir = code_dir,
        )

        return cls(
            project_path = project_path,
            task_configs = _build_task_config(project_path.prompt_path),
        )



