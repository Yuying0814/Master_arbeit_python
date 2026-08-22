import os
import json
import asyncio
import time

from dotenv import load_dotenv
from pathlib import Path
from typing import Any
from src.models.task_config import TaskConfig,ModelConfig
from src.models.preprocessing.register_output import RegisterMapItem, RegisterMapOutput
from src.llm.llm_task_runner import LLMTaskRunner
from src.models.llm.batch import UserRequest
def _read_instructions(prompt_path: str | Path | None) -> str:
    if not prompt_path:
        return "You are a helpful assistant."

    return Path(prompt_path).read_text(encoding="utf-8")

def _get_pages_by_ocr_index(pages:list[dict[str,Any]],page_indices) -> list[dict[str,Any]]:
    page_index_map = {page["index"]: page for page in pages}
    return [page_index_map[page_index] for page_index in page_indices]

def  _build_chunks(indices:list[int],*,chunk_length:int = 5) -> list[list[int]]:
    chunks:list[list[int]] = []
    length = len(indices)
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
) -> str:
    return json.dumps(
        {
            "pages": pages,
            "registers": register_summary if register_summary else [],
        },
        ensure_ascii=False,
    )

def _build_batch_user_input(
        pages:list[dict[str,Any]],
        page_indices:list[int],
        register_summary:dict[str,Any],
) -> list[UserRequest]:
    page_indices_chunks = _build_chunks(page_indices)

    user_requests:list[UserRequest] = []
    for index,indices_chunk in enumerate(page_indices_chunks):
        user_input = _build_extractor_input(
            pages=_get_pages_by_ocr_index(pages, indices_chunk),
            register_summary=register_summary,
        )
        custom_id = f"{DEVICE_NAME}_chunk{index+1}"
        user_requests.append(
            UserRequest(
                custom_id=custom_id,
                user_input=user_input,
            )
        )

    return user_requests

def _build_custom_id_result_map(
        raw_results:list[dict[str,Any]],
) -> dict[str,dict[str,Any]]:
    return {
        raw_result["custom_id"]: raw_result for raw_result in raw_results
    }

def _get_register_address_set(
        register_item:RegisterMapItem,
) -> set[tuple[str,str,str,str]]:
    return {
        (
            address.hex,
            address.decimal,
            address.bank,
            address.page,
        )
        for address in register_item.physical_address
    }

def _split_register_items_by_address(
        register_items:list[RegisterMapItem],
) -> tuple[list[RegisterMapItem],list[list[RegisterMapItem]]]:

    remaining_register_items = register_items.copy()
    register_groups:list[list[RegisterMapItem]] = []

    while remaining_register_items:
        register_group = [remaining_register_items.pop(0)]
        group_addresses = _get_register_address_set(register_group[0])
        item_index = 0

        while item_index < len(remaining_register_items):
            register_item = remaining_register_items[item_index]
            item_addresses = _get_register_address_set(register_item)

            if group_addresses & item_addresses:
                register_group.append(remaining_register_items.pop(item_index))
                group_addresses |= item_addresses
                item_index = 0
            else:
                item_index += 1

        register_groups.append(register_group)

    unique_register_items = [
        group[0] for group in register_groups if len(group) == 1
    ]
    duplicate_register_groups = [
        group for group in register_groups if len(group) > 1
    ]
    return unique_register_items, duplicate_register_groups

def _build_merge_input(
        pages:list[dict[str,Any]],
        register_items:list[RegisterMapItem],
) -> str:
    return json.dumps(
        {
            "pages": pages,
            "register_items": [
                register_item.model_dump() for register_item in register_items
            ],
        },
        ensure_ascii=False,
    )

def _build_merge_batch_user_input(
        pages:list[dict[str,Any]],
        duplicate_register_groups:list[list[RegisterMapItem]],
) -> list[UserRequest]:

    user_requests:list[UserRequest] = []

    for index,register_items in enumerate(duplicate_register_groups):
        source_page_indices = sorted(
            {
                source.page_index
                for register_item in register_items
                for source in register_item.source
            }
        )

        user_requests.append(
            UserRequest(
                custom_id=f"{DEVICE_NAME}_merge{index+1}",
                user_input=_build_merge_input(
                    pages=_get_pages_by_ocr_index(pages, source_page_indices),
                    register_items=register_items,
                ),
            )
        )

    return user_requests

#######################################################
PROJECT_ROOT = Path(__file__).resolve().parents[1]
DATA_DIR = PROJECT_ROOT / "data"

