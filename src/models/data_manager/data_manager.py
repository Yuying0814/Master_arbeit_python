from typing import Any

from src.models.structuredOutputModel import StructuredOutputModel
from src.models.preprocessing.function_identifier import DeviceFunctionOutput
from src.models.preprocessing.register_output import RegisterMapOutput
from src.models.preprocessing.preprocessor import PreprocessorSnapshot,TaskModelsByName,PreprocessingTokenConsumption


class DocumentRecord(StructuredOutputModel):
    device_name: str
    version_pk: int
    version_major:int
    version_minor: int
    pdf_sha256: str
    pages: list[dict[str, Any]]

class RegisterMapRecord(StructuredOutputModel):
    device_name:str
    version_pk: int
    version_major: int
    version_minor: int
    pdf_sha256: str
    register_map: RegisterMapOutput


class DeviceFunctionsRecord(StructuredOutputModel):
    device_name: str
    version_pk: int
    version_major: int
    version_minor: int
    pdf_sha256: str
    device_functions: DeviceFunctionOutput

class VersionResult(StructuredOutputModel):
    device_name:str
    version_pk: int
    version_major: int
    version_minor: int
    input_pdf_sha256: str
    pages_json: list[dict[str, Any]]
    pages_json_created_at: str
    register_map_json: RegisterMapOutput
    register_map_created_at: str
    register_map_modified_at: str
    device_functions: DeviceFunctionOutput
    snapshot_json: dict[str, Any]
    snapshot_created_at: str
    token_consumption: PreprocessingTokenConsumption

class MajorVersionResult(StructuredOutputModel):
    device_name: str
    version_major: int
    documents: list[DocumentRecord]
    register_maps: list[RegisterMapRecord]
    device_functions: list[DeviceFunctionsRecord]

class VersionInfo(StructuredOutputModel):
    device_name:str
    version_pk:int
    version_major:int
    version_minor:int
    pdf_name: str
    input_pdf_sha256:str
    pages_json_created_at:str
    register_map_created_at:str
    register_map_modified_at:str
    snapshot_created_at:str

class MajorVersionNumber(StructuredOutputModel):
    device_name: str
    major_versions: tuple[int,...]

class MajorTaskModelInfo(StructuredOutputModel):
    device_name:str
    version_major:int
    task_models:TaskModelsByName

class MajorPdfInfo(StructuredOutputModel):
    device_name: str
    version_major: int
    pdfs:list[str]

class TaskModelInfo(StructuredOutputModel):
    device_name: str
    version_pk: int
    version_major: int
    version_minor: int
    task_models: TaskModelsByName

class SnapshotRecord(StructuredOutputModel):
    device_name: str
    version_pk: int
    version_major: int
    version_minor: int
    snapshot: dict[str, Any]

class PreprocessingTokenConsumptionRecord(StructuredOutputModel):
    device_name: str
    version_pk: int
    version_major: int
    version_minor: int
    token_consumption: PreprocessingTokenConsumption

class OperationFeedback(StructuredOutputModel):
    operation_name: str
    operation_id: str
    succeeded: bool = True
    details: Any

class LatestVersion(StructuredOutputModel):
    device_name: str
    version_pk: int
    version_major: int
    version_minor: int

class RenumberedMajorVersion(StructuredOutputModel):
    old_version_major:int
    new_version_major:int

class MajorVersionDeletionRecord(StructuredOutputModel):
    deleted_versions:int
    renumbered_major_versions: list[RenumberedMajorVersion]
