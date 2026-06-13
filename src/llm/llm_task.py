from typing import Protocol, Any
from pathlib import Path

from src.models.batch import UserRequest
from src.models.task_config import TaskConfig
from src.llm.normal_llm_processor import LLMTaskProcessor
from src.llm.openai.batch.async_processor import OpenAIBatchTaskProcessor
from src.llm.ollama.batch.processor import OllamaBatchTaskProcessor


class TaskProcessor(Protocol):
    async def run(self):
        ...

    def add_user_inputs(self,user_inputs: str | list[UserRequest]):
        ...

class Task:
    processor: TaskProcessor
    results: Any

    def __init__(self, processor: TaskProcessor) -> None:
        self.processor = processor

    async def run(self,user_input: str | list[UserRequest]) -> Any:
        self.processor.add_user_inputs(user_input)
        results = await self.processor.run()
        self.results = results
        return results

    @classmethod
    def load_from_task_config(cls, task_config: TaskConfig, api_key:str = None, input_path:Path = None) -> "Task":
        processor = cls.build_task_processor(
            task_config = task_config,
            api_key = api_key,
            input_path = input_path
        )
        return cls(processor)

    @staticmethod
    def build_task_processor(task_config: TaskConfig,api_key,input_path) -> TaskProcessor:
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
