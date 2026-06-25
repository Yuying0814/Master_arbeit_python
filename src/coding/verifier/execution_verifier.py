"""Dependency:
- Arduino CLI
- Arduino core for the target board
- Target board FQBN """
import copy
import subprocess
import tempfile
from pathlib import Path
from typing import Any
from collections.abc import Callable
from langchain.tools import BaseTool

from src.models.task_config import TaskConfig
from src.models.verifier import (TestCoderInput,TestCoderOutput,
                                 ExecutionVerifierInput,ExecutionVerifierOutput,
                                 CompilerMsg,ExecutionVerifierLog,TestCoderLog,TestCoderConfig)
from src.llm.llm_agent import LLMAgent
from src.coding.filewriter.filewriter import FileWriter


class ExecutionVerifier:
    driver_name:str
    test_coder_config: dict[str,Any]
    enable_test_coder:bool
    cli_path: Path
    fqbn:str
    temp_dir:Path
    max_coding_retries: int = 10
    total_tokens: dict[str,Any]
    log:ExecutionVerifierLog

    def __init__(self,driver_name:str,test_coder_config:dict[str,Any],enable_test_coder:bool,cli_path:Path,fqbn:str):
        self.driver_name = driver_name
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
            test_coder_logs=[],
            token_consumption={}
        )

    @classmethod
    def load_from_task_config(
            cls,
            driver_name:str,
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
            driver_name = driver_name,
            test_coder_config = test_coder_config,
            enable_test_coder = enable_test_coder,
            cli_path = cli_path,
            fqbn = fqbn
        )

    def run(self,execution_verifier_input:ExecutionVerifierInput) -> ExecutionVerifierOutput:
        self._reset_log(execution_verifier_input)
        print(" ->-> start execution verification")

        with tempfile.TemporaryDirectory(prefix="arduino_verify_") as temp_root:
            self.test_dir = Path(temp_root) / self.driver_name

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
                    execution_output=test_result,
                )
                print(
                    f" ->-> candidate code failed to compile\n"
                    f"==================\n"
                    f"compiled:\n"
                    f"{compiler_message.passed}\n\n"
                    f"compiler message:\n"
                    f"{compiler_message.compiler_message}\n"
                    f"==================\n"
                )
                return test_result

            print(f" ->-> candidate code compiled successfully")

            if self.enable_test_coder:
                test_coder_output = self.run_test_coder(execution_verifier_input)
                test_result =  self.run_test(test_coder_output)
                self._update_log(
                    execution_output=test_result,
                )
                return test_result

            print(
                f" ->-> test coder disabled, therefore no test code generated and no test for candidate code"
            )

            test_result = ExecutionVerifierOutput(
                candidate_code_passed=True,
                compiler_message=compiler_message,
            )
            self._update_log(
                execution_output=test_result,
            )
            print(
                f" ->-> execution verification completed\n"
                f"==================\n"
                f"candidate code compiled successfully: {test_result.candidate_code_passed}\n"
                f"test code compiled successfully: {test_result.test_code_passed}\n"
                f"test passed: {test_result.test_passed}\n"
                f"==================\n"
            )

            return test_result

    def run_test_coder(self,execution_verifier_input:ExecutionVerifierInput) -> TestCoderOutput:
        logs = []
        compiler_msg = CompilerMsg()
        test_coder_output = TestCoderOutput()

        test_coder_config = self._build_test_coder_config(execution_verifier_input)
        test_coder = LLMAgent.load_from_task_config(**test_coder_config)
        print(f"test coder enabled, start generating test code")

        for attempt in range(1,self.max_coding_retries +1):
            print(f"attempt {attempt/self.max_coding_retries}")
            test_coder_input = _build_test_coder_input(compiler_msg)

            print(f"test code generation started")
            test_code = test_coder.run(test_coder_input.model_dump_json())
            print(f"test code generated")

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

        if test_coder_output.passed:
            print("test code compilation passed")
        else:
            print(
                "test code compilation failed:\n"
                f"End with: {compiler_msg.compiler_message}"
            )

        self._update_log(
            test_coder_logs= logs,
            total_tokens=test_coder.total_tokens
        )

        return test_coder_output

    def run_test(self,test_coder_output:TestCoderOutput) -> ExecutionVerifierOutput:
        if not test_coder_output.passed:
            return ExecutionVerifierOutput(
                candidate_code_passed=True,
                test_code_passed=False,
                test_coder_history=self.log.test_coder_logs,
                test_passed=None,
                compiler_message=test_coder_output.compiler_message,
            )

        pass

    def _build_test_coder_config(
            self,
            execution_verifier_input: ExecutionVerifierInput,
    ) -> dict[str, Any]:
        additional_system = TestCoderConfig(
            verification_plan=execution_verifier_input.verification_plan,
            candidate_files=execution_verifier_input.candidate_files,
            accepted_files=execution_verifier_input.accepted_files,
        )

        context = additional_system.model_dump_json(indent=2)
        task_config = self.test_coder_config["task_config"]

        system_context = (
            "\n\nBelow are the verification plan, the candidate_files to be verified, "
            "and the accepted_files that have already passed verification. "
            "The accepted_files are provided for reference only and should not be verified again."
            f"\n{context}"
        )

        return {
            **self.test_coder_config,
            "task_config": task_config.model_copy(
                deep=True,
                update={
                    "system": task_config.system + system_context,
                },
            ),
        }


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
                f"Arduino CLI failed to compile the verification sketch.\n"
                f"STDOUT:\n{compile_result.stdout}\n"
                f"STDERR:\n{compile_result.stderr}"
                if compile_result.returncode != 0
                else ""
            ),
        )

    def _update_log(
            self,
            *,
            test_coder_logs: list[TestCoderLog] | None = None,
            execution_input: ExecutionVerifierInput | None = None,
            execution_output: ExecutionVerifierOutput | None = None,
            total_tokens: dict[str, Any] | None = None,
    ) -> None:
        if test_coder_logs is not None:
            self.log.test_coder_logs = [
                log.model_copy(deep=True) for log in test_coder_logs
            ]

        if execution_input is not None:
            self.log.execution_input = execution_input.model_copy(deep=True)

        if execution_output is not None:
            self.log.execution_output = execution_output.model_copy(deep=True)

        if total_tokens is not None:
            self.log.token_consumption = copy.deepcopy(total_tokens)
            self.total_tokens = copy.deepcopy(total_tokens)

    def _reset_log(self,execution_verifier_input: ExecutionVerifierInput) -> None:
        self.total_tokens = {}
        self.log = ExecutionVerifierLog(
            enable_test_coder=self.enable_test_coder,
            execution_input=execution_verifier_input.model_copy(deep=True),
            execution_output=ExecutionVerifierOutput(),
            test_coder_logs=[],
            token_consumption={},
        )

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