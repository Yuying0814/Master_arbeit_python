from collections.abc import Callable
from langchain_core.tools import BaseTool

from models.task_config import TaskConfig
from src.models.planner import PlannerOutput,PlannerInput

from src.llm.llm_agent import LLMAgent

class Planner:
    planner_agent: LLMAgent
    logs = list

    def __init__(self,planner_agent: LLMAgent):
        self.planner_agent = planner_agent
        self.logs = []

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
        plan = self.planner_agent.run(user_input)
        self.update_logs()
        return plan

    def update_logs(self):
        ...


