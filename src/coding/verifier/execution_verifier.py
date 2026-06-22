"""Dependency:
- Arduino CLI
- Arduino core for the target board
- Target board FQBN """
import json
import subprocess
import tempfile
from pathlib import Path
from typing import Any
from collections.abc import Callable
from langchain.tools import BaseTool

from src.models.task_config import TaskConfig
from src.models.verifier import TestCoderInput,TestCoderOutput,ExecutionVerifierInput,ExecutionVerifierOutput,CompilerMsg,ExecutionVerifierLog,TestCoderLog
from src.llm.llm_agent import LLMAgent
from src.coding.filewriter.filewriter import FileWriter


class ExecutionVerifier:
    test_coder_config: dict[str,Any]
    enable_test_coder:bool
    cli_path: Path
    fqbn:str
    temp_dir:Path
    max_coding_retries: int = 10
    total_tokens: dict[str,Any]
    log:ExecutionVerifierLog

    def __init__(self,test_coder_config:dict[str,Any],enable_test_coder:bool,cli_path:Path,fqbn:str):
        self.test_coder_config = test_coder_config
        self.test_dir = ""
        self.enable_test_coder = enable_test_coder
        self.cli_path = cli_path
        self.fqbn = fqbn
        self.total_tokens = {}
        self.log = ExecutionVerifierLog(
            enable_test_coder=self.enable_test_coder,
            execution_input=ExecutionVerifierInput(),
            execution_output=ExecutionVerifierOutput(),
            test_coder_logs=[]
        )

    @classmethod
    def load_from_task_config(
            cls,
            task_config: TaskConfig,
            *,
            api_key:str = None,
            tools:list[Callable | BaseTool | dict]=None,
            thread_id:str,
            enable_test_coder:bool,
            cli_path: Path,
            fqbn: str,
    ) -> "ExecutionVerifier":

        test_coder_config = {
            "task_config" : task_config,
            "tools" : tools,
            "api_key" : api_key,
            "thread_id" : thread_id
        }
        return cls(
            test_coder_config = test_coder_config,
            enable_test_coder = enable_test_coder,
            cli_path = cli_path,
            fqbn = fqbn
        )

    def run(self,execution_verifier_input:ExecutionVerifierInput) -> ExecutionVerifierOutput:
        self._update_log(
            execution_input=execution_verifier_input,
        )

        with tempfile.TemporaryDirectory(prefix="arduino_verify_") as temp_root:
            self.test_dir = Path(temp_root) / "verification_test"

            files = execution_verifier_input.candidate_files
            FileWriter.write_to_files(
                code_files=files,
                output_dir=self.test_dir)
            compiler_message = self._compiler_run()

            if not compiler_message.passed:
                test_result = ExecutionVerifierOutput(
                    candidate_code_passed=False,
                    compiler_message=compiler_message,
                )
                self._update_log(
                    execution_verifier_output=test_result,
                )

                return test_result

            if self.enable_test_coder:
                test_coder_output = self.run_test_coder(execution_verifier_input)
                test_result =  self.run_test(test_coder_output)
                self._update_log(
                    execution_verifier_output=test_result,
                )
                return test_result

            test_result = ExecutionVerifierOutput(
                candidate_code_passed=True,
                compiler_message=compiler_message,
            )
            self._update_log(
                execution_verifier_output=test_result,
            )

            return test_result

    def run_test_coder(self,execution_verifier_input:ExecutionVerifierInput) -> TestCoderOutput:
        logs = []
        compiler_msg = CompilerMsg()
        test_coder_output = TestCoderOutput()

        self._add_input_to_system(execution_verifier_input)
        test_coder = LLMAgent.load_from_task_config(**self.test_coder_config)

        for attempt in range(self.max_coding_retries +1):
            test_coder_input = _build_test_coder_input(compiler_msg)
            test_code = test_coder.run(test_coder_input.model_dump_json())
            files = test_code.files

            FileWriter.write_to_files(
                code_files=files,
                output_dir=self.test_dir)

            compiler_msg = self._compiler_run()

            test_coder_output = TestCoderOutput(
                passed = compiler_msg.passed,
                files = files,
                compiler_message = compiler_msg,
            )

            logs.append(
                TestCoderLog(
                    attempt=attempt,
                    test_coder_input=test_coder_input,
                    test_coder_output=test_coder_output,
                )
            )
            if test_coder_output.passed:
                break

        self._update_log(
            test_coder_logs= logs
        )

        return test_coder_output

    def run_test(self,test_coder_output:TestCoderOutput) -> ExecutionVerifierOutput:
        if not test_coder_output.passed:
            return ExecutionVerifierOutput(
                test_code_passed=False,
                test_coder_history=self.log.test_coder_logs,
                test_passed=False,
                compiler_message=CompilerMsg(),
            )
        pass

    def _add_input_to_system(self,execution_verifier_input:ExecutionVerifierInput) -> None:
        additional_system = {
            "verification_plan":execution_verifier_input.verification_plan,
            "candidate_files":execution_verifier_input.candidate_files,
            "accepted_files":execution_verifier_input.accepted_files,
        }

        self.test_coder_config["task_config"].system += (f"\n Below are the verification plan, the candidate_files to be verified,"
                                                         f" and the accepted_files that have already passed verification. "
                                                         f"The accepted_files are provided for reference only and should not be verified again."
                                                         f"\n {json.dumps(additional_system)}")

    def _compiler_run(self) -> CompilerMsg:
        try:
            compile_result = _run_command(
                [
                    str(self.cli_path),
                    "compile",
                    "--fqbn",
                    self.fqbn,
                    str(self.test_dir),
                ],
            )
        except subprocess.TimeoutExpired as exc:
            return CompilerMsg(
                passed=False,
                compiler_message=f"Arduino CLI compilation timed out.\n{exc}",
            )

        return CompilerMsg(
            passed=compile_result.returncode == 0,
            compiler_message=(
                f"Arduino CLI failed to compile the candidate sketch.\n"
                f"STDOUT:\n{compile_result.stdout}\n"
                f"STDERR:\n{compile_result.stderr}"
                if compile_result.returncode != 0
                else ""
            ),
        )

    def _update_log(
            self,
            *,
            test_coder_logs:list[TestCoderLog] = None,
            execution_input:ExecutionVerifierInput = None,
            execution_verifier_output:ExecutionVerifierOutput = None,
    ) -> None:
        if test_coder_logs is not None:
            self.log.test_coder_logs = test_coder_logs
        if execution_input is not None:
            self.log.execution_verifier_input = execution_input
        if execution_verifier_output is not None:
            self.log.execution_verifier_output = execution_verifier_output



#Helper
def _build_test_coder_input(compiler_message:CompilerMsg) -> TestCoderInput:
    return TestCoderInput(
        compiler_message=compiler_message,
    )

def _run_command(command: list[str]) -> subprocess.CompletedProcess[str]:
    return subprocess.run(
        command,
        capture_output=True,
        text=True,
        encoding="utf-8",
        errors="replace",
        timeout=60,
    )