DEVICE_NAME = "BME280"
VERSION = "v2_0"
PDF = DATA_DIR/ "input_pdf" / "bst-bme280-ds002.pdf"
#######################################################


PROMPT = PROJECT_ROOT / "prompts"
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
OUTPUT_DIR = DATA_DIR / "output" / "test_chunk_extraction_batch"/ f"{DEVICE_NAME}_{VERSION}"
load_dotenv(ENV)
#######################################################

TASK_CONFIG = TaskConfig(
    model=ModelConfig(
        provider="openai",
        model_name="gpt-5.6-sol",
        is_batch=True,
        thinking_effort="medium",
        temperature=None,
        max_tokens=40000,
    ),
    system=_read_instructions(PROMPT / "prompt_extraction_chunk_batch.txt"),
    output_format=RegisterMapOutput,
)

EXTRACTOR = LLMTaskRunner.load_from_task_config(
    task_config=TASK_CONFIG,
    api_key= os.getenv("OPENAI_API_KEY","").strip(),
    input_path=OUTPUT_DIR / "extractor_batch_input.jsonl",
)

MERGE_TASK_CONFIG = TaskConfig(
    model=ModelConfig(
        provider="openai",
        model_name="gpt-5.4",
        is_batch=True,
        thinking_effort="medium",
        temperature=None,
        max_tokens=40000,
    ),
    system=_read_instructions(PROMPT / "prompt_merge_register_map_items.txt"),
    output_format=RegisterMapOutput,
)

MERGER = LLMTaskRunner.load_from_task_config(
    task_config=MERGE_TASK_CONFIG,
    api_key=os.getenv("OPENAI_API_KEY", "").strip(),
    input_path=OUTPUT_DIR / "merge_batch_input.jsonl",
)

def test():
    start_time = time.perf_counter()

    user_requests = _build_batch_user_input(
        pages=PAGES,
        page_indices=REG_PAGES_INDECIES,
        register_summary=REGISTER_SUMMARY,
    )

    raw_results = asyncio.run(EXTRACTOR.run(user_requests))

    retrieval_map = _build_custom_id_result_map(raw_results)

    results = [
        RegisterMapOutput.model_validate(
            retrieval_map[user_request.custom_id]["content"]
        )
        for user_request in user_requests
    ]

    register_items = [
        register_item
        for result in results
        for register_item in result.registers
    ]

    unique_register_items,duplicate_register_groups = (
        _split_register_items_by_address(register_items)
    )
    if duplicate_register_groups:
        merge_user_requests = _build_merge_batch_user_input(
            pages = PAGES,
            duplicate_register_groups=duplicate_register_groups,
        )

        merge_user_requests_path = OUTPUT_DIR / "merge_user_requests.json"

        with merge_user_requests_path.open("w",encoding="utf-8") as file:
            for user_request in merge_user_requests:
                file.write(
                    f"{user_request.model_dump_json(indent=4)}\n"
                )

        merged_raw_results = asyncio.run(MERGER.run(merge_user_requests))

        merged_retrieval_map = _build_custom_id_result_map(merged_raw_results)
        merged_register_maps = [
            RegisterMapOutput.model_validate(
                merged_retrieval_map[user_request.custom_id]["content"]
            )
            for user_request in merge_user_requests
        ]
        merged_register_items = []
        for register_map in merged_register_maps:
            merged_register_items.extend(register_map.registers)
    else:
        merged_register_items = []

    final_register_items = unique_register_items + merged_register_items

    for index,register_item in enumerate(final_register_items, start=1):
        register_item.index = index

    final_result = RegisterMapOutput(registers=final_register_items)

    register_map_path = OUTPUT_DIR/f"register_map_chunk_batch_{VERSION}.json"
    register_map_path.parent.mkdir(parents=True, exist_ok=True)
    with register_map_path.open("w",encoding="utf-8") as file:
        file.write(
            final_result.model_dump_json(
                indent=4,
            )
        )

    extractor_consumption = EXTRACTOR.token_consumption
    merge_consumption = MERGER.token_consumption
    usage = {
        "extractor": extractor_consumption.model_dump(),
        "merge": merge_consumption.model_dump(),
    }


    usage_path = OUTPUT_DIR/"usage.json"
    with usage_path.open("w",encoding="utf-8") as file:
        file.write(
            json.dumps(usage, indent=4, ensure_ascii=False)
        )

    print(final_result.model_dump_json(indent=2))


    elapsed_time = time.perf_counter() - start_time
    print(f"Total extraction time: {elapsed_time:.2f} seconds")

if __name__ == "__main__":
    test()
