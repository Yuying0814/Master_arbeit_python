from __future__ import annotations
import json
import math
from typing import Any

def build_json_schema(value:dict,name:str):
    return{
        "type": "json_schema",
        "name": name,
        "schema":_build_schema(value),
        "strict": True
    }

def _build_schema(value: Any) -> dict[str, Any]:

    if value == {} or value == [] or value is None:
        raise ValueError(
            "Empty examples {}, [], 'None' are not allowed."
        )

    if isinstance(value, dict):
        return _build_object_schema(value)

    if isinstance(value, (list, tuple)):
        return _build_array_schema(value)

    if isinstance(value, str):
        return {"type": "string"}

    if isinstance(value, bool):
        return {"type": "boolean"}

    if isinstance(value, int):
        return {"type": "integer"}

    if isinstance(value, float):
        if not math.isfinite(value):
            raise ValueError("Numeric examples must not contain NaN or Inf.")

        if value.is_integer():
            return {"type": "integer"}

        return {"type": "number"}

    raise TypeError(f"Unsupported JSON type: {type(value).__name__}")


def _build_object_schema(value: dict[str, Any]) -> dict[str, Any]:

    if not value:
        raise ValueError("Empty dictionaries are not allowed.")

    properties = {}

    for field_name, field_value in value.items():
        if not isinstance(field_name, str):
            raise TypeError("JSON object keys must be strings.")

        properties[field_name] = _build_schema(field_value)

    return {
        "type": "object",
        "properties": properties,
        "required": list(value.keys()),
        "additionalProperties": False,
    }


def _build_array_schema(value: list[Any] | tuple[Any, ...]) -> dict[str, Any]:

    if not value:
        raise ValueError("Empty lists are not allowed.")

    item_schemas = [_build_schema(item) for item in value]

    if _all_same(item_schemas):
        items_schema = item_schemas[0]
    else:
        items_schema = {"anyOf": item_schemas}

    return {
        "type": "array",
        "items": items_schema,
    }


def _all_same(item_schemas: list[dict[str, Any]]) -> bool:
    first_schema = json.dumps(item_schemas[0], sort_keys=True)

    for schema in item_schemas[1:]:
        current_schema = json.dumps(schema, sort_keys=True)

        if current_schema != first_schema:
            return False

    return True

def build_tools_schema(value) -> dict[str, Any]:
    pass