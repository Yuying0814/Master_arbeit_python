
from src.coding.config import CodingConfig
from src.coding.verifier.verifier import Verifier
from src.coding.planner.planner import Planner
from src.coding.retriever.retriever import Retriever
from src.models.controller import WorkFlowLog
from src.models.coder import CodeFile, CoderInput
from src.coding.coder.coder import Coder
from src.coding.filewriter.filewriter import FileWriter

class Controller:
    user_request:str = ""
    logs: list[WorkFlowLog]
    accepted_files: list[CodeFile]
    not_accepted_files: list[CodeFile]
    max_tries: int = 10
    config:CodingConfig

    def __init__(self,user_request,config:CodingConfig):
        self.user_request = user_request
        self.logs = []
        self.accepted_files = []
        self.config = config
        self.not_accepted_files = []

    def main(self):
        planner = FakePlanner(self.config.get_apikey("openai"))
        retriever = FakeRetriever(self.config.get_apikey("openai"))

        planner_output = planner.create_plan(self.user_request)
        programming_plans = planner_output.ProgrammingPlans
        retrieval_requests = planner_output.RetrievalRequests

        if len(programming_plans) != len(retrieval_requests):
            raise ValueError(
                "Each programming plan must have exactly one retrieval request. "
                "Use an empty retrieval request when no retrieval is needed."
            )

        #
        for programming_plan,retrieval_request in zip(programming_plans, retrieval_requests):
            coder = FakeCoder(self.config.get_apikey("openai"))
            verifier = FakeVerifier(self.config.get_apikey("openai"))

            retrieval_result = retriever.run(retrieval_request)
            coder.start_plan(
                CoderInput(
                    programming_plan=programming_plan,
                    retrieval_result=retrieval_result,
                    accepted_files=self.accepted_files
                )
            )

            for attempt in range(1,self.max_tries+1):
                coder.run()

                verification_request = coder.send_verification_request()

                verifier.receive_request(verification_request)

                verifier.run()

                feedback = verifier.get_feedback()

                coder.receive_feedback(feedback)
                if feedback.passed:
                    break

            coder_output = coder.get_output()
            if coder_output.passed:
                self.accepted_files.extend(coder_output.files)
            else:
                self.not_accepted_files.extend(coder_output.files)

        FileWriter.write_to_files(self.accepted_files,self.config.project_path.code_dir)


    def receive_user_request(self,user_request:str):
        self.user_request = user_request