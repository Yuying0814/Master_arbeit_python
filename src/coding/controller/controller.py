from typing import Any

from src.coding.config import CodingConfig
from src.coding.planner.planner import Planner
from src.coding.retriever.retriever import PageRetriever
from src.coding.coder.coder import Coder
from src.coding.filewriter.filewriter import FileWriter
from src.coding.verifier.verifier import Verifier

from src.models.coding_common import ProgrammingPlan,VerificationPlan,CodeFile
from src.models.register_output import RegisterMapOutput
from src.models.planner import PlannerInput
from src.models.retriever import RetrievalResult
from src.models.coder import CoderInput,CoderOutput
from src.models.verifier import VerifierInput,VerifierOutput

class Controller:
    candidate_files: list[CodeFile]
    accepted_files: list[CodeFile]
    max_tries: int = 10
    logs: list
    config:CodingConfig

    def __init__(self,driver_name:str,config:CodingConfig,pages:list[dict[str,Any]],register_map:RegisterMapOutput):
        self.logs = []
        self.candidate_files = []
        self.accepted_files = []
        self.config = config
        self.not_accepted_files = []

        self.driver_name = driver_name
        self.pages = pages
        self.register_map = register_map

        self._load_agents()

        self._check_valid_client()
        self._check_valid_fqbn()

    async def run(self,user_request:str = None):
        verifier_feedback = None

        for attempt in range(1,self.max_tries+1):

            planner_input = self._build_planner_input(user_request,verifier_feedback)
            planner_output = self.planner.create_plan(planner_input)

            programming_plan = planner_output.programming_plan
            topics = planner_output.retrieval_topics
            verification_plan = planner_output.verification_plan

            retrieval_response = await self.retriever.run(topics)
            retrieval_results = retrieval_response.results

            coder_input = self._build_coder_input(programming_plan,retrieval_results)
            coder_output = self.coder.create_code_file(coder_input)

            self._update_candidate_files(coder_output)

            verifier_input = self._build_verifier_input(verification_plan,retrieval_results)
            verifier_output = self.verifier.run(verifier_input)

            if verifier_output.passed:
                self.accepted_files = list(self.candidate_files)
                self._update_logs()
                break
            else:
                self._update_logs()
            verifier_feedback = verifier_output

        if len(self.accepted_files) > 0:
            FileWriter.write_to_files(self.accepted_files,self.config.project_path.code_dir/f"{self.driver_name}")



    def _load_agents(self):
        task_configs = self.config.task_configs
        self.planner = Planner.load_from_task_config(
            task_config=task_configs.planning,
            api_key=self.config.get_apikey(task_configs.planning.model.provider),
            tools=None,
        )

        self.retriever = PageRetriever.load_from_task_config(
            pages=self.pages,
            task_config=task_configs.retrieval,
            api_key=self.config.get_apikey(task_configs.retrieval.model.provider),
            input_path=self.config.project_path.input_path / "retrieval.jsonl"
        )

        self.coder = Coder.load_from_task_config(
            task_config=task_configs.coding,
            api_key=self.config.get_apikey(task_configs.coding.model.provider),
            tools=None,
        )

        self.verifier = Verifier.load_from_task_config(
            semantic_config=task_configs.verification_semantic,
            execution_config=task_configs.verification_test_coder,
            enable_test_coder=self.config.enable_test_coder,
            cli_path=self.config.project_path.cli_path,
            fqbn=self._build_fqbn(),
            api_key_semantic=self.config.get_apikey(task_configs.verification_semantic.model.provider),
            api_key_test_coder = self.config.get_apikey(task_configs.verification_test_coder.model.provider),
            semantic_tools=None,
            execution_tools=None,
        )

    def _build_planner_input(self,user_request:str|None,verifier_feedback:VerifierOutput|None) -> PlannerInput:
        if user_request is None:
            user_request = (
                "Generate an Arduino Wire.h-based sensor driver library. "
                "Create the required .h and .cpp driver files and an .ino sketch file for compilation verification."
            )

        return PlannerInput(
            user_request=user_request,
            register_map=self.register_map,
            candidate_files=self.candidate_files,
            accepted_files=self.accepted_files,
            verifier_feedback=verifier_feedback,
        )

    def _build_coder_input(self,programming_plan:ProgrammingPlan,retrieval_results:list[RetrievalResult]) -> CoderInput:
        return CoderInput(
            programming_plan=programming_plan,
            register_map=self.register_map,
            retrieval_result=retrieval_results,
            candidate_files=self.candidate_files,
            accepted_files=self.accepted_files,
        )

    def _build_verifier_input(self,verification_plan:VerificationPlan,retrieval_results:list[RetrievalResult]) -> VerifierInput:
        return VerifierInput(
            verification_plan=verification_plan,
            register_map=self.register_map,
            retrieval_results=retrieval_results,
            candidate_files=self.candidate_files,
            accepted_files=self.accepted_files,
        )

    def _update_candidate_files(self, coder_output:CoderOutput) -> None:
        files = coder_output.candidate_files
        candidate_files_by_id = {
            candidate_file.file_id: candidate_file
            for candidate_file in self.candidate_files
        }

        for code_file in files:
            candidate_files_by_id[code_file.file_id] = code_file

        self.candidate_files = list(candidate_files_by_id.values())

    def _update_logs(self) -> None:
        pass

    def _check_valid_client(self):
        pass

    def _build_fqbn(self):
        return f"arduino:{self.config.core}:{self.config.board}"

    def _check_valid_fqbn(self):
        pass