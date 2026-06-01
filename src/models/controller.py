from __future__ import annotations
from typing import Literal,Any
from src.models.structuredOutputModel import StructuredOutputModel
from src.models.planner import ProgrammingPlan
from src.models.retriever import RetrievalResponse

class WorkFlowLog(StructuredOutputModel):
    log_id: int
    module: Literal["planner", "retriever", "coder", "verifier", "controller"]
    event: str
    status: Literal["created","started", "completed", "failed"]
    programming_plan: ProgrammingPlan
    summary: str
    details: dict[str, Any]


