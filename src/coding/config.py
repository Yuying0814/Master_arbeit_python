from __future__ import annotations
from src.config import BaseConfig,BaseProjectPath
from dataclasses import dataclass
from pathlib import Path

def _build_openai_task_config(prompt_path:Path)->OpenaiConfig:
    task:dict[str, dict] ={}

    # task["classify_pages"] = {
    #     "model": "gpt-5-mini",
    #     "prompt_path": prompt_path/"prompt_classifyPages.txt",
    #     "text_format": PageClassification,
    #     "max_output_tokens": 2000,
    # }

    return OpenaiConfig(task=task)

@dataclass(frozen=True)
class CodingProjectPath(BaseProjectPath):
    code_dir: Path

@dataclass(frozen=True)
class OpenaiConfig:
    task:dict[str, dict]

class CodingConfig(BaseConfig):
    project_path: CodingProjectPath
    openai: OpenaiConfig

    def __init__(self,project_path:BaseProjectPath,openai_config:OpenaiConfig) -> None:
        super().__init__(project_path)
        self.openai = openai_config

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
            openai_config = _build_openai_task_config(project_path.prompt_path),
        )



