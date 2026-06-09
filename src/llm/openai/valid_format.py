from typing import Any, TypeAlias, Literal
from src.models.structuredOutputModel import StructuredOutputModel

ValidOutputFormat: TypeAlias = (
       Literal["text", "json"] | dict[str, Any] | StructuredOutputModel | type[StructuredOutputModel]
)