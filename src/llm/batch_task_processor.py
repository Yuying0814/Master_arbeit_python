from typing import Protocol
from coding.retriever.classifier_base import RetrievalCandidate


class BatchTaskProcessor(Protocol):
    def run_batch(self):
        ...

    def add_user_request(self):
        ...



class BatchTask:
    processor: BatchTaskProcessor

    def __init__(self, processor: BatchTaskProcessor) -> None:
        self.processor = processor

    def run(self):
        self.processor.run_batch()

