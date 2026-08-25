from __future__ import annotations
import json
import sys
import asyncio


from pathlib import Path
from typing import Any

PROJECT_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(PROJECT_ROOT))

from src.preprocessing.config import PreprocessingConfig
from src.preprocessing.preprocessor import Preprocessor

def configure_coding_models(config: PreprocessingConfig) -> None:
    """Configure model settings for the current preprocessing run."""
    """Available settings for each task:
        provider: str, "openai", "ollama"
        is_batch: bool, True, False (better not change)
        model_name: str, "gpt-5-mini", "gpt-5.4", ...
        temperature: int
        max_tokens: int
    """
    model_settings: dict[str, dict[str, Any]] = {
        "classify_pages": {
            "provider": "openai",
            "is_batch": True,
            "model_name": "gpt-5-mini",
            "temperature": 0.0,
            "max_tokens": 2000,
        },
        "verify_reg_sum_pages": {
            "provider": "openai",
            "is_batch": True,
            "model_name": "gpt-5-mini",
            "temperature": 0.0,
            "max_tokens": 1000,
        },
        "verify_reg_pages": {
            "provider": "openai",
            "is_batch": True,
            "model_name": "gpt-5-mini",
            "temperature": 0.0,
            "max_tokens": 1000,
        },
        "extract_reg_index": {
            "provider": "openai",
            "is_batch": False,
            "model_name": "gpt-5-mini",
            "temperature": 0.0,
            "max_tokens": 20000,
        },
        "extract_reg_map": {
            "provider": "openai",
            "is_batch": False,
            "model_name": "gpt-5.4",
            "temperature": 0.0,
            "max_tokens": 100000,
        },
    }

    for task_name, settings in model_settings.items():
        task_config = getattr(config.task_configs, task_name)

        for field_name, value in settings.items():
            setattr(task_config.model, field_name, value)

def test_preprocessor_pipeline(pdf_path:Path) -> None:
    """ Test for preprocessor pipeline """
    """ Test Results will be written to project root/data/output """

    pdf_path:Path = PROJECT_ROOT / "data" / "input_pdf" / pdf_path ## Enter real PDF Path Here for testing e.g. PROJECT_ROOT / "data" / "input_pdf" / "xxx"
    name = pdf_path.stem
    config = PreprocessingConfig.load_config(pdf=pdf_path)
    preprocessor = Preprocessor(config)

    asyncio.run(preprocessor.run())

    output_dir = config.project_path.output_path / name

    output_dir.mkdir(parents=True, exist_ok=True)

    write_json(
        output_dir / f"{name}_preprocessor_snapshot.json",
        build_preprocessor_snapshot(preprocessor),
    )

    write_json(
        output_dir / f"{name}_register_map.json",
        preprocessor.reg_map,
    )

    write_json(
        output_dir / f"{name}_pages.json",
        preprocessor.pages,
    )

    assert preprocessor.pages

def make_json_safe(value: Any) -> Any:
    if isinstance(value, Path):
        return str(value)

    if isinstance(value, dict):
        return {
            str(key): make_json_safe(item)
            for key, item in value.items()
        }

    if isinstance(value, list):
        return [
            make_json_safe(item)
            for item in value
        ]

    if isinstance(value, tuple):
        return [
            make_json_safe(item)
            for item in value
        ]

    if isinstance(value, (str, int, float, bool)) or value is None:
        return value

    return str(value)


def build_preprocessor_snapshot(preprocessor: Preprocessor) -> dict[str, Any]:
    return {
        "pdf_path": preprocessor.pdf_path,
        "toc_page_idx": preprocessor.toc_page_idx,
        "toc_entries": preprocessor.toc_entries,
        "reg_page_idx_from_toc": preprocessor.reg_page_idx_from_toc,
        "reg_page_idx_from_retrieval": preprocessor.reg_page_idx_from_retrieval,
        "reg_page_idx_from_llm": preprocessor.reg_page_idx_from_llm,
        "reg_page_candidate_idx": preprocessor.reg_page_candidate_idx,
        "reg_page_idx": preprocessor.reg_page_idx,
        "reg_sum_idx_from_toc": preprocessor.reg_sum_idx_from_toc,
        "reg_sum_idx_from_retrieval": preprocessor.reg_sum_idx_from_retrieval,
        "reg_sum_idx_from_llm": preprocessor.reg_sum_idx_from_llm,
        "reg_sum_candidate_idx": preprocessor.reg_sum_candidate_idx,
        "reg_sum_page_idx": preprocessor.reg_sum_page_idx,
        "reg_summary": preprocessor.reg_summary,
        "reg_map": preprocessor.reg_map,
    }

def write_json(output_path: Path, data: Any) -> None:
    output_path.parent.mkdir(parents=True, exist_ok=True)

    output_path.write_text(
        json.dumps(
            make_json_safe(data),
            ensure_ascii=False,
            indent=2,
        ),
        encoding="utf-8",
    )