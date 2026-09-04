import sys
import asyncio
import json

from pathlib import Path
from typing import Any



PROJECT_ROOT = Path(__file__).resolve().parents[1]
PROMPT_PATH = PROJECT_ROOT/"prompts"
sys.path.insert(0, str(PROJECT_ROOT))

from src.models.planner import PlannerOutput
from models.coding.coder import CoderOutput
from src.coding.config import CodingConfig
from src.coding.controller.controller import Controller

DRIVER_NAME = "adxl345"
ENABLE_TEST_CODER = False
CORE = "avr"
BOARD = "uno"
CODE_DIR = PROJECT_ROOT/"temp"
CLI_PATH = PROJECT_ROOT/"arduino"/"bin"/"arduino-cli.exe"
ENV = PROJECT_ROOT/".env"
PAGES_PATH = PROJECT_ROOT/"data"/"output"/"adxl345"/"adxl345_pages.json"
REGISTER_MAP = PROJECT_ROOT/"data"/"output"/"adxl345"/"adxl345_register_map.json"
TEMP_INPUT = PROJECT_ROOT/"temp"/"planner_input.json"
TEMP_OUTPUT = PROJECT_ROOT/"temp"/"planner_output.json"
TEMP_TOKENS = PROJECT_ROOT/"temp"/"planner_tokens.json"

def read_json(path: Path) -> Any:
    with open(path, "r", encoding="utf-8") as f:
        return json.load(f)

def read_pages(path: Path) -> Any:
    pages = read_json(path)
    keep_field = {"index","markdown","tables"}
    return [
        {
            key: value for key, value in page.items() if key in keep_field
        }for page in pages
    ]

def write(content:str, path: Path):
    with open(path, "w", encoding="utf-8") as f:
        f.write(content)

def configure_coding_models(config: CodingConfig) -> None:
    """Configure model settings for the current preprocessing run."""
    """Available settings for each task:
        provider: str, "openai", "ollama"
        is_batch: bool, True, False (better not change)
        model_name: str, "gpt-5-mini", "gpt-5.4", ...
        temperature: int
        max_tokens: int
    """
    model_settings: dict[str, dict[str, Any]] = {
        "planning": {
            "provider": "openai",
            "model_name": "gpt-5-mini",
            "temperature": 0.0,
            "max_tokens": 100000,
        },
        "retrieval": {
            "provider": "openai",
            "model_name": "gpt-5-mini",
            "temperature": 0.0,
            "max_tokens": 5000,
        },
        "coding": {
            "provider": "openai",
            "model_name": "gpt-5.3-codex",
            "temperature": 0.0,
            "max_tokens": 20000,
        },
        "verification_semantic": {
            "provider": "openai",
            "model_name": "gpt-5-mini",
            "temperature": 0.0,
            "max_tokens": 10000,
        },
        "verification_test_coder": {
            "provider": "openai",
            "model_name": "gpt-5-mini",
            "temperature": 0.0,
            "max_tokens": 10000,
        },
    }

    for task_name, settings in model_settings.items():
        task_config = getattr(config.task_configs, task_name)

        for field_name, value in settings.items():
            setattr(task_config.model, field_name, value)

async def build_controller() -> Controller:
    code_dir = CODE_DIR
    cli_path = CLI_PATH
    env_path = ENV

    config = CodingConfig.load_config(
        code_dir=code_dir,
        cli_path=cli_path,
        env = env_path,
        enable_test_coder=ENABLE_TEST_CODER,
        core=CORE,
        board=BOARD,
    )
    configure_coding_models(config)

    controller = Controller.load_controller(
        driver_name=DRIVER_NAME,
        config=config,
        pages=read_pages(PAGES_PATH),
        register_map = read_json(REGISTER_MAP),
    )

    return controller

async def run_coding():
    controller = await build_controller()
    await controller.run()

async def run_planner():
    controller = await build_controller()
    planner_input = controller._build_planner_input(user_request=None, device_functions=, verifier_feedback=None)
    write(planner_input.model_dump_json(indent=2), TEMP_INPUT)

    planner_output = controller.planner.create_plan(planner_input)
    write(planner_output.model_dump_json(indent=2), TEMP_OUTPUT)

    planner_tokens = controller.planner.logs[-1].token_consumption
    write(json.dumps(planner_tokens), TEMP_TOKENS)

async def run_coder():
    controller = await build_controller()
    plan_path = Path("D:/python/master_arbeit/temp/planner_output.json")
    with plan_path.open("r", encoding="utf-8") as f:
        planner_output = json.load(f)
    planner_output = PlannerOutput.model_validate(planner_output)

    coder_input = controller._build_coder_input(programming_plan = planner_output.programming_plan, retrieval_results=[])
    write(coder_input.model_dump_json(indent=2), Path("D:/python/master_arbeit/temp/coder_input.json"))

    coder_output = controller.coder.create_code_file(coder_input)
    write(coder_output.model_dump_json(indent=2), Path("D:/python/master_arbeit/temp/coder_output.json"))

    coder_tokens = controller.coder.logs[-1].token_consumption
    write(json.dumps(coder_tokens), Path("D:/python/master_arbeit/temp/coder_tokens.json"))

async def run_verifier():
    controller = await build_controller()
    plan_path = Path("D:/python/master_arbeit/temp/planner_output.json")
    with plan_path.open("r", encoding="utf-8") as f:
        planner_output = json.load(f)
    planner_output = PlannerOutput.model_validate(planner_output)

    code_path = Path("D:/python/master_arbeit/temp/coder_output.json")
    with code_path.open("r", encoding="utf-8") as f:
        coder_output = json.load(f)
    coder_output = CoderOutput.model_validate(coder_output)

    controller.candidate_files = coder_output.candidate_files
    verifier_input = controller._build_verifier_input(planner_output.verification_plan,,
    write(verifier_input.model_dump_json(indent=2), Path("D:/python/master_arbeit/temp/verifier_input.json"))

    verifier_output = controller.verifier.run(verifier_input)
    write(verifier_output.model_dump_json(indent=2), Path("D:/python/master_arbeit/temp/verifier_output.json"))

    verifier_tokens = controller.verifier.logs[-1].token_consumption
    write(json.dumps(verifier_tokens), Path("D:/python/master_arbeit/temp/verifier_tokens.json"))


def main():
    asyncio.run(run_coding())

if __name__ == "__main__":
    main()