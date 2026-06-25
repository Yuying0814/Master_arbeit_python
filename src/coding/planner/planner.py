import copy

from collections.abc import Callable
from langchain_core.tools import BaseTool

from src.models.task_config import TaskConfig
from src.models.planner import PlannerOutput,PlannerInput,PlannerLog

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

    def create_plan(self,planer_input:PlannerInput) -> PlannerOutput:
        user_input = planer_input.model_dump_json()
        print(" -> start creating new plan")
        plan = self.planner_agent.run(user_input)
        self._update_logs(planer_input,plan)
        print(
            f" -> plan created\n"
            f"==================\n"
            f"plan id:\n{plan.plan_id}\n\n"
            f"retrieval topics:\n{[topic.topic_keywords for topic in plan.retrieval_topics]}\n\n"
            f"programming plan:\n{plan.programming_plan.programming_instructions}\n\n"
            f"verification plan:\n{plan.verification_plan.semantic_plan}\n\n"
            f"verification plan:\n{plan.verification_plan.execution_plan}\n\n"
            f"==================\n"
        )
        return plan

    def _update_logs(self, planner_input: PlannerInput, planner_output: PlannerOutput) -> None:
        self.logs.append(
            PlannerLog(
                planner_input=planner_input.model_copy(deep=True),
                planner_output=planner_output.model_copy(deep=True),
                token_consumption=copy.deepcopy(self.planner_agent.total_tokens),
            )
        )


