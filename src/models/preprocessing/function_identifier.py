from typing import Any

from pydantic import BaseModel,Field
from src.models.structuredOutputModel import StructuredOutputModel
from src.models.preprocessing.register_output import RegisterMapOutput

class FunctionIdentifierInput(BaseModel):
    pages: list[dict[str, Any]]
    register_map:RegisterMapOutput

class DeviceFunction(StructuredOutputModel):
    function_name:str = Field(description="Device function name")
    function_description: str = Field(description="Concrete description of the device function process, state changes, details")
    registers: list[str] = Field(description="Involved register names with address")

class DeviceFunctionOutput(StructuredOutputModel):
    device_functions: list[DeviceFunction] = Field(description="List of device functions")