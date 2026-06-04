import sys
import os
import json
from pathlib import Path
from dotenv import load_dotenv
from typing import Any
from src.models.register_output import RegisterMapOutput
from src.openai.openai_task import OpenAITask
from src.preprocessing.mistral.mistral_client import MistralClient

PROJECT_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(PROJECT_ROOT))


def test_without_preprocessing(pdf_name:str):
    pdf_path = PROJECT_ROOT / "data" / "input_pdf" / pdf_name
    name = pdf_path.stem
    output_path = PROJECT_ROOT / "data" /"output" / "test_without_preprocessing" / name

    load_dotenv(dotenv_path=PROJECT_ROOT/".env")
    openai_api_key = os.getenv("OPENAI_API_KEY", "").strip()
    mistralai_api_key = os.getenv("MISTRALAI_API_KEY", "").strip()

    mistral = MistralClient(mistralai_api_key)
    ocr_result = mistral.run_ocr(pdf_path)

    pages = [
        {
            "index": page["index"],
            "markdown": page["markdown"],
            "tables": page["tables"],
        } for page in ocr_result.get("pages")]

    user = json.dumps(
        {
            "pages": pages,
            "registers":[]
        }
    )

    task = {}
    task["extract_reg_map"] = {
        "model": "gpt-5-mini",
        "prompt_path": PROJECT_ROOT/"prompts"/"prompt_extractRegMap.txt",
        "text_format": RegisterMapOutput,
    }

    task_reg_map_extraction = OpenAITask(
        api_key=openai_api_key,
        user=user,
        task_config=task["extract_reg_map"],
    )

    result = task_reg_map_extraction.run()
    write_json(output_path, result)

def write_json(output_path: Path, data: Any) -> None:
    output_path.parent.mkdir(parents=True, exist_ok=True)

    output_path.write_text(
        json.dumps(
            make_json_safe(data),
            ensure_ascii=False,
            indent=2,
        ),
        encoding="utf-8",
    )

def make_json_safe(value: Any) -> Any:
    if isinstance(value, Path):
        return str(value)

    if isinstance(value, dict):
        return {
            str(key): make_json_safe(item)
            for key, item in value.items()
        }

    if isinstance(value, list):
        return [
            make_json_safe(item)
            for item in value
        ]

    if isinstance(value, tuple):
        return [
            make_json_safe(item)
            for item in value
        ]

    if isinstance(value, (str, int, float, bool)) or value is None:
        return value

    return str(value)