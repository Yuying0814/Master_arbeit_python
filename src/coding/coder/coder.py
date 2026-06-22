from collections.abc import Callable
from langchain.tools import BaseTool

from models.coding_common import ProgrammingPlan, CodeFile
from src.models.task_config import TaskConfig
from src.models.coder import CoderInput,CoderOutput,CoderLog
from src.llm.llm_agent import LLMAgent

class Coder:
    coder_agent: LLMAgent
    logs:list[CoderLog]

    def __init__(self,coder:LLMAgent):
        self.coder_agent = coder
        self.logs = []

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

    def create_code_file(self,coder_input:CoderInput)-> CoderOutput:
        user_input = coder_input.model_dump_json()
        candidate_files = self.coder_agent.run(user_input)
        self._update_logs(coder_input,candidate_files)
        return candidate_files

    def _update_logs(self,coder_input:CoderInput,candidate_files:list[CodeFile])-> None:
        self.logs.append(
            CoderLog(
                coder_input=coder_input,
                coder_output=candidate_files,
                token_consumption=self.coder_agent.total_tokens
            )
        )