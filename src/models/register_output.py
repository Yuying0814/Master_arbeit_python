from pydantic import Field
from models.structuredOutputModel import StructuredOutputModel

class RegisterIndexItem(StructuredOutputModel):
    name: str
    address: str
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

class RegisterFieldValue(StructuredOutputModel):
    value: str
    value_description: str

class RegisterBitField(StructuredOutputModel):
    name_or_parameter: str
    field_description: str
    bit_start: int
    bit_end: int
    bit_width: int
    values: list[RegisterFieldValue]
    is_reserved: bool
    type_write_read: str

class RegisterSource(StructuredOutputModel):
    page_index: int

class RegisterMapItem(StructuredOutputModel):
    index: int
    name: str
    address: RegisterAddress
    register_description: str
    width_bits: int
    type_write_read: str
    bit_field: list[RegisterBitField]
    category: str
    source: list[RegisterSource]
    default_value: str
    default_value_description: str

class RegisterMapOutput(StructuredOutputModel):
    registers: list[RegisterMapItem] = Field(alias="Registers")