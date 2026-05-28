from typing import Any, TypeAlias
from src.models.structuredOutputModel import StructuredOutputModel

ValidTextFormat: TypeAlias = (
        str | dict[str, Any] | StructuredOutputModel | type[StructuredOutputModel]
)