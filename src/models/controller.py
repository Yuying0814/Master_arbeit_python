from __future__ import annotations
from typing import Any

from src.models.retriever import RetrievalTopic
from src.models.structuredOutputModel import StructuredOutputModel
from src.models.coding_common import CodeFile, ProgrammingPlan, VerificationPlan
from src.models.verifier import VerifierOutput

class ControllerLog(StructuredOutputModel):
    driver_name: str
    attempt:int
    snapshot:Snapshot
    details: SubLogs
    token_consumption:TokenConsumption

class Snapshot(StructuredOutputModel):
    programming_plan:ProgrammingPlan
    verification_plan:VerificationPlan
    retrieval_topics:list[RetrievalTopic]
    candidate_files:list[CodeFile]
    accepted_files:list[CodeFile]
    verifier_feedback:VerifierOutput
    passed:bool

class SubLogs(StructuredOutputModel):
    planner_log:Any
    retriever_log:Any
    coder_log:Any
    verifier_log:Any

class TokenConsumption(StructuredOutputModel):
    planner:dict[str, Any]
    retriever:dict[str, Any]
    coder:dict[str, Any]
    verifier:dict[str, Any]


