from typing import Protocol, Any

from src.models.batch import UserRequest
from src.models.task_config import TaskConfig


class TaskProcessor(Protocol):
    async def run(self):
        ...

    def add_user_inputs(self,user_inputs: str | list[UserRequest]):
        ...

class Task:
    processor: TaskProcessor

    def __init__(self, processor: TaskProcessor) -> None:
        self.processor = processor

    async def run(self,user_input: str | list[UserRequest]) -> Any:
        self.processor.add_user_inputs(user_input)
        return await self.processor.run()

    @classmethod
    def load_from_task_config(cls, task_config: TaskConfig) -> "Task":
        processor = Task.build_batch_task_processor(task_config)
        return cls(processor)

    @staticmethod
    def build_batch_task_processor(task_config: TaskConfig) -> TaskProcessor:
        raise NotImplementedError("Subclasses must implement build_batch_task_processor().")
