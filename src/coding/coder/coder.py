from collections.abc import Callable
from langchain.tools import BaseTool

from src.models.task_config import TaskConfig
from src.models.coder import CoderInput
from src.llm.llm_agent import LLMAgent

class Coder:
    coder_agent: LLMAgent
    log:list

    def __init__(self,coder:LLMAgent):
        self.coder_agent = coder
        self.log = []

    @classmethod
    def load_from_task_config(
            cls,
            task_config: TaskConfig,
            *,
            api_key: str = None,
            tools: list[Callable | BaseTool | dict] = None,
    ):
        coder_agent = LLMAgent.load_from_task_config(
            task_config=task_config,
            api_key=api_key,
            tools=tools,
            thread_id="coder",
        )

        return cls(coder_agent)

    def create_code_file(self,coder_input:CoderInput):
        user_input = coder_input.model_dump_json()
        candidate_files = self.coder_agent.run(user_input)
        self.update_logs()
        return candidate_files

    def update_logs(self):
        ...