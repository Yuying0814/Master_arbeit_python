from typing import Any

from src.models.structuredOutputModel import StructuredOutputModel
from src.models.preprocessing.register_output import RegisterMapOutput
from src.models.preprocessing.preprocessor import PreprocessorSnapshot,TaskModelsByName,PreprocessingTokenConsumption
from src.models.llm.common import NormalizedTokenConsumption


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
    snapshot_json: PreprocessorSnapshot
    snapshot_created_at: str
    token_consumption: NormalizedTokenConsumption

class MajorVersionResult(StructuredOutputModel):
    device_name: str
    version_major: int
    documents: list[DocumentRecord]
    register_maps: list[RegisterMapRecord]

class VersionInfo(StructuredOutputModel):
    device_name:str
    version_pk:int
    version_major:int
    version_minor:int
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
    snapshot: PreprocessorSnapshot

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
    version_major: int
    version_minor: int

class RenumberedMajorVersion(StructuredOutputModel):
    old_version_major:int
    new_version_major:int

class MajorVersionDeletionRecord(StructuredOutputModel):
    deleted_versions:int
    renumbered_major_versions: list[RenumberedMajorVersion]
