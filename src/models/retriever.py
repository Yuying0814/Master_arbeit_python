from typing import Any
from src.models.structuredOutputModel import StructuredOutputModel
from src.models.register_output import RegisterMapItem

# retriever input
class RetrievalRequest(StructuredOutputModel):
    request_id: str
    topics:list[RetrievalTopic]

class RetrievalTopic(StructuredOutputModel):
    topic_keywords: list[str]
    topic_description:str

# binary classifier output
class BinaryClassifierOutput(StructuredOutputModel):
    result:list[bool]

# retriever output
class RetrievalResponse(StructuredOutputModel):
    request_id: int
    results:list[RetrievalResult]

class RetrievalResult(StructuredOutputModel):
    topic: RetrievalTopic
    pages:list[dict[str,Any]]