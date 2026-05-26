from typing import Any
from pydantic import BaseModel, ConfigDict

class StructuredOutputModel(BaseModel):
    model_config = ConfigDict(extra='forbid')

    @classmethod
    def get_openai_format(cls) -> dict[str,Any]:
        schema_name:str = cls.__name__

        return{
            "type": "json_schema",
            "name": schema_name,
            "strict": True,
            "schema":cls.model_json_schema(),
        }