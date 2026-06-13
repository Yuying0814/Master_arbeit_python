from __future__ import annotations
from dataclasses import dataclass
from typing import Any, Protocol


@dataclass
class RetrievalCandidate:
    candidate_id: str
    kind: str
    content: dict[str, Any]

class BinaryClassifier(Protocol):
    def run(self,*,query: str,candidates: list[RetrievalCandidate]) -> list[Any]:
        ...