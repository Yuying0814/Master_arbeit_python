# src/coding/retriever/classifier/openai_batch_classifier.py

from __future__ import annotations


class OpenAIBatchClassifier:

    def __init__(self, api_key: str) -> None:
        self.api_key = api_key

    def classify(self,*,query: str,candidates: list[RetrievalCandidate],) -> list[str]:
        # Build JSONL requests.
        # Submit OpenAI batch job.
        # Wait and collect outputs.
        # Parse each output into RelevanceResult.
        raise NotImplementedError