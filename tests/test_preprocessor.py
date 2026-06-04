from __future__ import annotations
import json
import sys
from pathlib import Path
from typing import Any

PROJECT_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(PROJECT_ROOT))

from src.preprocessing.config import PreprocessingConfig
from src.preprocessing.preprocessor import Preprocessor


def test_preprocessor_pipeline(pdf_name:str) -> None:
    """ Test for preprocessor pipeline """
    """ Test Results will be written to project root/data/output """

    pdf_path:Path = PROJECT_ROOT / "data" / "input_pdf" / pdf_name ## Enter real PDF Path Here for testing e.g. PROJECT_ROOT / "data" / "input_pdf" / "xxx"
    name = pdf_path.stem
    config = PreprocessingConfig.load_config(pdf=pdf_path)
    preprocessor = Preprocessor(config)

    preprocessor.run()

    output_dir = config.project_path.output_path
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