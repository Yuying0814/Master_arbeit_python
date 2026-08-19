import copy

from collections.abc import Callable
from langchain_core.tools import BaseTool

from src.models.task_config import TaskConfig
from src.models.coding.planner import PlannerOutput, PlannerInput, PlannerLog

from src.llm.llm_agent import LLMAgent

class Planner:
    planner_agent: LLMAgent
    logs: list

    def __init__(self,planner_agent: LLMAgent):
        self.planner_agent = planner_agent
        self.logs = []
        print("planner created")

    @classmethod
    def load_from_task_config(
            cls,
            task_config:TaskConfig,
            *,
            api_key:str = None,
            tools:list[Callable | BaseTool | dict]=None,
    ):
        planner = LLMAgent.load_from_task_config(
            task_config = task_config,
            api_key=api_key,
            tools = tools,
            thread_id="planner",
        )

        return cls(planner)

    async def create_plan_async(self,planer_input:PlannerInput) -> PlannerOutput:
        user_input = planer_input.model_dump_json()
        print(" -> start creating new plan")
        plan = await self.planner_agent.arun(user_input)
        self._update_logs(planer_input,plan)

        text = "\n".join(str(topic.topic_keywords) for topic in plan.retrieval_topics)
        print(
            f" -> plan successfully created\n"
            f"==================\n"
            f"plan id: {plan.plan_id}\n\n"
            f"retrieval topics:\n{text}\n\n"
            f"programming plan:\n{plan.programming_plan.programming_instructions}\n\n"
            f"verification plan:\n{plan.verification_plan.semantic_plan}\n\n"
            f"verification plan:\n{plan.verification_plan.execution_plan}\n"
            f"==================\n"
        )
        return plan

    def get_elapsed_time(self):
        time = self.planner_agent.elapsed_time
        self.planner_agent.elapsed_time = 0.0
        return time

    def _update_logs(self, planner_input: PlannerInput, planner_output: PlannerOutput) -> None:
        self.logs.append(
            PlannerLog(
                planner_input=planner_input.model_copy(deep=True),
                planner_output=planner_output.model_copy(deep=True),
                token_consumption=copy.deepcopy(self.planner_agent.total_tokens),
            )
        )


