import copy
import time
import asyncio
from pathlib import Path
from typing import Any
from collections.abc import Callable
from langchain.tools import BaseTool


from src.models.task_config import TaskConfig
from src.models.coding.verifier import VerifierInput, VerifierOutput, SemanticVerifierInput, ExecutionVerifierInput, \
    VerifierLog
from src.llm.llm_agent import LLMAgent

from src.coding.config import ArduinoBoardConfig
from src.coding.verifier.execution_verifier import ExecutionVerifier

class Verifier:
    semantic_verifier:LLMAgent
    execution_verifier: ExecutionVerifier
    logs:list

    def __init__(self,semantic_verifier:LLMAgent,execution_verifier:Any) -> None:
        self.semantic_verifier = semantic_verifier
        self.execution_verifier = execution_verifier
        self.logs = []
        self.elapsed_time = 0.0
        print(f"verifier created")

    @classmethod
    def load_from_task_config(
            cls,
            driver_name:str,
            semantic_config:TaskConfig,
            execution_config:TaskConfig,
            *,
            enable_test_coder:bool,
            cli_path: Path,
            board_config: ArduinoBoardConfig,
            api_key_semantic:str|None = None,
            api_key_test_coder:str|None = None,
            semantic_tools :list[Callable | BaseTool | dict] | None=None,
            execution_tools :list[Callable | BaseTool | dict] | None=None,
    ) -> "Verifier":

        semantic_verifier= LLMAgent.load_from_task_config(
            task_config=semantic_config,
            api_key=api_key_semantic,
            tools = semantic_tools,
            thread_id="semantic_verifier",
        )

        execution_verifier = ExecutionVerifier.load_from_task_config(
            driver_name = driver_name,
            task_config = execution_config,
            api_key = api_key_test_coder,
            tools = execution_tools,
            thread_id = "execution_verifier",
            enable_test_coder=enable_test_coder,
            cli_path=cli_path,
            board_config=board_config,
        )
        return cls(
            semantic_verifier=semantic_verifier,
            execution_verifier=execution_verifier,
        )

    async def run_async(self,verifier_input:VerifierInput) -> VerifierOutput:
        start_time = time.perf_counter()

        try:
            print(f" -> start verifying code files")
            semantic_input = _build_semantic_input(verifier_input)
            print(f" ->-> start semantic verification")
            semantic_output = await self.semantic_verifier.arun(semantic_input)
            print(
                f" ->-> semantic verification completed\n"
                f"==================\n"
                f"passed: \n"
                f"{semantic_output.passed}\n\n"
                f"feedback: \n"
                f"{semantic_output.feedback}\n"
                f"==================\n"
            )

            execution_input = _build_execution_input(verifier_input)
            execution_output = await asyncio.to_thread(
                self.execution_verifier.run,
                execution_input,
            )

            execution_passed = execution_output.candidate_code_passed

            if execution_output.test_code_passed is not None:
                execution_passed = execution_passed and execution_output.test_code_passed

            if execution_output.test_passed is not None:
                execution_passed = execution_passed and execution_output.test_passed

            passed = semantic_output.passed and execution_passed

            verifier_output = VerifierOutput(
                passed=passed,
                semantic_result=semantic_output,
                execution_result=execution_output,
            )

            print(
                f" -> verification completed\n"
                f"==================\n"
                f"passed: {passed}\n"
                f"semantically passed: {semantic_output.passed}\n"
                f"execution passed: {execution_passed}\n"
                f"  - candidate code compiled: {execution_output.candidate_code_passed}\n"
                f"  - test code compiled: {execution_output.test_code_passed}\n"
                f"  - test passed: {execution_output.test_passed}\n"
                f"==================\n"
            )

            self._update_logs(verifier_input,verifier_output)
        finally:
            self.elapsed_time = time.perf_counter() - start_time
        return verifier_output

    def get_elapsed_time(self) -> float:
        value = self.elapsed_time
        self.elapsed_time = 0.0
        return value

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
def _build_semantic_input(verifier_input: VerifierInput) -> str:
    return SemanticVerifierInput(
        user_request=verifier_input.user_request,
        device_functions=verifier_input.device_functions,
        programming_plan=verifier_input.programming_plan,
        verification_plan=verifier_input.verification_plan.semantic_plan,
        register_maps=verifier_input.register_maps,
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
