
from src.coding.config import Config
from src.coding.verifier.verifier import FakeVerifier
from src.coding.planner.planner import FakePlanner
from src.coding.retriever.retriever import FakeRetriever
from src.models.controller import WorkFlowLog
from src.models.coder import CodeFile, CoderInput
from src.coding.coder.coder import FakeCoder
from src.coding.filewriter.filewriter import FileWriter

class Controller:
    user_request:str = ""
    logs: list[WorkFlowLog]
    accepted_files: list[CodeFile]
    not_accepted_files: list[CodeFile]
    max_tries: int = 10
    config:Config


    def __init__(self,user_request,config:Config):
        self.user_request = user_request
        self.logs = []
        self.accepted_files = []
        self.config = config

    def main(self):
        planner = FakePlanner(self.config.get_apikey("openai"))

        planner_output = planner.create_plan(self.user_request)
        programming_plans = planner_output.ProgrammingPlans

        retrieval_requests = planner_output.RetrievalRequests

        #
        retriever = FakeRetriever(self.config.get_apikey("openai"))


        for programming_plan,retrieval_request in zip(programming_plans, retrieval_requests):

            retrieval_result = retriever.run(retrieval_request)

            coder = FakeCoder(self.config.get_apikey("openai"))

            verifier = FakeVerifier(self.config.get_apikey("openai"))

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

        FileWriter.write_to_files(self.accepted_files,)



    def receive_user_request(self,user_request:str):
        self.user_request = user_request