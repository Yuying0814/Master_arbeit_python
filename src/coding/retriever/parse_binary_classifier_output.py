from typing import Any
from src.models.batch import UserRequest
from src.models.retriever import BinaryClassifierOutput


def parse_binary_classifier_output(contents: list[dict[str,Any]],retrieval_requests:list[UserRequest],len_topics:int) -> list[list[int]]:
    results = []

    id_output_map = build_custom_id_output_map(contents)
    for user_request in retrieval_requests:
        if user_request.custom_id in id_output_map:
            content = id_output_map[user_request.custom_id]
            result = BinaryClassifierOutput.model_validate_json(content).result
            results.append(result)
        else:
            results.append([False]*len_topics)

    page_indices = []
    for topic_index in range(len_topics):
        page = []
        for index,result in enumerate(results):
            if result[topic_index]:
                page.append(index)

        page_indices.append(page)

    return page_indices

def build_custom_id_output_map(contents: list[dict[str,Any]]) -> dict[str,Any]:
    return {
        item["custom_id"]: item.get("content") for item in contents if "custom_id" in item
    }