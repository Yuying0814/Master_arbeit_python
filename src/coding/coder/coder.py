from models.coder import CodeFile
from src.models.coder import CoderInput,CodeFile,FilePlannerInput,FilePlan,FileCoderInput,FileCoderOutput
from src.models.planner import ProgrammingPlan
from src.models.retriever import RetrievalResponse
from src.models.verifier import VerificationRequest, VerifierOutput
from src.coding.coder.file_coder import FileCoder
from src.coding.coder.file_planner import FilePlanner



class Coder:
    # unchanged after run()
    planner: FilePlanner
    coder: FileCoder
    programming_plan: ProgrammingPlan | None
    retrieval_result: RetrievalResponse | None
    accepted_files: list[CodeFile]

    # can change after run()
    current_file_plan_id: int
    candidate_files: list[CodeFile] | None
    feedback: VerifierOutput | None
    code_passed: bool = False

    def __init__(self,api_key:str):
        self.planner = FilePlanner(api_key=api_key)
        self.coder = FileCoder(api_key=api_key)
        self.reset()

    def reset(self):
        self.programming_plan = None
        self.retrieval_result = None
        self.candidate_files = []
        self.accepted_files = []
        self.current_file_plan_id = 0
        self.feedback = None

    def start_plan(self,coder_input:CoderInput):
        self.programming_plan = coder_input.programming_plan
        self.retrieval_result = coder_input.retrieval_result
        self.accepted_files = coder_input.accepted_files

    def run(self):
        self.candidate_files = []

    def send_verification_request(self):
        return VerificationRequest(
            programming_plan=self.programming_plan,
            retrieval_result=self.retrieval_result,
            candidate_files=self.candidate_files,
            accepted_files=self.accepted_files,
        )

    def receive_feedback(self,feedback:VerifierOutput):
        self.feedback = feedback
        self.code_passed = feedback.passed

    def get_output(self):
        return