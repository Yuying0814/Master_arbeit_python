from typing import Protocol, Any
from pathlib import Path

from src.models.batch import UserRequest
from src.models.task_config import TaskConfig
from src.llm.normal_llm_processor import LLMTaskProcessor
from src.llm.openai.batch.async_processor import OpenAIBatchTaskProcessor
from src.llm.ollama.batch.processor import OllamaBatchTaskProcessor


class TaskProcessor(Protocol):
    has_valid_output:bool
    async def run(self) -> Any:
        ...

    def add_user_inputs(self,user_inputs: str | list[UserRequest]):
        ...

class LLMTask:
    processor: TaskProcessor
    results: Any
    has_valid_output: bool
    total_usage: dict[str,Any]
    final_usage: dict[str,Any]

    def __init__(self, processor: TaskProcessor) -> None:
        self.processor = processor
        self.results = None
        self.has_valid_output = False
        self.token_usage = None

    async def run(self,user_input: str | list[UserRequest]) -> Any:

        self.processor.add_user_inputs(user_input)
        results = await self.processor.run()
        self.results = results
        self.has_valid_output = self.processor.has_valid_output
        self.get_token_usage()
        return results

    async def cleanup(self) -> None:
        if isinstance(self.processor, OpenAIBatchTaskProcessor):
            await self.processor.cleanup()

    @classmethod
    def load_from_task_config(cls, task_config: TaskConfig, api_key:str = None, input_path:str|Path = None) -> "LLMTask":
        processor = cls.build_task_processor(
            task_config = task_config,
            api_key = api_key,
            input_path = Path(input_path) if input_path else None,
        )
        return cls(processor)

    @staticmethod
    def build_task_processor(task_config:TaskConfig, api_key:str|None ,input_path:Path|None) -> TaskProcessor:
        if not task_config.model.is_batch:
            return LLMTaskProcessor.load_from_task_config(
                task_config = task_config,
                api_key = api_key,
            )

        match task_config.model.provider:
            case "openai":
                return OpenAIBatchTaskProcessor.load_from_task_config(
                    api_key = api_key,
                    input_path = input_path,
                    task_config = task_config,
                )
            case "ollama":
                return OllamaBatchTaskProcessor.load_from_task_config(
                    task_config = task_config,
                )
            case _:
                raise ValueError(f"Unsupported provider {task_config.model.provider}")

    def get_token_usage(self):
        self.total_usage = self.processor.total_usage
        self.final_usage = self.processor.final_usage