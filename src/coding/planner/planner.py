from models.controller import WorkFlowLog
from src.models.planner import PlannerOutput,ProgrammingPlan,PlannerLog
from src.models.retriever import RetrievalRequest,RetrievalTopic

class Planner:
    logs = list[PlannerLog]

    def __init__(self,api_key:str):
        pass

    def create_plan(self,user_request:str):
        pass

    def create_log(self,plans:PlannerOutput):
        self.logs.append(
            PlannerLog(
                plans= PlannerOutput(
                    ProgrammingPlans=plans.ProgrammingPlans,
                    retrieval_requests= plans.retrieval_requests
                )
            )
        )

    def create_workflow_log(self,plans:PlannerLog) -> WorkFlowLog:
        pass


