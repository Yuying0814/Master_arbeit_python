from __future__ import annotations

import json
from typing import Any
from src.llm.common.types import ValidOutputFormat


def get_output_schema(output_format: ValidOutputFormat) -> dict[str, Any] | None:

    if output_format is not None:
        return output_format.model_json_schema()
    return None

def parse_output_text(content: str,output_format: ValidOutputFormat) -> Any:
    if output_format is None:
        return content

    parsed = json.loads(content)
    return output_format.model_validate(parsed).model_dump()

def merge_contents(
    current: list[dict[str, Any]],
    updates: list[dict[str, Any]],
) -> None:

    update_map = {
        item["custom_id"]: item
        for item in updates
    }

    for index, item in enumerate(current):
        replacement = update_map.get(item["custom_id"])
        if replacement is not None:
            current[index] = replacement


def sum_normalized_usage(usages: list[dict[str, Any]]) -> dict[str, Any]:

    total = {
        "input_tokens": 0,
        "output_tokens": 0,
        "total_tokens": 0,
        "input_tokens_details": {
            "cached_tokens": 0,
        },
        "output_tokens_details": {
            "reasoning_tokens": 0,
        },
    }

    for usage in usages:
        input_tokens = int(usage.get("input_tokens", 0) or 0)
        output_tokens = int(usage.get("output_tokens", 0) or 0)
        total_tokens = int(
            usage.get("total_tokens", input_tokens + output_tokens)
            or input_tokens + output_tokens
        )
        cached_tokens = int(
            usage
            .get("input_tokens_details", {})
            .get("cached_tokens", 0)
            or 0
        )
        reasoning_tokens = int(
            usage
            .get("output_tokens_details", {})
            .get("reasoning_tokens", 0)
            or 0
        )

        total["input_tokens"] += input_tokens
        total["output_tokens"] += output_tokens
        total["total_tokens"] += total_tokens
        total["input_tokens_details"]["cached_tokens"] += cached_tokens
        total["output_tokens_details"]["reasoning_tokens"] += reasoning_tokens

    return total
