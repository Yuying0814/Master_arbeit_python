from __future__ import annotations
from typing import Any

from src.models.llm.batch import UserRequest
from src.models.preprocessing.page_output import PageClassification, PageDescription

def parse_verification_contents(
        contents: list[dict[str,Any]],
        user_requests: list[UserRequest],
        pages:list[dict[str,Any]]) ->list[int]:

    custom_id_content_map = _build_custom_id_content_map(
        contents=contents
    )

    page_index_content_map = _build_index_content_map(
        custom_id_content_map=custom_id_content_map,
        user_requests=user_requests,
        pages=pages
    )

    return [page_index for page_index,content in page_index_content_map.items() if str(content).strip().lower() == "yes"]

def parse_classification_content(
        contents: list[dict[str,Any]],
        user_requests: list[UserRequest],
        pages:list[dict[str,Any]]) -> None:

    custom_id_content_map = _build_custom_id_content_map(
        contents=contents
    )

    page_index_content_map = _build_index_content_map(
        custom_id_content_map = custom_id_content_map,
        user_requests = user_requests,
        pages = pages
    )

    for page in pages:
        page_index = page["index"]
        page["classification"] = page_index_content_map.get(
            page_index,
            PageClassification.get_default_value()
        )

# def parse_description_content(page_task:PageBatchTask | None,pages:list[dict[str,Any]]) -> None:
#     if not page_task:
#         print("No add description task\n")
#         return
#     index_content_map = _build_index_content_map(page_task)
#     for page in pages:
#         page_index = page["index"]
#         page["description"] = index_content_map.get(
#             page_index,
#             PageDescription.get_default_value(),
#         )
#     print("Page description added\n")

def _build_custom_id_content_map(contents: list[dict[str,Any]]) -> dict[str,Any]:
    return {
        item["custom_id"]: item.get("content") for item in contents if "custom_id" in item
    }

def _build_index_content_map(
        custom_id_content_map:dict[str,dict[str,Any]],
        user_requests: list[UserRequest],
        pages:list[dict[str,Any]]) -> dict[int,Any]:

        return {
            page["index"]: custom_id_content_map.get(
                user_request.custom_id,
                PageClassification.get_default_value()
            )
            for user_request,page in zip(user_requests,pages)
        }
