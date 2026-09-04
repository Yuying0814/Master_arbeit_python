"""Run ExecutionVerifier manually with the external BME280 candidate driver.

This script calls the configured test coder and may compile, upload, and run
firmware on the board connected to PORT. Run it manually, not through pytest.
"""

from __future__ import annotations

import json
import sys
from pathlib import Path


PROJECT_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(PROJECT_ROOT))

from src.coding.config import CodingConfig
from src.coding.verifier.execution_verifier import ExecutionVerifier
from src.models.coding.coding_common import CodeFile, FilePlan
from src.models.coding.verifier import ExecutionVerifierInput


DRIVER_NAME = "bme280"
HEADER_PATH = Path("D:/data_test_07_08/Temp/bme280/bme280.h")
SOURCE_PATH = Path("D:/data_test_07_08/Temp/bme280/bme280.cpp")

ENV_PATH = PROJECT_ROOT / ".env"
CLI_PATH = PROJECT_ROOT / "arduino" / "bin" / "arduino-cli.exe"
CODE_DIR = PROJECT_ROOT / "code"

PORT = "COM6"
PACKAGE = "rp2040"
ARCHITECTURE = "rp2040"
BOARD = "generic"
BOARD_OPTIONS = {
    "flash": "4194304_0",
    "boot2": "boot2_w25q128jvxq_4_padded_checksum",
    "usbstack": "picosdk",
}

BME280_I2C_ADDRESS = "0x76"
I2C_BUS_INSTANCE = "Wire1"
I2C_SDA_PIN = 2
I2C_SCL_PIN = 3
MAX_TEST_CODER_RETRIES = 1


def print_step(title: str) -> None:
    print(f"\n{'=' * 72}")
    print(title)
    print(f"{'=' * 72}")


class VerboseExecutionVerifier(ExecutionVerifier):
    """ExecutionVerifier with console output around hardware-facing steps."""

    def _compiler_run(self, project_dir: Path, build_dir: Path | None = None):
        print_step("COMPILER")
        print(f"Project directory: {project_dir}")
        print(f"Build directory: {build_dir or 'Arduino CLI temporary build path'}")
        result = super()._compiler_run(project_dir, build_dir)
        print(f"Compilation passed: {result.passed}")
        if result.compiler_message:
            print(f"Compiler message:\n{result.compiler_message}")
        return result

    def _prepare_test_project(self, all_code_files, test_files):
        print_step("TEST PROJECT PREPARATION")
        project_dir = super()._prepare_test_project(
            all_code_files=all_code_files,
            test_files=test_files,
        )
        print(f"Test code directory: {self.code_dir}")
        print(f"Test build directory: {self.build_dir}")
        print("Test project files:")
        for path in sorted(project_dir.iterdir()):
            print(f"  - {path.name}")
        return project_dir

    def _check_upload_port(self):
        print_step("UPLOAD PORT CHECK")
        print(f"Configured port: {self.port}")
        available, identity, message = super()._check_upload_port()
        print(f"Port available: {available}")
        print(f"Port identity: {json.dumps(identity, indent=2)}")
        print(f"Port message: {message}")
        return available, identity, message

    def _upload_test_code(self, port: str):
        print_step("FIRMWARE UPLOAD")
        print(f"Upload port: {port}")
        print(f"Build directory: {self.build_dir}")
        uploaded, message = super()._upload_test_code(port)
        print(f"Upload passed: {uploaded}")
        print(f"Upload message: {message}")
        return uploaded, message

    def _reconnect_device(
            self,
            port_identity: dict[str, str],
            timeout: float = 10.0,
            poll_interval: float = 0.5,
    ):
        print_step("DEVICE RECONNECTION")
        print(f"Identity before upload: {json.dumps(port_identity, indent=2)}")
        reconnected, identity, message = super()._reconnect_device(
            port_identity=port_identity,
            timeout=timeout,
            poll_interval=poll_interval,
        )
        print(f"Device reconnected: {reconnected}")
        print(f"Identity after upload: {json.dumps(identity, indent=2)}")
        print(f"Reconnection message: {message}")
        return reconnected, identity, message

    def _read_serial_output(
            self,
            duration: float = 10.0,
            baudrate: int = 115200,
            read_timeout: float = 0.25,
    ):
        print_step("SERIAL RUN_TEST HANDSHAKE")
        print(f"Serial port: {self.port}")
        print(f"Baud rate: {baudrate}")
        print("Sending: RUN_TEST\\n")
        succeeded, output, message = super()._read_serial_output(
            duration=duration,
            baudrate=baudrate,
            read_timeout=read_timeout,
        )
        print(f"Serial read succeeded: {succeeded}")
        print(f"Serial read message: {message}")
        print(f"Serial output:\n{output or '<empty>'}")
        return succeeded, output, message

    def _evaluate_test_output(self, output: str):
        print_step("RUNTIME RESULT EVALUATION")
        passed, message = super()._evaluate_test_output(output)
        print(f"Runtime test passed: {passed}")
        print(f"Runtime result message: {message}")
        return passed, message


