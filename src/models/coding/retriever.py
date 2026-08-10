from typing import Any

from src.models.llm.batch import UserRequest, RequestReference
from src.models.structuredOutputModel import StructuredOutputModel
from src.models.coding.coding_common import InputDocument

# retriever input
class RetrievalTopic(StructuredOutputModel):
    topic_keywords: list[str]
    topic_description:str

class RetrievalRequest(StructuredOutputModel):
    request_id: str
    topics:list[RetrievalTopic]

class RetrieverUserInput(StructuredOutputModel):
    user_requests:list[UserRequest]
    request_references:list[RequestReference]

# binary classifier output
class BinaryClassifierOutput(StructuredOutputModel):
    result:list[bool]

# retriever output
class RetrievalResult(StructuredOutputModel):
    topic: RetrievalTopic
    documents:list[InputDocument]

class RetrievalResponse(StructuredOutputModel):
    request_id: int
    results:list[RetrievalResult]

# log
class RetrieverLog(StructuredOutputModel):
    request_id: int
    topics:list[RetrievalTopic]
    retrieval_results:list[RetrievalResult]
    token_consumption:dict[str, Any]
