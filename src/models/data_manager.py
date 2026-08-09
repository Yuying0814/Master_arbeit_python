from typing import Any
from src.models.structuredOutputModel import StructuredOutputModel
from src.models.register_output import RegisterMapOutput

class DocumentRecord(StructuredOutputModel):
    version_pk: int
    version_minor: int
    pdf_sha256: str
    pages: list[dict[str, Any]]


class RegisterMapRecord(StructuredOutputModel):
    version_pk: int
    version_minor: int
    pdf_sha256: str
    register_map: RegisterMapOutput


class MajorVersionResult(StructuredOutputModel):
    device_name: str
    version_major: int
    documents: list[DocumentRecord]
    register_maps: list[RegisterMapRecord]