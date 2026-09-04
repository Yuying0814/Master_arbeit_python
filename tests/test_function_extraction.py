import os
import json
import asyncio
import time

from pydantic import Field

from dotenv import load_dotenv
from pathlib import Path
from typing import Any

from src.models.task_config import TaskConfig,ModelConfig
from src.models.preprocessing.register_output import RegisterMapOutput
from src.models.structuredOutputModel import StructuredOutputModel

from src.llm.llm_task_runner import LLMTaskRunner
PROJECT_ROOT = Path(__file__).resolve().parents[1]
DATA_DIR = PROJECT_ROOT / "data"

class DeviceFunction(StructuredOutputModel):
    function_name:str = Field(description="Function name")
    function_description: str = Field(description="Concrete description of the function process, state changes")
    registers: list[str] = Field(description="Involved register names")

class DeviceFunctionOutput(StructuredOutputModel):
    device_functions: list[DeviceFunction] = Field(description="List of device functions")


def _read_instructions(prompt_path: str | Path | None) -> str:
    if not prompt_path:
        return "You are a helpful assistant."

    return Path(prompt_path).read_text(encoding="utf-8")

def _build_extractor_input(
        pages:list[dict[str,Any]],
        register_map:RegisterMapOutput|None
) -> str:
    return json.dumps(
        {
            "pages": pages,
            "register_map": register_map,
        },
        ensure_ascii=False,
    )

DEVICE_NAME = "TMP4719"
VERSION = "v1_0"

PROMPT = PROJECT_ROOT / "Prompts"
VERSION_PATH = DATA_DIR / "output" / DEVICE_NAME/ VERSION
PAGES_PATH = VERSION_PATH / "pages.json"

with PAGES_PATH.open(encoding="utf-8") as f:
    PAGES = json.load(f)

REGISTER_MAP_PATH = VERSION_PATH / "register_map.json"
with PAGES_PATH.open(encoding="utf-8") as f:
    REGISTER_MAP = json.load(f)

ENV = (PROJECT_ROOT / ".env").resolve()
OUTPUT_DIR = DATA_DIR / "output" / "test_function_extraction"/ f"{DEVICE_NAME}_{VERSION}"
load_dotenv(ENV)

TASK_CONFIG = TaskConfig(
    model=ModelConfig(
        provider="openai",
        model_name="gpt-5-mini",
        is_batch=False,
        thinking_effort="medium",
        temperature=None,
        max_tokens=20000,
    ),
    system=f"Carefully read the complete register_map "
           f"and systematically enumerate all device behaviors and driver APIs that are directly supported by the provided evidence.",
    output_format=DeviceFunctionOutput,
)

EXTRACTOR = LLMTaskRunner.load_from_task_config(
    task_config=TASK_CONFIG,
    api_key= os.getenv("OPENAI_API_KEY","").strip(),
)

def test():
    print(f"start identifying device functions")
    start_time = time.perf_counter()

    functions = asyncio.run(
        EXTRACTOR.run(
            _build_extractor_input(pages=PAGES,register_map=REGISTER_MAP),
        )
    )

    function_path = OUTPUT_DIR / "functions.json"
    function_path.parent.mkdir(parents=True, exist_ok=True)

    with function_path.open("w", encoding="utf-8") as file:
        file.write(
                functions.model_dump_json(indent=4),
            ),
    print("Functions written")

    usage_path = OUTPUT_DIR / "usage.json"
    usage_path.parent.mkdir(parents=True, exist_ok=True)
    with usage_path.open("w", encoding="utf-8") as file:
        file.write(
            EXTRACTOR.token_consumption.model_dump_json(indent=4),
        )
    print("Token consumption written")

    elapsed_time = time.perf_counter() - start_time
    print(f"Total extraction time: {elapsed_time:.2f} seconds")

if __name__ == "__main__":
    test()
