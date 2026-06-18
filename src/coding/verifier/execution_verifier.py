"""Dependency:
- Arduino CLI
- Arduino core for the target board
- Target board FQBN """
import subprocess
import tempfile
from pathlib import Path
from typing import Any
from collections.abc import Callable
from langchain.tools import BaseTool

from src.models.coding_common import CodeFile
from src.models.task_config import TaskConfig
from src.models.verifier import TestCoderInput,TestCoderOutput,ExecutionVerifierInput,ExecutionVerifierOutput,CompilerMsg
from src.llm.llm_agent import LLMAgent
from src.coding.filewriter.filewriter import FileWriter


class ExecutionVerifier:
    test_coder_config: dict[str,Any]
    enable_test_coder:bool
    cli_path: Path
    fqbn:str
    temp_dir:Path
    max_coding_retries: int = 10

    def __init__(self,test_coder_config:dict[str,Any],enable_test_coder:bool,cli_path:Path,fqbn:str):
        self.test_coder_config = test_coder_config
        self.test_dir = cli_path.parent/"temp"/"verification_test"
        self.enable_test_coder = enable_test_coder
        self.cli_path = cli_path
        self.fqbn = fqbn

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
        try:
            _write_basic_test_sketch(self.test_dir)
            files = execution_verifier_input.candidate_files
            FileWriter.write_to_files(
                code_files=files,
                output_dir=self.test_dir)
            compiler_message = self._compiler_run()

            if not compiler_message.passed:
                return ExecutionVerifierOutput(
                    passed=False,
                    compiler_message=compiler_message,
                )

            if self.enable_test_coder:
                test_coder_output = self.run_test_coder(execution_verifier_input)
                return self.run_test(test_coder_output.files)

            return ExecutionVerifierOutput(
                passed=True,
                compiler_message=compiler_message,
            )

        except Exception as e:
            raise e
        finally:
            self._clean_up()

    def run_test_coder(self,execution_verifier_input:ExecutionVerifierInput) -> TestCoderOutput:
        files = []
        compiler_messages = []
        for attempt in range(self.max_coding_retries +1):
            test_coder = LLMAgent.load_from_task_config(**self.test_coder_config)
            test_coder_input = _build_test_coder_input(execution_verifier_input,compiler_messages)
            test_coder_output = test_coder.run(test_coder_input.model_dump_json())
            files = test_coder_output.files

            FileWriter.write_to_files(
                code_files=files,
                output_dir=self.test_dir)
            compiler_message = self._compiler_run()

            if compiler_message.passed:
                return TestCoderOutput(
                    files=files,
                )

        if len(compiler_messages) == 0:
            return TestCoderOutput(
                files = [],
            )

        id_passed_map = _id_passed_map(compiler_messages)
        return TestCoderOutput(
            files = [file for file in files if file.file_id in id_passed_map],
        )

    def run_test(self,test_files:list[CodeFile]) -> ExecutionVerifierOutput:
        pass

    def _compiler_run(self):
        compile_result = _run_command(
            [
                str(self.cli_path),
                "compile",
                "--fqbn",
                self.fqbn,
                str(self.test_dir),
            ],
        )
        return CompilerMsg(
            passed=compile_result.returncode == 0,
            compiler_message= f"Arduino CLI failed to compile the basic test sketch.\n"\
                      f"STDOUT:\n{compile_result.stdout}\n"\
                      f"STDERR:\n{compile_result.stderr}" if compile_result.returncode != 0 else ""
        )

    def _clean_up(self):
        pass


#Helper
def _build_test_coder_input(execution_verifier_input:ExecutionVerifierInput,compiler_message:CompilerMsg) -> TestCoderInput:
    return TestCoderInput(
        verification_plan=execution_verifier_input.verification_plan,
        candidate_files=execution_verifier_input.candidate_files,
        accepted_files=execution_verifier_input.accepted_files,
        compiler_message=compiler_message,
    )

def _run_command(command: list[str]) -> subprocess.CompletedProcess[str]:
    return subprocess.run(
        command,
        capture_output=True,
        text=True,
        encoding="utf-8",
        errors="replace",
    )


def _id_passed_map(compiler_messages:list[CompilerMsg]) -> dict[str,Any]:
    return {
        msg.file_id:msg.passed for msg in compiler_messages if msg.passed
    }

def _write_basic_test_sketch(test_dir:Path) -> None:
    basic_ino_sketch = CodeFile(
        file_id= "1",
        name = "verification_test",
        file_type = ".ino",
        description = "Basic test sketch",
        content = """\
        #include <Arduino.h>
        #include <Wire.h>
        
        void setup() {
            Wire.begin();
        }
        
        void loop() {
        }
        """,
    )
    FileWriter.write_to_file(basic_ino_sketch, test_dir)