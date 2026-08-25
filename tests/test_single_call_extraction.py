import os
import json
import time

from pathlib import Path
from dotenv import load_dotenv
from typing import Any

from src.models.preprocessing.register_output import RegisterMapOutput
from langchain_openai import ChatOpenAI

PROJECT_ROOT = Path(__file__).resolve().parents[1]
DATA_DIR = PROJECT_ROOT / "data"

DEVICE_NAME = "BME280"
VERSION = "v2_0"
PDF = DATA_DIR/ "input_pdf" / "bst-bme280-ds002.pdf"

###############################################
PROMPT = PROJECT_ROOT / "Prompts"
VERSION_PATH = DATA_DIR / "output" / DEVICE_NAME/ VERSION

SNAPSHOT_PATH = VERSION_PATH/ "preprocessor_snapshot.json"
PAGES_PATH = VERSION_PATH / "pages.json"
with PAGES_PATH.open(encoding="utf-8") as f:
    PAGES = json.load(f)

with SNAPSHOT_PATH.open(encoding="utf-8") as f:
    SNAPSHOT = json.load(f)

REGISTER_SUMMARY = SNAPSHOT["reg_summary"]["registers"]
REG_PAGES_INDICES = SNAPSHOT["reg_page_idx"]
ENV = (PROJECT_ROOT / ".env").resolve()
OUTPUT_DIR = DATA_DIR / "output" / "test_single_call_extraction"/ f"{DEVICE_NAME}_{VERSION}"
load_dotenv(ENV)

def _read_instructions(prompt_path: str | Path | None) -> str:
    if not prompt_path:
        return "You are a helpful assistant."

    return Path(prompt_path).read_text(encoding="utf-8")

def _get_pages_by_ocr_index(pages:list[dict[str,Any]],page_indices) -> list[dict[str,Any]]:
    page_index_map = {page["index"]: page for page in pages}
    return [page_index_map[page_index] for page_index in page_indices]

def _build_user_input(pages:list[dict[str,Any]],page_indices:list[int],register_summary:dict[str,Any]) -> str:
    return json.dumps(
        {
            "pages": _get_pages_by_ocr_index(pages,page_indices),
            "registers": register_summary,
        },
        indent=4,
    )

def test():
    start_time = time.perf_counter()
    print(f"Extracting")

    llm = ChatOpenAI(
        model="gpt-5-mini",
        api_key=os.getenv("OPENAI_API_KEY"),
        reasoning_effort="medium",
        max_tokens=50000,
    )

    structured_model = llm.with_structured_output(
        schema=RegisterMapOutput,
        method="json_schema",
        include_raw=True,
    )

    user_input = _build_user_input(
                pages=PAGES,
                page_indices=REG_PAGES_INDICES,
                register_summary=REGISTER_SUMMARY,
            )

    user_input_path = OUTPUT_DIR / "user_input.json"
    user_input_path.parent.mkdir(parents=True, exist_ok=True)
    with user_input_path.open("w",encoding="utf-8") as file:
        file.write(user_input)
    print("user input written")

    response = structured_model.invoke(
        [
            ("system", _read_instructions(PROMPT/"prompt_extractRegMap.txt")),
            ("human", user_input),
        ],

    )
    elapsed_time = time.perf_counter() - start_time

    serializable_response = {
        "raw": response["raw"].model_dump(mode="json"),
        "parsed": response["parsed"].model_dump(mode="json"),
        "time": elapsed_time,
    }

    raw_result_path = OUTPUT_DIR / "raw.json"
    raw_result_path.parent.mkdir(parents=True, exist_ok=True)
    with raw_result_path.open("w",encoding="utf-8") as file:
        file.write(
            json.dumps(serializable_response,indent=4)
        )
    print("raw result written")

    register_map_path = OUTPUT_DIR / "register_map.json"
    register_map_path.parent.mkdir(parents=True, exist_ok=True)
    with register_map_path.open("w",encoding="utf-8") as file:
        file.write(
            json.dumps(
                serializable_response["parsed"],
                indent=4,
            )
        )
    print(f"Total extraction time: {elapsed_time:.2f} seconds")

    return response

if __name__ == "__main__":
    test()