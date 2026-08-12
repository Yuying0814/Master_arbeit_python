"""Dependency:
- Arduino CLI
- Arduino core for the target board
- Target board FQBN """
import copy
import subprocess
import tempfile
import time
from pathlib import Path
from typing import Any
from collections.abc import Callable
from langchain.tools import BaseTool
import serial
from serial.tools import list_ports

from src.coding.config import ArduinoBoardConfig
from src.models.coding.coding_common import CodeFile
from src.models.task_config import TaskConfig
from src.models.coding.verifier import (TestCoderInput,TestCoderOutput,
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
    port:str
    port_identity:dict[str,str]
    test_dir:Path
    code_dir:Path
    build_dir:Path

    board_options:dict[str,str]
    max_coding_retries: int = 10
    total_tokens: dict[str,Any]
    log:ExecutionVerifierLog

    def __init__(
            self,
            driver_name:str,
            test_coder_config:dict[str,Any],
            enable_test_coder:bool,
            cli_path:Path,
            board_options:dict[str,str],
            fqbn:str,
            port:str,
    ):
        self.driver_name = driver_name
        self.test_coder_config = test_coder_config
        self.test_dir = Path()
        self.code_dir = Path()
        self.build_dir = Path()

        self.enable_test_coder = enable_test_coder
        self.cli_path = cli_path
        self.fqbn = fqbn
        self.board_options = board_options
        self.port = port.strip()
        self.port_identity = {}
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
            board_config: ArduinoBoardConfig,
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
            fqbn = f"{board_config.package}:{board_config.architecture}:{board_config.board}",
            board_options=board_config.options,
            port = board_config.port,
        )

    def run(self,execution_verifier_input:ExecutionVerifierInput) -> ExecutionVerifierOutput:
        self._reset_log(execution_verifier_input)
        print(" ->-> start execution verification")

        with tempfile.TemporaryDirectory(prefix="arduino_verify_") as temp_root:
            self.test_dir = Path(temp_root) / self.driver_name

            files = execution_verifier_input.candidate_files

            project_dir = FileWriter.write_to_files(
                code_files=files,
                output_dir=self.test_dir
            )

            compiler_message = self._compiler_run(project_dir)

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
                all_code_files = execution_verifier_input.candidate_files + execution_verifier_input.accepted_files

                test_result =  self.run_test(all_code_files,test_coder_output)
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

        test_coder_config = self._build_test_coder_config(
            execution_verifier_input
        )

        test_coder = LLMAgent.load_from_task_config(
            **test_coder_config
        )
        print(f"test coder enabled, start generating test code")

        for attempt in range(1,self.max_coding_retries +1):
            print(f"attempt {attempt/self.max_coding_retries}")
            test_coder_input = _build_test_coder_input(compiler_msg)

            print(f"test code generation started")
            test_code = test_coder.run(test_coder_input.model_dump_json())
            print(f"test code generated")

            files = test_code.files

            project_dir = FileWriter.write_to_files(
                code_files=files,
                output_dir=self.test_dir)

            compiler_msg = self._compiler_run(project_dir)

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

    def run_test(
            self,
            all_code_files:list[CodeFile],
            test_coder_output:TestCoderOutput
    ) -> ExecutionVerifierOutput:

        print("start runing test")
        self._prepare_test_project(
            all_code_files=all_code_files,
            test_files=test_coder_output.files,
        )
        compiler_message = self._compiler_run(
            project_dir=self.code_dir,
            build_dir=self.build_dir,
        )

        if not compiler_message.passed:
            return ExecutionVerifierOutput(
                candidate_code_passed=True,
                test_code_passed=False,
                test_coder_history=self.log.test_coder_logs,
                test_passed=None,
                compiler_message=compiler_message,
            )

        port_available, port_identity, port_message = self._check_upload_port()

        self.port_identity = port_identity

        if not port_available:
            return ExecutionVerifierOutput(
                candidate_code_passed=True,
                test_code_passed=True,
                test_code_uploaded=False,
                test_coder_history=self.log.test_coder_logs,
                test_passed=None,
                execution_message=port_message,
                compiler_message=compiler_message,
            )

        uploaded, upload_message = self._upload_test_code(self.port)

        if not uploaded:
            return ExecutionVerifierOutput(
                candidate_code_passed=True,
                test_code_passed=True,
                test_code_uploaded=False,
                test_coder_history=self.log.test_coder_logs,
                test_passed=None,
                execution_message=f"{port_message}\n{upload_message}",
                compiler_message=compiler_message,
            )

        reconnected, reconnected_identity, reconnect_message =  self._reconnect_device(port_identity)

        self.port_identity = reconnected_identity
        if not reconnected:
            return ExecutionVerifierOutput(
                candidate_code_passed=True,
                test_code_passed=True,
                test_code_uploaded=True,
                device_reconnected=False,
                test_coder_history=self.log.test_coder_logs,
                test_passed=None,
                execution_message=(
                    f"{port_message}\n{upload_message}\n{reconnect_message}"
                ),
                compiler_message=compiler_message,
            )

        self.port = reconnected_identity["address"]
        read_succeeded, serial_output, read_message = self._read_serial_output()

        if read_succeeded:
            runtime_passed, runtime_message = self._evaluate_test_output(
                serial_output
            )
        else:
            runtime_passed = False
            runtime_message = (
                "Failed to read serial output."
            )

        return ExecutionVerifierOutput(
            candidate_code_passed=True,
            test_code_passed=True,
            test_code_uploaded=True,
            device_reconnected=True,
            run_time_test_passed=runtime_passed,
            test_coder_history=self.log.test_coder_logs,
            test_passed=runtime_passed,
            execution_message=(
                f"{port_message}\n{upload_message}\n{reconnect_message}\n"
                f"{read_message}\n{runtime_message}\n"
                f"Serial output:\n{serial_output}"
            ),
            compiler_message=compiler_message,
        )

    def _prepare_test_project(
            self,
            all_code_files: list[CodeFile],
            test_files: list[CodeFile],
    ) -> Path:

        test_ino_files = [
            code_file
            for code_file in test_files
            if code_file.file_type.strip().casefold() == ".ino"
        ]

        if len(test_ino_files) != 1:
            raise ValueError(
                "Test coder output must contain exactly one .ino file."
            )

        test_ino_file = test_ino_files[0]
        input_name = test_ino_file.name.strip()

        if not input_name or Path(input_name).name != input_name:
            raise ValueError(
                "The generated test sketch name must be a plain filename."
            )

        if not input_name.strip():
            raise ValueError(
                "The generated test sketch must have a non-empty filename."
            )

        driver_files = [
            code_file.model_copy(deep=True)
            for code_file in all_code_files
            if code_file.file_type.strip().casefold() in {".cpp", ".h"}
        ]
        project_files = [*driver_files, test_ino_file]

        code_root = self.test_dir / "code"
        build_root = self.test_dir / "build"
        self.code_dir = FileWriter.write_to_files(
            code_files=project_files,
            output_dir=code_root,
        )

        self.build_dir = build_root / input_name
        self.build_dir.mkdir(parents=True, exist_ok=True)

        return self.code_dir

    def _check_upload_port(self,) -> tuple[bool, dict[str, str], str]:
        if not self.port:
            return False, {}, "No upload port configured."

        try:
            connected_ports = list(list_ports.comports())
        except OSError as exc:
            return False, {}, f"Failed to query connected serial ports.\n{exc}"

        port_info = next(
            (
                port
                for port in connected_ports
                if port.device.casefold() == self.port.casefold()
            ),
            None,
        )

        if port_info is None:
            return False, {}, f"The configured port {self.port} is not connected. "

        port_identity = {
            "address": port_info.device,
            "serial_number": port_info.serial_number or "",
            "vid": f"0x{port_info.vid:04X}" if port_info.vid is not None else "",
            "location": port_info.location or "",
        }

        try:
            with serial.Serial(
                    port=port_info.device,
                    baudrate=115200,
                    timeout=0,
                    write_timeout=0,
            ):
                pass
        except (serial.SerialException, OSError) as err:
            return (
                False,
                port_identity,
                f"The configured port {port_info.device} is connected but "
                f"cannot be opened. It may be in use by another process.\n{err}",
            )

        self.port = port_info.device

        return True,port_identity,f"The configured port {self.port} is connected and available.",

    def _upload_test_code(self, port: str) -> tuple[bool, str]:
        command = [
            str(self.cli_path),
            "upload",
            "--fqbn",
            self.fqbn,
            "--port",
            port,
        ]

        if self.board_options:
            command.extend([
                "--board-options",
                self._build_board_options(),
            ])

        command.extend([
            "--build-path",
            str(self.build_dir),
        ])

        try:
            result = _run_command(command)
        except subprocess.TimeoutExpired as exc:
            return False, f"Upload timed on port {port}.\n{exc}"
        except OSError as exc:
            return False, f"Failed to start Arduino CLI upload.\n{exc}"

        if result.returncode != 0:
            return (
                False,
                f"Failed to upload the test firmware to {port}.\n"
                f"STDOUT:\n{result.stdout}\n"
                f"STDERR:\n{result.stderr}",
            )

        return True, f"Test firmware uploaded to {port}."

    def _reconnect_device(
            self,
            port_identity: dict[str, str],
            timeout: float = 10.0,
            poll_interval: float = 0.5,
    ) -> tuple[bool, dict[str, str], str]:

        deadline = time.monotonic() + timeout
        last_detected_ports: list[str] = []

        while True:
            try:
                connected_ports = list(list_ports.comports())
            except OSError as exc:
                return (
                    False,
                    port_identity,
                    f"Failed to reconnect to the device after upload.\n{exc}",
                )

            last_detected_ports = [port.device for port in connected_ports]

            for port_info in connected_ports:
                current_identity = {
                    "address": port_info.device,
                    "serial_number": port_info.serial_number or "",
                    "vid": f"0x{port_info.vid:04X}" if port_info.vid is not None else "",
                    "location": port_info.location or "",
                }

                serial_number = port_identity.get("serial_number", "")
                location = port_identity.get("location", "")
                original_address = port_identity.get("address", "")
                vid = port_identity.get("vid", "")

                if serial_number:
                    matched = current_identity["serial_number"] == serial_number

                elif location:
                    matched = (
                        current_identity["location"] == location
                        and (
                            not vid
                            or current_identity["vid"] == vid
                        )
                    )
                else:
                    matched = (
                        current_identity["address"].casefold()
                        == original_address.casefold()
                        and (
                            not vid
                            or current_identity["vid"] == vid
                        )
                    )

                if matched:
                    return (
                        True,
                        current_identity,
                        "Device reconnected"
                        f"{current_identity['address']}.",
                    )

            if time.monotonic() >= deadline:
                break

            time.sleep(poll_interval)

        return (
            False,
            port_identity,
            f"The target device did not reconnect within {timeout:.1f} seconds.",
        )

    def _read_serial_output(self, duration: float = 10.0,baudrate: int = 115200,read_timeout: float = 0.25,) -> tuple[bool, str, str]:
        if not self.port:
            return False, "", "No serial port configured."

        if duration <= 0:
            return False, "", "Serial read duration must be > 0."

        if read_timeout <= 0:
            return False, "", "Serial read timeout must be > 0."

        output_chunks: list[bytes] = []

        try:
            with serial.Serial(
                    port=self.port,
                    baudrate=baudrate,
                    timeout=min(read_timeout, duration),
                    write_timeout=1.0,
            ) as serial_port:
                serial_port.reset_input_buffer()
                serial_port.write(b"RUN_TEST\n")
                serial_port.flush()
                deadline = time.monotonic() + duration

                while time.monotonic() < deadline:
                    bytes_waiting = serial_port.in_waiting
                    chunk = serial_port.read(bytes_waiting or 1)

                    if chunk:
                        output_chunks.append(chunk)

        except (serial.SerialException, OSError) as exc:
            output = b"".join(output_chunks).decode(
                "utf-8",
                errors="replace",
            )
            return False,output,f"Failed to read serial output from port {self.port}.\n{exc}",

        output_bytes = b"".join(output_chunks)
        output = output_bytes.decode("utf-8", errors="replace")
        if not output_bytes:
            return (
                True,
                "",
                f"No serial output was received from port {self.port} "
                f"within {duration:.1f} seconds.",
            )

        return True,output,f"RUN_TEST was sent and {len(output_bytes)} bytes were read from port {self.port}.",

    def _evaluate_test_output(self, output: str) -> tuple[bool, str]:
        valid_markers = {
            "TEST_RESULT:PASS",
            "TEST_RESULT:FAIL",
        }

        result_markers = [line.strip() for line in output.splitlines() if line.strip() in valid_markers]

        if not result_markers:
            return (
                False,
                "The runtime test output does not contain a result marker.",
            )

        if len(result_markers) != 1:
            return False,"The runtime test must output exactly one result marker.",

        if result_markers[0] == "TEST_RESULT:FAIL":
            return False, "The runtime test reported TEST_RESULT:FAIL."

        return True, "The runtime test reported TEST_RESULT:PASS."

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


    def _compiler_run(self,project_dir:Path,build_dir:Path | None = None,) -> CompilerMsg:
        try:
            command = [
                str(self.cli_path),
                "compile",
                "--fqbn",
                self.fqbn,
            ]

            if self.board_options:
                command.extend([
                    "--board-options",
                    self._build_board_options(),
                ])

            if build_dir is not None:
                build_dir.mkdir(parents=True, exist_ok=True)
                command.extend([
                    "--build-path",
                    str(build_dir),
                ])

            command.append(str(project_dir))
            compile_result = _run_command(command)
        except subprocess.TimeoutExpired as exc:
            return CompilerMsg(
                passed=False,
                compiler_message=f"Arduino CLI compilation timed out.\n{exc}",
            )

        except OSError as exc:
            return CompilerMsg(
                passed=False,
                compiler_message=f"Failed to start Arduino CLI compilation.\n{exc}",
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

    def _build_board_options(self) -> str:
        return ",".join(
            f"{key}={value}"
            for key, value in self.board_options.items()
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