def build_candidate_files() -> list[CodeFile]:
    header = CodeFile(
        file_id="bme280_header_candidate",
        name="bme280",
        file_type=".h",
        description="Candidate BME280 public driver interface.",
        content=HEADER_PATH.read_text(encoding="utf-8"),
    )
    source = CodeFile(
        file_id="bme280_source_candidate",
        name="bme280",
        file_type=".cpp",
        description="Candidate BME280 I2C driver implementation.",
        content=SOURCE_PATH.read_text(encoding="utf-8"),
    )

    compile_harness = CodeFile(
        file_id="bme280_compile_harness",
        name="bme280_compile_harness",
        file_type=".ino",
        description=(
            "Minimal entrance sketch required for the candidate compilation "
            "stage of ExecutionVerifier."
        ),
        content=(
            '#include <Arduino.h>\n'
            '#include <Wire.h>\n'
            '#include "bme280.h"\n\n'
            'BME280 sensor;\n\n'
            'void setup() {\n'
            f'    {I2C_BUS_INSTANCE}.setSDA({I2C_SDA_PIN});\n'
            f'    {I2C_BUS_INSTANCE}.setSCL({I2C_SCL_PIN});\n'
            f'    {I2C_BUS_INSTANCE}.begin();\n'
            '}\n\n'
            'void loop() {\n'
            '}\n'
        ),
    )

    return [header, source, compile_harness]


def build_planner_verification_plan() -> list[FilePlan]:
    plan = {
        "description": (
            "Generate one real-hardware BME280 I2C verification sketch. Use "
            f"the {I2C_BUS_INSTANCE} I2C instance, GPIO {I2C_SDA_PIN} for "
            f"SDA, GPIO {I2C_SCL_PIN} for SCL, and "
            f"I2C address {BME280_I2C_ADDRESS}. Configure the pins with "
            f"{I2C_BUS_INSTANCE}.setSDA({I2C_SDA_PIN}) and "
            f"{I2C_BUS_INSTANCE}.setSCL({I2C_SCL_PIN}) before "
            f"{I2C_BUS_INSTANCE}.begin(). Pass {I2C_BUS_INSTANCE} to "
            f"sensor.begin({BME280_I2C_ADDRESS}, {I2C_BUS_INSTANCE}). "
            "Call the bus configuration methods directly; do not wrap them "
            "in preprocessor checks such as #if defined(Wire) or "
            "#if defined(Wire1). Do not replace Wire1 with Wire. "
            "Wait for the RUN_TEST serial command at 115200 baud, execute the "
            "test once, and output exactly one TEST_RESULT marker. Verify that "
            "begin succeeds, isConnected returns true, chip ID register 0xD0 "
            "equals 0x60, configure succeeds, raw measurement reading succeeds, "
            "and compensated temperature, pressure, and humidity are finite. "
            "Require positive pressure and humidity within 0 to 100 percent. "
            "Do not reset the sensor and do not guess custom GPIO assignments."
        ),
        "target_files": [
            {
                "file_id": "bme280_hardware_test_sketch",
                "name": "bme280_hardware_test",
                "file_type": ".ino",
                "operation": {
                    "operation": "create",
                    "description": "Create the standalone hardware test sketch.",
                },
                "description": (
                    "Hardware runtime test for the candidate BME280 driver "
                    "using the RUN_TEST handshake."
                ),
                "sections": [
                    {
                        "name": "includes_and_test_state",
                        "description": (
                            "Include Arduino.h, Wire.h, math.h, and bme280.h; "
                            f"declare the BME280 instance, {I2C_BUS_INSTANCE} "
                            f"as the I2C bus, GPIO {I2C_SDA_PIN} SDA and GPIO "
                            f"{I2C_SCL_PIN} SCL constants, and one-execution "
                            "state."
                        ),
                        "functions": [],
                    },
                    {
                        "name": "hardware_runtime_checks",
                        "description": (
                            "Run all planned BME280 communication, identity, "
                            "configuration, raw-data, and compensated-data checks."
                        ),
                        "functions": [
                            {
                                "name": "runHardwareTest",
                                "description": (
                                    "Execute the complete hardware test and return "
                                    "true only when every required check passes."
                                ),
                                "operation": {
                                    "operation": "create",
                                    "description": "Create the runtime test function.",
                                },
                                "parameters": [],
                                "return_type": {
                                    "data_type": "bool",
                                    "description": (
                                        "True only if all BME280 runtime checks pass."
                                    ),
                                },
                            }
                        ],
                    },
                    {
                        "name": "serial_handshake_and_entry_points",
                        "description": (
                            "Initialize Serial at 115200 baud, wait for RUN_TEST, "
                            "execute the test once, and emit one final result marker."
                        ),
                        "functions": [
                            {
                                "name": "setup",
                                "description": "Initialize serial communication.",
                                "operation": {
                                    "operation": "create",
                                    "description": "Create Arduino setup entry point.",
                                },
                                "parameters": [],
                                "return_type": {
                                    "data_type": "void",
                                    "description": "No return value.",
                                },
                            },
                            {
                                "name": "loop",
                                "description": (
                                    "Accept RUN_TEST and execute the test exactly once."
                                ),
                                "operation": {
                                    "operation": "create",
                                    "description": "Create Arduino loop entry point.",
                                },
                                "parameters": [],
                                "return_type": {
                                    "data_type": "void",
                                    "description": "No return value.",
                                },
                            },
                        ],
                    },
                ],
            }
        ],
    }
    return [FilePlan.model_validate(plan)]


