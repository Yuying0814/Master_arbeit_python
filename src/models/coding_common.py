from __future__ import annotations
from pydantic import Field
from typing import Literal

from src.models.structuredOutputModel import StructuredOutputModel
class IncompleteImplementation(StructuredOutputModel):

    target_section: str = Field(
        description="Name of the incomplete target section location.",
    )

    target_function: str = Field(
        description="Name of the incomplete target function. Use an empty string if the issue is not function-specific.",
    )

    description: str = Field(
        description="Description of what has been implemented so far in this item and what remains unimplemented.",
    )

    reason: str = Field(
        description="Reason why the planned operation could not be fully implemented.",
    )

class CodeFile(StructuredOutputModel):
    file_id: str = Field(
        description="identifier of the current code file",
    )
    name: str = Field(
        description="name of the current code file",
    )
    file_type: str = Field(
        description="type of the current code file, .ino, .cpp or .h",
    )
    description: str = Field(
        description="short functional description of the current code file",
    )
    content: str = Field(
        description="content of the current code file",
    )
    incomplete_implementation: list[IncompleteImplementation] = Field(
        default_factory=list,
        description="Planned target operations that could not be fully implemented in this coding iteration.",
    )

class Operation(StructuredOutputModel):
    operation: Literal["delete", "modify", "create"] = Field(
        description="Operation type.",
    )
    description: str = Field(
        description="Short description of the current operation.",
    )

class ProgrammingPlan(StructuredOutputModel):
    programming_instructions: str|None = Field(
        default = None,
        description="an brief instruction to the following coder",
    )

    file_plans: list[FilePlan] = Field(
        default_factory=list,
        description="file plan for creating new code files, deleting existing files or modifying target files",
    )

class FilePlan(StructuredOutputModel):
    description: str = Field(
        default=None,
        description="short description of the current file plan",
    )
    target_files: list[TargetFile] = Field(
        default_factory=list,
        description="files to be modified in current file plan",
    )

class TargetFile(StructuredOutputModel):
    file_id: str = Field(
        description="identifier of the target file. when target file is a existing file, use the file id of the existing file. "
                    "otherwise create a new file id",
    )
    name: str = Field(
        description="name of the current target file",
    )
    file_type: str = Field(
        description="type of the current target file, .ino, .cpp or .h",
    )
    operation: Operation = Field(
        description="operation of the current target file."
                    "the field 'operation' of this value must be one of 'delete', 'modify', or 'create'."
                    "Files not listed in target_files must remain unchanged."
    )
    description: str = Field(
        description="short functional description of this current target file",
    )
    sections: list[FileSection] = Field(
        default_factory=list,
        description="major content sections that should appear in the target file",
    )

class FileSection(StructuredOutputModel):
    name: str = Field(
        description="name of the planned file section",
    )
    description: str = Field(
        description="purpose of this file section",
    )

    functions: list[FunctionSpec] = Field(
        default_factory=list,
        description="functions to be modified in current target file",
    )

    required: bool = Field(
        description="whether this section must be generated",
    )

class FunctionSpec(StructuredOutputModel):
    name:str = Field(
        description="name of the current target function",
    )
    description:str = Field(
        description="short functional description of this current target function",
    )
    operation: Operation = Field(
        description="operation of the current target function, "
                    " the field 'operation' of this value must be one of 'delete', 'modify', 'create' " ,
    )
    parameters:list[DataType] = Field(
        default_factory=list,
        description="input parameters for the target function",
    )
    return_type:ReturnType = Field(
        description="return type of the target function",
    )

class DataType(StructuredOutputModel):
    name:str = Field(
        description="name of the current parameter or output",
    )
    data_type:str = Field(
        description="data type of the current parameter or output",
    )
    direction: Literal["input", "output", "inout"] = Field(
        description="data flow direction of the parameter",
    )
    description:str = Field(
        description="short description of the current parameter or output",
    )
    nullable:bool = Field(
        description="whether the current parameter or output is optional",
    )
    default_value:str|None = Field(
        default=None,
        description="default value of the current parameter or output, null if no default value",
    )

class ReturnType(StructuredOutputModel):
    data_type: str = Field(
        description="return type of the function."
    )
    description: str = Field(
        description="Meaning of the return value."
    )

class VerificationPlan(StructuredOutputModel):
    semantic_plan: str = Field(
        default=None,
        description="semantic verification plan",
    )

    execution_plan: list[FilePlan] = Field(
        default_factory=list,
        description="execution verification plan.Leave this field empty if enable_test_coder is set to false",
    )