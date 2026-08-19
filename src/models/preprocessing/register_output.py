from pydantic import Field, field_validator
from src.models.structuredOutputModel import StructuredOutputModel


class RegisterIndexItem(StructuredOutputModel):
    name: str
    is_multi_address: bool
    physical_address: list[str]
    bank: str
    page: str
    source_index: str


class RegisterIndexOutput(StructuredOutputModel):
    registers: list[RegisterIndexItem]


class RegisterAddress(StructuredOutputModel):
    hex: str
    decimal: str
    bank: str
    page: str
    description: str

    @field_validator("decimal", mode="before")
    @classmethod
    def normalize_decimal(cls, value):
        if isinstance(value, int) and not isinstance(value, bool):
            return str(value)
        return value


class RegisterFieldValue(StructuredOutputModel):
    value: str
    value_description: str


class RegisterBitField(StructuredOutputModel):
    name_or_parameter: str
    field_description: str
    bit_start: int | None
    bit_end: int | None
    bit_width: int | None
    values: list[RegisterFieldValue]
    is_reserved: bool
    type_write_read: str


class RegisterFieldPart(StructuredOutputModel):
    register_name: str
    physical_address: RegisterAddress
    description: str
    width_bits: int | None
    type_write_read: str
    bit_field: list[RegisterBitField]


class RegisterSource(StructuredOutputModel):
    page_index: int


class RegisterMapItem(StructuredOutputModel):
    index: int
    name: str
    is_multi_address: bool
    physical_address: list[RegisterAddress]
    register_description: str
    width_bits: int | None
    type_write_read: str
    field_parts: list[RegisterFieldPart]
    category: str
    source: list[RegisterSource]
    default_value: str = ""
    default_value_description: str = ""


class RegisterMapOutput(StructuredOutputModel):
    registers: list[RegisterMapItem]