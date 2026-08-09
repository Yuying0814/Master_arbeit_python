from __future__ import annotations


from typing import Any
from src.models.llm.common import NormalizedUsage
from src.llm.common.types import ValidOutputFormat


def get_output_schema(output_format: ValidOutputFormat) -> dict[str, Any] | None:

    if output_format is not None:
        return output_format.model_json_schema()
    return None

def parse_output_text(content: str,output_format: ValidOutputFormat) -> Any:
    if output_format is None:
        return content

    return output_format.model_validate_json(content).model_dump()

def merge(current: list[dict[str, Any]],updates: list[dict[str, Any]],) -> None:

    current_index_map = {
        item["custom_id"]: index for index,item in enumerate(current)
    }

    for index, item in enumerate(updates):
        custom_id = item["custom_id"]
        if custom_id in current_index_map:
            index = current_index_map.get(custom_id)
            current[index] = item
        else:
            current.append(item)


def sum_normalized_usage(usages: list[NormalizedUsage]) -> NormalizedUsage:

    input_tokens = 0
    output_tokens = 0

    input_token_details: dict[str, int] = {}
    output_token_details: dict[str, int] = {}

    for usage in usages:
        input_tokens += usage.input_tokens
        output_tokens += usage.output_tokens

        for key, value in usage.input_token_details.items():
            input_token_details[key] = (
                input_token_details.get(key, 0) + value
            )

        for key, value in usage.output_token_details.items():
            output_token_details[key] = (
                output_token_details.get(key, 0) + value
            )

    return NormalizedUsage(
        input_tokens=input_tokens,
        output_tokens=output_tokens,
        total_tokens=input_tokens + output_tokens,
        input_token_details=input_token_details,
        output_token_details=output_token_details,
    )
