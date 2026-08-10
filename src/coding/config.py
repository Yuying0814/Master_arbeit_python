from __future__ import annotations
from dataclasses import dataclass,field
from pathlib import Path

from src.config import BaseConfig,BaseProjectPath
from src.models.coding.retriever import BinaryClassifierOutput
from src.models.coding.coder import CoderOutput
from src.models.coding.planner import PlannerOutput
from src.models.coding.verifier import SemanticVerifierOutput, TestCode
from src.models.task_config import TaskConfig,ModelConfig,CodingTaskConfigs

@dataclass
class ArduinoBoardConfig:
    package: str
    architecture: str
    board: str
    options: dict[str, str] = field(default_factory=dict)

def _build_task_config(prompt_path:Path)->CodingTaskConfigs:
    retrieval = TaskConfig(
        model = ModelConfig(
            provider = "openai",
            is_batch=True,
            model_name="gpt-5-mini",
            thinking_effort="medium",
            temperature=None,
            max_tokens=2000,
        ),
        system = _read_instructions(prompt_path/"prompt_retriever.txt"),
        output_format = BinaryClassifierOutput,
    )

    planning = TaskConfig(
        model=ModelConfig(
            provider="openai",
            model_name="gpt-5-mini",
            thinking_effort="medium",
            temperature=None,
            max_tokens=10000,
        ),
        system=_read_instructions(prompt_path / "prompt_planner.txt"),
        output_format=PlannerOutput,
        memory_enabled=True,
    )

    coding = TaskConfig(
        model=ModelConfig(
            provider="openai",
            model_name="gpt-5-mini",
            thinking_effort="medium",
            temperature=None,
            max_tokens=10000,
        ),
        system=_read_instructions(prompt_path / "prompt_coder.txt"),
        output_format=CoderOutput,
    )

    verification_semantic = TaskConfig(
        model=ModelConfig(
            provider="openai",
            model_name="gpt-5-mini",
            thinking_effort="medium",
            temperature=None,
            max_tokens=10000,
        ),
        system=_read_instructions(prompt_path / "prompt_semantic_verifier.txt"),
        output_format=SemanticVerifierOutput,
    )

    verification_test_coder = TaskConfig(
        model=ModelConfig(
            provider="openai",
            model_name="gpt-5-mini",
            thinking_effort="medium",
            temperature=None,
            max_tokens=10000,
        ),
        system=_read_instructions(prompt_path / "prompt_test_coder.txt"),
        output_format=TestCode,
        memory_enabled=True
    )

    return CodingTaskConfigs(
        retrieval=retrieval,
        planning = planning,
        coding = coding,
        verification_semantic = verification_semantic,
        verification_test_coder = verification_test_coder
    )

def _read_instructions(prompt_path:str|Path|None) -> str:
    if not prompt_path:
        return "You are a helpful assistant."

    prompt_path = Path(prompt_path)
    return Path(prompt_path).read_text(encoding="utf-8")

@dataclass
class CodingProjectPath(BaseProjectPath):
    code_dir: Path
    cli_path: Path

class CodingConfig(BaseConfig):
    project_path: CodingProjectPath
    task_configs: CodingTaskConfigs
    enable_test_coder: bool
    board_config:ArduinoBoardConfig

    def __init__(
            self,
            project_path:CodingProjectPath,
            task_configs:CodingTaskConfigs,
            enable_test_coder:bool,
            board_config:ArduinoBoardConfig,
    ) -> None:
        super().__init__(project_path)
        self.task_configs = task_configs
        self.enable_test_coder = enable_test_coder
        self.board_config = board_config

    @classmethod
    def load_config(
            cls,code_dir:str|Path, cli_path:str|Path, env:str|Path="",*,
            enable_test_coder:bool=False,
            package:str,
            architecture:str,
            board:str,
            board_options:dict[str,str],
    ) -> CodingConfig:

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
        cli_path = Path(cli_path)

        project_path = CodingProjectPath(
            root_path=root_path,
            input_path=root_path /"data"/ "input",
            output_path=root_path /"data"/ "output",
            prompt_path=root_path / "prompts",
            src_dir=root_path / "src",
            env_path=env_path,
            tests_dir=root_path / "tests",
            code_dir = code_dir,
            cli_path= cli_path,
        )

        return cls(
            project_path = project_path,
            task_configs = _build_task_config(project_path.prompt_path),
            enable_test_coder = enable_test_coder,
            board_config=ArduinoBoardConfig(
                package=package,
                architecture=architecture,
                board=board,
                options=board_options,
            ),
        )



