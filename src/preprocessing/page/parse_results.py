from __future__ import annotations
from typing import Any
from src.preprocessing.page.page_batch_task import PageBatchTask
from src.models.page_output import PageClassification,PageDescription


def parse_verification_content(page_task:PageBatchTask | None) ->list[int]:
    if not page_task:
        return []
    index_content_map = _build_index_content_map(page_task)
    return [page_index for page_index,content in index_content_map.items() if str(content).strip().lower() == "yes"]

def parse_classification_content(page_task:PageBatchTask | None,pages:list[dict[str,Any]]) -> None:
    if not page_task:
        print("No classification task")
        return
    index_content_map = _build_index_content_map(page_task)
    for page in pages:
        page_index = page["index"]
        page["classification"] = index_content_map.get(
            page_index,
            PageClassification.get_default_value(),
        )

def parse_description_content(page_task:PageBatchTask | None,pages:list[dict[str,Any]]) -> None:
    if not page_task:
        print("No add description task")
        return
    index_content_map = _build_index_content_map(page_task)
    for page in pages:
        page_index = page["index"]
        page["description"] = index_content_map.get(
            page_index,
            PageDescription.get_default_value(),
        )
    print("Page description added")

def _build_custom_id_content_map(page_task:PageBatchTask) -> dict[str,Any]:
    content_id_map = {
        result["custom_id"]: result.get("content")
        for result in page_task.contents if "custom_id" in result
    }
    return content_id_map

def _build_index_content_map(page_task:PageBatchTask) -> dict[int,Any]:
        content_id_map = _build_custom_id_content_map(page_task)
        index_content_map = {
            page["index"]:content_id_map[custom_id]
            for custom_id,page in zip(page_task.custom_ids,page_task.pages) if custom_id in content_id_map
        }
        return index_content_map
