from typing import Any
from src.models.structuredOutputModel import StructuredOutputModel

# retriever input
class RetrievalTopic(StructuredOutputModel):
    topic_keywords: list[str]
    topic_description:str

class RetrievalRequest(StructuredOutputModel):
    request_id: str
    topics:list[RetrievalTopic]

# binary classifier output
class BinaryClassifierOutput(StructuredOutputModel):
    result:list[bool]

# retriever output
class RetrievalResult(StructuredOutputModel):
    topic: RetrievalTopic
    documents:list[dict[str,Any]]

class RetrievalResponse(StructuredOutputModel):
    request_id: int
    results:list[RetrievalResult]

# log
class RetrieverLog(StructuredOutputModel):
    request_id: int
    topics:list[RetrievalTopic]
    retrieval_results:list[RetrievalResult]
    token_consumption:dict[str, Any]
