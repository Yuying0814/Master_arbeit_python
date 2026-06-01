
from __future__ import annotations
from src.models.structuredOutputModel import StructuredOutputModel
from src.models.retriever import RetrievalRequest

# Planner Output
class PlannerOutput(StructuredOutputModel):
    ProgrammingPlans: list[ProgrammingPlan]
    retrieval_requests: list[RetrievalRequest]

class ProgrammingPlan(StructuredOutputModel):
    plan_id: str
    title: str
    goal: str

# Planner log
class PlannerLog(StructuredOutputModel):
    plans: PlannerOutput