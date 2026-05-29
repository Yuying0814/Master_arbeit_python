from __future__ import annotations
from typing import Any
from src.preprocessing.page.page_batch_task import PageBatchTask
from src.models.page_output import PageClassification,PageDescription


def parse_verification_content(page_task:PageBatchTask) ->list[int]:
    index_content_map = _build_index_content_map(page_task)
    return [key for key,value in index_content_map.items() if value.strip() == "yes"]

def parse_classification_content(page_task:PageBatchTask,pages:list[dict[str,Any]]) -> None:
    index_content_map = _build_index_content_map(page_task)
    outputs = [index_content_map.get(page["index"],PageClassification.get_default_value()) for page in page_task.pages]
    for page,output in zip(pages,outputs):
        page["classification"] = output

def parse_description_content(page_task:PageBatchTask,pages:list[dict[str,Any]]) -> None:
    index_content_map = _build_index_content_map(page_task)
    outputs = [index_content_map.get(page["index"],PageDescription.get_default_value()) for page in page_task.pages]
    for page,output in zip(pages,outputs):
        page["description"] = output

def _build_custom_id_content_map(page_task:PageBatchTask) -> list[dict[str,Any]]:
    content_id_map = {
        result["custom_id"]: result["content"]
        for result in page_task.contents
    }
    return content_id_map

def _build_index_content_map(page_task:PageBatchTask) -> list[dict[str,Any]]:
        content_id_map = _build_custom_id_content_map(page_task)
        index_content_map = {
            page["index"]:content_id_map[custom_id]
            for custom_id,page in zip(page_task.custom_ids,page_task.pages) if custom_id in content_id_map
        }
        return index_content_map
