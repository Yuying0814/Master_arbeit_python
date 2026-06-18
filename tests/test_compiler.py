from __future__ import annotations

import subprocess
from pathlib import Path


PROJECT_ROOT = Path(__file__).resolve().parents[1]

ARDUINO_CLI_PATH = PROJECT_ROOT / "arduino" / "bin" / "arduino-cli.exe"

TEST_SKETCH_DIR = PROJECT_ROOT / "temp" / "basic_compile_test"
TEST_SKETCH_FILE = TEST_SKETCH_DIR / "basic_compile_test.ino"

FQBN = "arduino:avr:uno"
CORE_NAME = "arduino:avr"


def run_command(command: list[str], cwd: Path) -> subprocess.CompletedProcess[str]:
    """Run a command and capture its output."""
    return subprocess.run(
        command,
        cwd=cwd,
        capture_output=True,
        text=True,
        encoding="utf-8",
        errors="replace",
    )


def write_basic_test_sketch() -> None:
    """Write a minimal Arduino sketch for compile verification."""
    TEST_SKETCH_DIR.mkdir(parents=True, exist_ok=True)

    TEST_SKETCH_FILE.write_text(
        """\
#include <Arduino.h>
#include <Wire.h>

void setup() {
    Wire.begin();
}

void loop() {
}
""",
        encoding="utf-8",
    )


def test_arduino_cli_can_compile_basic_sketch() -> None:
    assert ARDUINO_CLI_PATH.exists(), f"Arduino CLI not found: {ARDUINO_CLI_PATH}"

    write_basic_test_sketch()

    compile_result = run_command(
        [
            str(ARDUINO_CLI_PATH),
            "compile",
            "--fqbn",
            FQBN,
            str(TEST_SKETCH_DIR),
        ],
        cwd=PROJECT_ROOT,
    )

    assert compile_result.returncode == 0, (
        "Arduino CLI failed to compile the basic test sketch.\n"
        f"Command: {ARDUINO_CLI_PATH} compile --fqbn {FQBN} {TEST_SKETCH_DIR}\n"
        f"STDOUT:\n{compile_result.stdout}\n"
        f"STDERR:\n{compile_result.stderr}"
    )