def build_verifier() -> VerboseExecutionVerifier:
    config = CodingConfig.load_config(
        code_dir=CODE_DIR,
        cli_path=CLI_PATH,
        env=ENV_PATH,
        enable_test_coder=True,
        package=PACKAGE,
        architecture=ARCHITECTURE,
        board=BOARD,
        board_options=BOARD_OPTIONS,
        port=PORT,
    )

    task_config = config.task_configs.verification_test_coder
    if not task_config.system.strip():
        raise RuntimeError("prompt_test_coder.txt is empty.")

    api_key = config.get_apikey(task_config.model.provider)
    if not api_key:
        raise RuntimeError(
            f"No API key configured for provider {task_config.model.provider}."
        )

    verifier = VerboseExecutionVerifier.load_from_task_config(
        driver_name=DRIVER_NAME,
        task_config=task_config,
        api_key=api_key,
        tools=None,
        thread_id="manual_execution_verifier_bme280",
        enable_test_coder=True,
        cli_path=CLI_PATH,
        board_config=config.board_config,
    )
    verifier.max_coding_retries = MAX_TEST_CODER_RETRIES
    return verifier


def print_test_coder_summary(verifier: ExecutionVerifier) -> None:
    print_step("TEST CODER SUMMARY")
    print(f"Attempts: {len(verifier.log.test_coder_logs)}")
    for log in verifier.log.test_coder_logs:
        output = log.test_coder_output
        print(f"Attempt {log.attempt}: preliminary compilation passed={output.passed}")
        for code_file in output.files:
            print(f"Generated file: {code_file.name}{code_file.file_type}")
            print("Generated content:")
            print(code_file.content)
        if output.compiler_message.compiler_message:
            print("Preliminary compiler message:")
            print(output.compiler_message.compiler_message)

    print("Token consumption:")
    print(json.dumps(verifier.total_tokens, indent=2, default=str))


def main() -> None:
    print_step("MANUAL BME280 EXECUTION VERIFIER TEST")
    print("This run may compile and upload firmware to real hardware.")
    print(f"Header candidate: {HEADER_PATH}")
    print(f"Source candidate: {SOURCE_PATH}")
    print(f"Arduino CLI: {CLI_PATH}")
    print(f"FQBN: {PACKAGE}:{ARCHITECTURE}:{BOARD}")
    print(f"Port: {PORT}")
    print(f"BME280 address: {BME280_I2C_ADDRESS}")
    print(f"I2C bus instance: {I2C_BUS_INSTANCE}")
    print(f"I2C SDA pin: GPIO{I2C_SDA_PIN}")
    print(f"I2C SCL pin: GPIO{I2C_SCL_PIN}")

    for required_path in (HEADER_PATH, SOURCE_PATH, ENV_PATH, CLI_PATH):
        if not required_path.is_file():
            raise FileNotFoundError(f"Required file not found: {required_path}")

    candidate_files = build_candidate_files()
    verification_plan = build_planner_verification_plan()

    print_step("SIMULATED PLANNER VERIFICATION PLAN")
    print(
        json.dumps(
            [plan.model_dump(mode="json") for plan in verification_plan],
            indent=2,
        )
    )

    print_step("EXECUTION VERIFIER INPUT")
    for code_file in candidate_files:
        print(
            f"Candidate: {code_file.file_id} -> "
            f"{code_file.name}{code_file.file_type}"
        )

    verifier_input = ExecutionVerifierInput(
        verification_plan=verification_plan,
        candidate_files=candidate_files,
        accepted_files=[],
    )
    verifier = build_verifier()

    print_step("EXECUTION VERIFIER RUN")
    result = verifier.run(verifier_input)

    print_test_coder_summary(verifier)

    print_step("FINAL EXECUTION VERIFIER OUTPUT")
    print(result.model_dump_json(indent=2))
    print(f"Final port: {verifier.port}")
    print(f"Final port identity: {json.dumps(verifier.port_identity, indent=2)}")


if __name__ == "__main__":
    main()
