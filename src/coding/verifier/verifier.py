import copy
from pathlib import Path
from typing import Any
from collections.abc import Callable
from langchain.tools import BaseTool

from src.models.task_config import TaskConfig
from src.models.verifier import VerifierInput, VerifierOutput, SemanticVerifierInput, ExecutionVerifierInput, \
    VerifierLog

from src.llm.llm_agent import LLMAgent

from src.coding.verifier.execution_verifier import ExecutionVerifier

class Verifier:
    semantic_verifier:LLMAgent
    execution_verifier: ExecutionVerifier
    logs:list

    def __init__(self,semantic_verifier:LLMAgent,execution_verifier:Any) -> None:
        self.semantic_verifier = semantic_verifier
        self.execution_verifier = execution_verifier
        self.logs = []
        print(f"verifier created")

    @classmethod
    def load_from_task_config(cls,
                              semantic_config:TaskConfig,
                              execution_config:TaskConfig,
                              *,
                              enable_test_coder:bool,
                              cli_path: Path,
                              fqbn: str,
                              api_key_semantic:str = None,
                              api_key_test_coder:str = None,
                              semantic_tools :list[Callable | BaseTool | dict]=None,
                              execution_tools :list[Callable | BaseTool | dict]=None,
                              ) -> "Verifier":

        semantic_verifier= LLMAgent.load_from_task_config(
            task_config=semantic_config,
            api_key=api_key_semantic,
            tools = semantic_tools,
            thread_id="semantic_verifier",
        )

        execution_verifier = ExecutionVerifier.load_from_task_config(
            task_config = execution_config,
            api_key = api_key_test_coder,
            tools = execution_tools,
            thread_id = "execution_verifier",
            enable_test_coder=enable_test_coder,
            cli_path=cli_path,
            fqbn=fqbn,

        )
        return cls(
            semantic_verifier=semantic_verifier,
            execution_verifier=execution_verifier,
        )

    def run(self,verifier_input:VerifierInput) -> VerifierOutput:
        semantic_input = _build_semantic_input(verifier_input)
        print(f"semantic verification started")
        semantic_output = self.semantic_verifier.run(semantic_input)
        print(f"semantic verification completed:{semantic_output.model_dump_json(indent=2)}")

        execution_input = _build_execution_input(verifier_input)
        execution_output = self.execution_verifier.run(execution_input)

        passed = semantic_output.passed and execution_output.candidate_code_passed
        if execution_output.test_code_passed is not None:
            passed = passed and execution_output.test_code_passed

        if execution_output.test_passed is not None:
            passed = passed and execution_output.test_passed

        verifier_output = VerifierOutput(
            passed=passed,
            semantic_result=semantic_output,
            execution_result=execution_output,
        )

        self._update_logs(verifier_input,verifier_output)
        return verifier_output

    def _update_logs(self,verifier_input:VerifierInput,verifier_output:VerifierOutput) -> None:
        self.logs.append(
            VerifierLog(
                verifier_input=verifier_input.model_copy(deep=True),
                verifier_output=verifier_output.model_copy(deep=True),
                execution_verifier_log=self.execution_verifier.log.model_copy(deep=True),
                token_consumption={
                    "semantic": copy.deepcopy(self.semantic_verifier.total_tokens),
                    "execution": copy.deepcopy(self.execution_verifier.total_tokens),
                }
            )
        )

# Helper
def _build_semantic_input(verifier_input:VerifierInput):
    return SemanticVerifierInput(
        verification_plan=verifier_input.verification_plan.semantic_plan,
        register_map=verifier_input.register_map,
        retrieval_results=verifier_input.retrieval_results,
        candidate_files=verifier_input.candidate_files,
        accepted_files=verifier_input.accepted_files,
    ).model_dump_json()

def _build_execution_input(verifier_input:VerifierInput):
   return ExecutionVerifierInput(
       verification_plan=verifier_input.verification_plan.execution_plan,
       candidate_files=verifier_input.candidate_files,
       accepted_files=verifier_input.accepted_files,
   )