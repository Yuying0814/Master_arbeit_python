from __future__ import annotations
from typing import Any

from pydantic import Field

from src.models.structuredOutputModel import StructuredOutputModel
from src.models.coding.coding_common import CodeFile, ProgrammingPlan, VerificationPlan
from src.models.coding.function_identifier import FunctionIdentifierLog,DeviceFunctionOutput
from src.models.coding.planner import PlannerLog
from src.models.coding.coder import CoderLog
from src.models.coding.verifier import VerifierOutput, VerifierLog
from src.models.coding.retriever import RetrievalTopic, RetrieverLog

class ControllerLog(StructuredOutputModel):
    driver_name: str
    attempt:int
    snapshot:Snapshot
    details: SubLogs
    token_consumption:TokenConsumption

class Snapshot(StructuredOutputModel):
    device_functions:DeviceFunctionOutput|None
    programming_plan:ProgrammingPlan | None
    verification_plan:VerificationPlan | None
    retrieval_topics:list[RetrievalTopic] | None
    candidate_files:list[CodeFile] | None
    accepted_files:list[CodeFile] | None
    verifier_feedback:VerifierOutput | None
    passed:bool = Field(default=False)

class SubLogs(StructuredOutputModel):
    function_identifier:FunctionIdentifierLog| None = Field(default=None)
    planner_log:PlannerLog|None = Field(default=None)
    retriever_log:RetrieverLog|None = Field(default=None)
    coder_log:CoderLog|None = Field(default=None)
    verifier_log:VerifierLog|None = Field(default=None)

class TokenConsumption(StructuredOutputModel):
    planner:dict[str, Any]
    retriever:dict[str, Any]
    coder:dict[str, Any]
    verifier:dict[str, Any]


