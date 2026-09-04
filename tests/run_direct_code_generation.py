from __future__ import annotations

import argparse
import asyncio
import json
import os
import re
import sys
from pathlib import Path
from typing import Any

from dotenv import load_dotenv
from pydantic import Field


PROJECT_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(PROJECT_ROOT))
load_dotenv(PROJECT_ROOT / ".env")
OCR_DIR = PROJECT_ROOT/ "data"/ "output"/ "ocr"/ "mistral"/ "mistral-ocr-latest"
DIRECT_GENERATION_DIR = PROJECT_ROOT / "data" / "output" / "direct_generation"
PROMPT_PATH = PROJECT_ROOT / "prompts" / "prompt_direct_code_generation.txt"

from src.llm.llm_task_runner import LLMTaskRunner
from src.models.structuredOutputModel import StructuredOutputModel
from src.models.task_config import ModelConfig, TaskConfig

# =============================================
PDF_NAME = "bst-bme280-ds002.pdf"
PROVIDER = "openai"
API_KEY = os.getenv("OPENAI_API_KEY")
MODEL_NAME = "gpt-5.6-terra"

THINKING_EFFORT = "medium"
MAX_TOKENS = 60000
TIMEOUT = 3600
# =============================================


DEFAULT_PDF_PATH = PROJECT_ROOT / "data" / "input_pdf" / PDF_NAME



class CodeFile(StructuredOutputModel):
    name: str = Field(description="Plain file basename without an extension.")
    file_type: str = Field(description="File extension: .ino, .cpp, or .h.")
    content: str = Field(description="Complete source content of the file.")


class CodeFilesOutput(StructuredOutputModel):
    files: list[CodeFile] = Field(
        description="Exactly three generated Arduino CodeFile objects."
    )


def resolve_pdf_path(path: Path) -> Path:
    if path.is_absolute():
        pdf_path = path
    else:
        project_relative_path = PROJECT_ROOT / path
        input_pdf_relative_path = PROJECT_ROOT / "data" / "input_pdf" / path
        pdf_path = (
            project_relative_path
            if project_relative_path.is_file()
            else input_pdf_relative_path
        )

    pdf_path = pdf_path.expanduser().resolve()
    if not pdf_path.is_file():
        raise FileNotFoundError(f"Input PDF not found: {pdf_path}")
    if pdf_path.suffix.lower() != ".pdf":
        raise ValueError(f"Input file must be a PDF: {pdf_path}")
    return pdf_path


def load_cached_pages(pdf_path: Path) -> tuple[Path, list[dict[str, Any]]]:
    ocr_path = OCR_DIR / f"{pdf_path.stem}.json"
    if not ocr_path.is_file():
        raise FileNotFoundError(
            f"Cached OCR result not found for {pdf_path.name}: {ocr_path}"
        )

    data = json.loads(ocr_path.read_text(encoding="utf-8"))
    pages = data.get("pages") if isinstance(data, dict) else data
    if not isinstance(pages, list) or not pages:
        raise ValueError(f"Cached OCR result contains no pages: {ocr_path}")
    if not all(isinstance(page, dict) for page in pages):
        raise ValueError(f"Cached OCR pages must be a list of objects: {ocr_path}")
    return ocr_path, pages


def build_runner() -> LLMTaskRunner:

    api_key = os.getenv("OPENAI_API_KEY", "").strip()
    if not api_key:
        raise RuntimeError("OPENAI_API_KEY is missing from the project .env file.")
    if not PROMPT_PATH.is_file():
        raise FileNotFoundError(f"Direct-generation prompt not found: {PROMPT_PATH}")

    task_config = TaskConfig(
        model=ModelConfig(
            provider=PROVIDER,
            is_batch=False,
            model_name=MODEL_NAME,
            thinking_effort=THINKING_EFFORT,
            max_tokens=MAX_TOKENS,
            timeout=TIMEOUT,
        ),
        system=PROMPT_PATH.read_text(encoding="utf-8"),
        output_format=CodeFilesOutput,
        memory_enabled=False,
    )
    return LLMTaskRunner.load_from_task_config(
        task_config=task_config,
        api_key=api_key,
        task_name="Direct code generation",
    )


def validate_code_files(code_files: list[CodeFile]) -> None:
    """Validate the minimal three-file contract before writing output."""
    expected_types = {".ino", ".cpp", ".h"}
    actual_types = {code_file.file_type for code_file in code_files}

    if len(code_files) != 3 or actual_types != expected_types:
        raise ValueError(
            "The LLM must return exactly one .ino, one .cpp, and one .h file."
        )

    for code_file in code_files:
        if not code_file.name.strip() or not code_file.content.strip():
            raise ValueError("Generated CodeFile names and contents must be non-empty.")
        if (
            code_file.name in {".", ".."}
            or Path(code_file.name).name != code_file.name
            or code_file.name.rstrip(" .") != code_file.name
            or any(character in code_file.name for character in '<>:"|?*')
            or code_file.name.lower().endswith(tuple(expected_types))
        ):
            raise ValueError(f"Unsafe generated file name: {code_file.name!r}")


def write_code_files(code_files: list[CodeFile], output_dir: Path) -> None:
    """Write the structured result and the three generated source files."""
    output_dir.mkdir(parents=True, exist_ok=True)
    (output_dir / "code_files.json").write_text(
        json.dumps(
            [code_file.model_dump(mode="json") for code_file in code_files],
            ensure_ascii=False,
            indent=2,
        ),
        encoding="utf-8",
    )

    for code_file in code_files:
        source_path = output_dir / f"{code_file.name}{code_file.file_type}"
        source_path.write_text(code_file.content, encoding="utf-8")


async def generate_code_files(
    pages: list[dict[str, Any]],
) -> list[CodeFile]:
    """Send only `pages` to the LLM and return the generated CodeFile list."""
    runner = build_runner()
    user_input = json.dumps({"pages": pages}, ensure_ascii=False)
    result: CodeFilesOutput = await runner.run(user_input)
    code_files = result.files
    validate_code_files(code_files)
    return code_files


def make_output_dir(pdf_path: Path, model_name: str) -> Path:
    """Create a filesystem-safe default output directory name."""
    model_slug = re.sub(r"[^A-Za-z0-9_.-]+", "_", model_name).strip("._")
    return DIRECT_GENERATION_DIR / pdf_path.stem / (model_slug or "model")


async def main() -> None:
    pdf_path = resolve_pdf_path(DEFAULT_PDF_PATH)
    ocr_path, pages = load_cached_pages(pdf_path)
    code_files = await generate_code_files(pages)

    output_dir = make_output_dir(pdf_path, MODEL_NAME)
    output_dir = output_dir.resolve()
    write_code_files(code_files, output_dir)

    print(f"Input PDF: {pdf_path}")
    print(f"Reused OCR: {ocr_path}")
    print(f"Generated {len(code_files)} CodeFile objects from {len(pages)} OCR pages.")
    print(f"Output directory: {output_dir}")
    for code_file in code_files:
        print(f"- {code_file.name}{code_file.file_type}")


if __name__ == "__main__":
    asyncio.run(main())
