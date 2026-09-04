import os
import json
import asyncio

from dotenv import load_dotenv

from pathlib import Path
from src.models.task_config import TaskConfig,ModelConfig
from src.models.preprocessing.function_identifier import DeviceFunctionOutput,FunctionIdentifierInput
from src.llm.llm_task_runner import LLMTaskRunner

PROJECT_ROOT = Path(__file__).resolve().parents[1]

ENV = (PROJECT_ROOT / ".env").resolve()
load_dotenv(ENV)

#############################
DEVICE_NAME = "TCS3472"
PDF = "TCS3472.pdf"

VERSION = 1
PROVIDER = "openai"
MODEL = "gpt-5-mini" # "gpt-5-mini","gemini-3.6-flash","gemini-3.5-flash-lite","claude-haiku-4-5","glm-4-plus","kimi-k2.6","mistral-medium-3.5:128b-ctx256k"
THINKING_EFFORT = "medium"

APIKEY = os.getenv("OPENAI_API_KEY")
#############################

BASE_URL = "http://129.187.200.113:11434"
DATA_DIR = PROJECT_ROOT / "data"
OUTPUT_DIR = DATA_DIR / "output"
PROMPT_PATH = PROJECT_ROOT / "prompts"
OCR_PATH = OUTPUT_DIR / "ocr" / "mistral"/ "mistral-ocr-latest"/f"{Path(PDF).stem}.json"
DEVICE_DIR = OUTPUT_DIR / f"{DEVICE_NAME}" / f"v{VERSION}_0"
REGISTER_PATH = DEVICE_DIR / "register_map.json"
TASK_MODELS_PATH = DEVICE_DIR / "task_models.json"
TOKEN_CONSUMPTION_PATH = DEVICE_DIR / "token_consumption.json"
TIME_CONSUMPTION_PATH = DEVICE_DIR / "time_consumption.json"
SNAPSHOT_PATH = DEVICE_DIR / "preprocessor_snapshot.json"
DEVICE_FUNCTION_PATH = DEVICE_DIR / "device_functions.json"

with OCR_PATH.open() as f:
    OCR = json.load(f)
    PAGES = OCR["pages"]

with REGISTER_PATH.open("r",encoding="utf-8") as f:
    REGISTER_MAP = json.load(f)
with TASK_MODELS_PATH.open("r",encoding="utf-8") as f:
    TASK_MODELS = json.load(f)
    TASK_MODELS.pop("add_page_description", None)
with TOKEN_CONSUMPTION_PATH.open("r",encoding="utf-8") as f:
    TOKEN_CONSUMPTION = json.load(f)

if TIME_CONSUMPTION_PATH.is_file():
    with TIME_CONSUMPTION_PATH.open("r",encoding="utf-8") as f:
        TIME_CONSUMPTION = json.load(f)
else:
    TIME_CONSUMPTION = {}

with SNAPSHOT_PATH.open("r",encoding="utf-8") as f:
    SNAPSHOT=json.load(f)

def _read_instructions(prompt_path: str | Path | None) -> str:

    return Path(prompt_path).read_text(encoding="utf-8")

TASK_CONFIG = TaskConfig(
        model=ModelConfig(
            provider= PROVIDER,
            model_name=MODEL,
            is_batch=False,
            thinking_effort=THINKING_EFFORT,
            temperature=None,
            max_tokens=20000,
            timeout=1200,
            base_url=BASE_URL,
        ),
        system = _read_instructions(PROMPT_PATH / "prompt_function_identifier.txt"),
        output_format= DeviceFunctionOutput,
    )

IDENTIFIER = LLMTaskRunner.load_from_task_config(
    task_config=TASK_CONFIG,
    api_key=APIKEY
)

USER_INPUT = FunctionIdentifierInput(
    register_map=REGISTER_MAP,
    pages=PAGES
)

def add_device_functions():
    print("\nstart identifying functions")
    device_functions = asyncio.run(
        IDENTIFIER.run(
            USER_INPUT.model_dump_json()
        )
    )
    print("\nIdentification complete")
    with DEVICE_FUNCTION_PATH.open("w",encoding="utf-8") as file:
        file.write(
            device_functions.model_dump_json(indent=4),
        )

    TASK_MODELS["identify_function"] = MODEL
    TOKEN_CONSUMPTION["function_identification"] = IDENTIFIER.token_consumption.model_dump()
    TIME_CONSUMPTION["device_function_identification"] = IDENTIFIER.elapsed_time
    SNAPSHOT["device_functions"] = device_functions.model_dump()

    with TASK_MODELS_PATH.open("w",encoding="utf-8") as file:
        file.write(
            json.dumps(TASK_MODELS, indent=4)
        )

    with TOKEN_CONSUMPTION_PATH.open("w",encoding="utf-8") as file:
        file.write(
            json.dumps(TOKEN_CONSUMPTION, indent=4)
        )

    with TIME_CONSUMPTION_PATH.open("w",encoding="utf-8") as file:
        file.write(
            json.dumps(TIME_CONSUMPTION, indent=4)
        )

    with SNAPSHOT_PATH.open("w",encoding="utf-8") as file:
        file.write(
            json.dumps(SNAPSHOT, indent=4)
        )

if __name__ == "__main__":
    add_device_functions()