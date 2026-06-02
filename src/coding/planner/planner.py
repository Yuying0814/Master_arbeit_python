from models.controller import WorkFlowLog
from src.models.planner import PlannerOutput,ProgrammingPlan,PlannerLog
from src.models.retriever import RetrievalRequest,RetrievalTopic

class FakePlanner:
    logs = list[PlannerLog]

    def __init__(self,api_key:str):
        pass

    def create_plan(self,user_request:str):
        programming_plan1 = ProgrammingPlan(
            plan_id="plan_01",
            title="first plan",
            goal="first goal",
        )
        programming_plan2 = ProgrammingPlan(
            plan_id="plan_02",
            title="second plan",
            goal="second goal",
        )
        programming_plans = [programming_plan1,programming_plan2]

        topic1 = RetrievalTopic(
            topic_name="topic_01",
            topic_description="description_01",
        )

        topic2 = RetrievalTopic(
            topic_name="topic_02",
            topic_description="description_02",
        )

        topic3 = RetrievalTopic(
            topic_name="topic_03",
            topic_description="description_03",
        )

        topic4 = RetrievalTopic(
            topic_name="topic_04",
            topic_description="description_04",
        )

        retrieval_request1 = RetrievalRequest(
            request_id="request_01",
            topics=[topic1,topic2],
        )

        retrieval_request2 = RetrievalRequest(
            request_id="request_02",
            topics=[topic3,topic4],
        )

        retrieval_requests = [retrieval_request1,retrieval_request2]
        plans = PlannerOutput(
            ProgrammingPlans=programming_plans,
            retrieval_requests= retrieval_requests,
        )

        self.create_log(plans)
        return plans

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


