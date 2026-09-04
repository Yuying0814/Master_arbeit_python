import sys
import os
import json
import asyncio

from pathlib import Path
from dotenv import load_dotenv

PROJECT_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(PROJECT_ROOT))

from src.models.preprocessing.register_output import RegisterMapOutput
from src.models.task_config import TaskConfig,ModelConfig
from src.llm.llm_task_runner import LLMTaskRunner



load_dotenv(dotenv_path=PROJECT_ROOT/".env")

###################################################
PDF_NAME = "ATmega8.pdf"
MODEL_NAME = "gpt-5-mini"
PROVIDER = "openai"
###################################################

PDF_DIR = PROJECT_ROOT / "data" / "input_pdf"
PDF_PATH = PDF_DIR / PDF_NAME
OCR_PATH= PROJECT_ROOT / "data" / "output" / "ocr" / "mistral" / "mistral-ocr-latest"/f"{PDF_PATH.stem}.json"
OPENAI_API_KEY = os.getenv("OPENAI_API_KEY", "").strip()
PROMPT_PATH = PROJECT_ROOT/"prompts"/"prompt_extractRegMap.txt"
OUTPUT_PATH = PROJECT_ROOT / "data" /"output"/"test_without_preprocessing"/MODEL_NAME/f"{PDF_PATH.stem}.json"
BASE_URL = "100.118.198.6:11434"

def _read_instructions(prompt_path: str | Path | None) -> str:
    if not prompt_path:
        return "You are a helpful assistant."

    return Path(prompt_path).read_text(encoding="utf-8")

TASK_CONFIG = TaskConfig(
    model=ModelConfig(
        provider=PROVIDER,
        model_name=MODEL_NAME,
        thinking_effort="",
        max_tokens=70000,
        timeout=36000,
        base_url=BASE_URL,
    ),
    system= _read_instructions(PROMPT_PATH),
    output_format=RegisterMapOutput,
    memory_enabled=False,
)

EXTRACTOR = LLMTaskRunner.load_from_task_config(
    task_config=TASK_CONFIG,
    api_key=OPENAI_API_KEY,
)
with OCR_PATH.open("r",encoding="utf-8") as f:
    OCR_RESULT = json.load(f)
PAGES = OCR_RESULT["pages"]

async def test():
    user = {
        "pages": PAGES,
        "registers": [],
    }

    register_map = await EXTRACTOR.run(json.dumps(user))

    OUTPUT_PATH.parent.mkdir(parents=True, exist_ok=True)
    with OUTPUT_PATH.open("w",encoding="utf-8") as file:
        file.write(register_map.model_dump_json(indent=4))


if __name__ == "__main__":
    asyncio.run(test())
