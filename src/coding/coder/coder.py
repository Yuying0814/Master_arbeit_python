from collections.abc import Callable
from langchain.tools import BaseTool

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
        coder_output = self.coder_agent.run(user_input)
        self._update_logs(coder_input,coder_output)
        return coder_output

    def _update_logs(self,coder_input:CoderInput,coder_output:CoderOutput)-> None:
        self.logs.append(
            CoderLog(
                coder_input=coder_input,
                coder_output=coder_output,
                token_consumption=self.coder_agent.total_tokens
            )
        )