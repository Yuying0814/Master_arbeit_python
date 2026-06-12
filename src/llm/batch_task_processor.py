from typing import Protocol
from src.models.batch import UserRequest


class BatchTaskProcessor(Protocol):
    def run_batch(self):
        ...

    def add_user_requests(self, user_requests: list[UserRequest]) -> None:
        ...


class BatchTask:
    processor: BatchTaskProcessor

    def __init__(self, processor: BatchTaskProcessor) -> None:
        self.processor = processor

    def run(self):
        self.processor.run_batch()

