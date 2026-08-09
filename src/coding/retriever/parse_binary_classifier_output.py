from typing import Any

from src.models.retriever import BinaryClassifierOutput


def parse_binary_classifier_output(
    contents: list[dict[str, Any]],
    retrieval_requests: dict[str, Any],
    len_topics: int,
) -> dict[str,list[list[int]]]:

    user_requests = retrieval_requests["user_requests"]
    request_references = retrieval_requests["request_references"]

    id_output_map = build_custom_id_output_map(contents)

    raw_results: list[list[bool]] = []
    for user_request in user_requests:
        content = id_output_map.get(user_request.custom_id)

        if content is None:
            raw_results.append([False] * len_topics)
            continue

        structured_output = parse_binary_output_content(content) # BinaryClassifierOutput
        result = structured_output.result # result is a field of BinaryClassifierOutput, list[bool], relevance to topics in one page
        raw_results.append(normalize_binary_result(result, len_topics))

    pdf_sha256_page_indices = {}
    for request_reference,raw_result in zip(request_references, raw_results):

        topic_page_indices = pdf_sha256_page_indices.setdefault(
            request_reference.pdf_sha256,
            [[]for _ in range(len_topics)],
        )

        for topic_index,is_relevant in enumerate(raw_result):
            topic_page_indices[topic_index].append(request_reference.page_index)

    return pdf_sha256_page_indices


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