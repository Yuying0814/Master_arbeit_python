import json
from typing import Any

from src.models.batch import UserRequest
from src.models.retriever import BinaryClassifierOutput


def parse_binary_classifier_output(
    contents: list[dict[str, Any]],
    retrieval_requests: list[UserRequest],
    len_topics: int,
) -> list[list[int]]:
    results: list[list[bool]] = []

    id_output_map = build_custom_id_output_map(contents)

    for user_request in retrieval_requests:
        content = id_output_map.get(user_request.custom_id)

        if content is None:
            results.append([False] * len_topics)
            continue

        output = parse_binary_output_content(content)
        results.append(normalize_binary_result(output.result, len_topics))

    page_indices: list[list[int]] = []

    for topic_index in range(len_topics):
        matched_pages: list[int] = []

        for page_position, result in enumerate(results):
            if result[topic_index]:
                matched_pages.append(page_position)

        page_indices.append(matched_pages)

    return page_indices


def parse_binary_output_content(content: Any) -> BinaryClassifierOutput:
    if isinstance(content, str):
        return BinaryClassifierOutput.model_validate_json(content)

    return BinaryClassifierOutput.model_validate(content)


def normalize_binary_result(result: list[bool], expected_len: int) -> list[bool]:
    normalized = list(result[:expected_len])

    if len(normalized) < expected_len:
        normalized.extend([False] * (expected_len - len(normalized)))

    return normalized


def build_custom_id_output_map(contents: list[dict[str, Any]]) -> dict[str, Any]:
    return {
        item["custom_id"]: item.get("content")
        for item in contents
        if item.get("custom_id") and item.get("completed", False)
    }