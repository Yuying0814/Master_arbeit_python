from __future__ import annotations
from typing import Any
from src.preprocessing.page.page_batch_task import PageBatchTask
from src.models.page_output import PageClassification,PageDescription


def parse_verification_content(page_task:PageBatchTask) ->list[int]:
    content_id_map = _build_page_custom_id_map(page_task)
    return [content_id_map.get(custom_id,"").strip()=="yes" for custom_id in page_task.custom_ids]

def parse_classification_content(page_task:PageBatchTask) ->list[dict[str,bool]]:
    content_id_map = _build_page_custom_id_map(page_task)
    return [content_id_map.get(custom_id,PageClassification.get_default_value()) for custom_id in page_task.custom_ids]

def parse_description_content(page_task:PageBatchTask):
    content_id_map = _build_page_custom_id_map(page_task)
    return [content_id_map.get(custom_id,PageDescription.get_default_value()) for custom_id in page_task.custom_ids]

def _build_page_custom_id_map(page_task:PageBatchTask) -> list[dict[str,Any]]:
    content_id_map = {
        result["custom_id"]: result["content"]
        for result in page_task.contents
    }
    return content_id_map
