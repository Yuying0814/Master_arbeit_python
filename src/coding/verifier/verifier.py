from src.models.verifier import VerificationRequest,VerifierOutput

class Verifier():
    api_key: str
    request: VerificationRequest | None

    def __init__(self,api_key: str):
        self.api_key = api_key

    def receive_request(self,verification_request:VerificationRequest):
        self.request = verification_request

    def run(self):
        pass

    def write_test_code(self,test_code:str):
        pass

    def get_feedback(self) -> VerifierOutput:
        return VerifierOutput()

    def reset(self):
        self.request = None