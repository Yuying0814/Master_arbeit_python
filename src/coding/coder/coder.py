import copy

from collections.abc import Callable
from langchain.tools import BaseTool

from src.models.task_config import TaskConfig
from src.models.coding.coder import CoderInput, CoderOutput, CoderLog
from src.llm.llm_agent import LLMAgent

class Coder:
    coder_agent: LLMAgent
    logs:list[CoderLog]

    def __init__(self,coder:LLMAgent):
        self.coder_agent = coder
        self.logs = []
        print(f"coder created")

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

        print(f" -> start creating code files")
        coder_output = self.coder_agent.run(user_input)
        print(
            f" -> code files created\n"
            f"==================\n"
            f"generated_or_modified_files:\n"
            f"{[file.name + file.file_type for file in coder_output.candidate_files]}\n\n"
            f"deleted_file_ids:\n"
            f"{coder_output.deleted_file_ids}\n"
            f"==================\n"
        )

        self._update_logs(coder_input,coder_output)
        return coder_output

    def _update_logs(self, coder_input: CoderInput, coder_output: CoderOutput) -> None:
        self.logs.append(
            CoderLog(
                coder_input=coder_input.model_copy(deep=True),
                coder_output=coder_output.model_copy(deep=True),
                token_consumption=copy.deepcopy(self.coder_agent.total_tokens),
            )
        )
