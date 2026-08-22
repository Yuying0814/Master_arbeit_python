import os
import math
import json
import asyncio
import time

from dotenv import load_dotenv
from pathlib import Path
from typing import Any
from src.models.task_config import TaskConfig,ModelConfig
from src.models.preprocessing.register_output import RegisterMapOutput
from src.llm.llm_task_runner import LLMTaskRunner

def _read_instructions(prompt_path: str | Path | None) -> str:
    if not prompt_path:
        return "You are a helpful assistant."

    return Path(prompt_path).read_text(encoding="utf-8")

def _get_pages_by_ocr_index(pages:list[dict[str,Any]],page_indices) -> list[dict[str,Any]]:
    page_index_map = {page["index"]: page for page in pages}
    return [page_index_map[page_index] for page_index in page_indices]

def  _build_chunks(indices:list[int],*,chunk_num:int = 3) -> list[list[int]]:
    chunks:list[list[int]] = []
    length = len(indices)
    chunk_length = math.ceil(length/chunk_num)
    chunk_start = 0

    while chunk_start < length:
        chunk_end = min(chunk_start + chunk_length, length)
        real_end = min(chunk_end+2,length)
        chunks.append(indices[chunk_start:real_end])
        chunk_start = chunk_end

    print(str(chunks))
    return chunks

def _build_extractor_input(
        pages:list[dict[str,Any]],
        register_summary:dict[str,Any],
        register_map:RegisterMapOutput|None
) -> str:
    return json.dumps(
        {
            "pages": pages,
            "registers": register_summary if register_summary else [],
            "previous_register_map": register_map.model_dump() if register_map else {},
        },
        ensure_ascii=False,
    )

PROJECT_ROOT = Path(__file__).resolve().parents[1]
DATA_DIR = PROJECT_ROOT / "data"

DEVICE_NAME = "BME280"
VERSION = "v2_0"
PDF = DATA_DIR/ "input_pdf" / "bst-bme280-ds002.pdf"



PROMPT = PROJECT_ROOT / "Prompts"
VERSION_PATH = DATA_DIR / "output" / DEVICE_NAME/ VERSION

SNAPSHOT_PATH = VERSION_PATH/ "preprocessor_snapshot.json"
PAGES_PATH = VERSION_PATH / "pages.json"
with PAGES_PATH.open(encoding="utf-8") as f:
    PAGES = json.load(f)

with SNAPSHOT_PATH.open(encoding="utf-8") as f:
    SNAPSHOT = json.load(f)

REGISTER_SUMMARY = SNAPSHOT["reg_summary"]["registers"]
REG_PAGES_INDECIES = SNAPSHOT["reg_page_idx"]
ENV = (PROJECT_ROOT / ".env").resolve()
OUTPUT_DIR = DATA_DIR / "output" / "test_chunk_extraction"/ f"{DEVICE_NAME}_{VERSION}"
load_dotenv(ENV)

TASK_CONFIG = TaskConfig(
    model=ModelConfig(
        provider="openai",
        model_name="gpt-5-mini",
        is_batch=False,
        thinking_effort="medium",
        temperature=None,
        max_tokens=50000,
    ),
    system=_read_instructions(PROMPT / "prompt_extract_register_map_chunk.txt"),
    output_format=RegisterMapOutput,
)

EXTRACTOR = LLMTaskRunner.load_from_task_config(
    task_config=TASK_CONFIG,
    api_key= os.getenv("OPENAI_API_KEY","").strip(),
)

def test():
    start_time = time.perf_counter()

    page_indices_chunks =  _build_chunks(REG_PAGES_INDECIES)
    last_register_map = None
    for index,indices_chunk in enumerate(page_indices_chunks):
        print(f"\nextracting chunk{index+1}/{len(page_indices_chunks)}")
        user_input = _build_extractor_input(
            pages = _get_pages_by_ocr_index(PAGES,indices_chunk),
            register_map=last_register_map,
            register_summary=REGISTER_SUMMARY,
        )
        register_map = asyncio.run(EXTRACTOR.run(user_input))
        last_register_map = register_map
        path = OUTPUT_DIR / f"chunk{index+1}.json"
        path.parent.mkdir(parents=True, exist_ok=True)
        with path.open("w",encoding="utf-8") as file:
            file.write(
                    last_register_map.model_dump_json(indent=4),
                ),
        print("chunk result written")

    elapsed_time = time.perf_counter() - start_time
    print(f"Total extraction time: {elapsed_time:.2f} seconds")

if __name__ == "__main__":
    test()
