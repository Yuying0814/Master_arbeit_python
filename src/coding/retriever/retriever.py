from models.retriever import RetrievalRequest,RetrievalResponse
from src.models.register_output import RegisterMapItem

class FakeRetriever:
    api_key: str

    def __init__(self,api_key: str):
        self.api_key = api_key

    def run(self,retrieval_request: RetrievalRequest) -> RetrievalResponse:
        result = RetrievalResponse(
            request_id=retrieval_request.request_id,
            registers= [],
            pages = []
        )
        return result