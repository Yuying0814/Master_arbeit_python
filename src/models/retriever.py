from typing import Any
from src.models.structuredOutputModel import StructuredOutputModel
from src.models.register_output import RegisterMapItem

# retriever input
class RetrievalRequest(StructuredOutputModel):
    request_id: str
    topics:list[RetrievalTopic]

class RetrievalTopic(StructuredOutputModel):
    topic_name:str
    topic_description:str

# retriever output
class RetrievalResponse(StructuredOutputModel):
    request_id: str
    registers:list[RegisterMapItem]
    pages:list[dict[str,Any]]