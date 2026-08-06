from __future__ import annotations

import json
import os
import sys
from pathlib import Path
from urllib.error import URLError
from urllib.request import urlopen

import pymupdf


PROJECT_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(PROJECT_ROOT))

from src.llm.zai.ocr.ocr_client import GlmOcrClient


def test_glm_ocr_client_run() -> None:
    pdf_path = Path(
        os.getenv(
            "GLM_OCR_TEST_PDF",
            str(
                PROJECT_ROOT
                / "data"
                / "input_pdf"
                / "ITG-3050-Register-Map.pdf"
            ),
        )
    ).resolve()

    ollama_url = os.getenv(
        "GLM_OCR_TEST_URL",
        "http://localhost:11434",
    ).rstrip("/")

    model_name = os.getenv(
        "GLM_OCR_TEST_MODEL",
        "glm-ocr:latest",
    )

    layout_device = os.getenv(
        "GLM_OCR_LAYOUT_DEVICE",
        "cpu",
    )

    assert pdf_path.is_file(), f"Test PDF not found: {pdf_path}"
    _assert_ollama_ready(ollama_url, model_name)
    output_dir = PROJECT_ROOT / "data" / "output" / "glm_ocr_test"
    output_dir.mkdir(parents=True, exist_ok=True)
    test_pdf = _extract_page(pdf_path, output_dir)

    client = GlmOcrClient(
        url=ollama_url,
        layout_device=layout_device,
    )

    raw_result = client.run_ocr(
        file_path=test_pdf,
        model_name=model_name,
        table_format="html",
        include_image=False,
        connection_poor_size=1,
        max_workers=1,
        batch_size=1,
    )

    assert isinstance(raw_result, dict)

    json_result = raw_result.get("json_result")
    assert isinstance(json_result, list)
    assert json_result, "GLM-OCR returned no pages."
    assert all(isinstance(page, list) for page in json_result)

    regions = [
        region
        for page in json_result
        for region in page
        if isinstance(region, dict)
    ]
    assert regions, "GLM-OCR returned no layout regions."
    assert any(
        str(region.get("content") or "").strip()
        for region in regions
    ), "GLM-OCR returned no recognized content."

    markdown_result = raw_result.get("markdown_result")
    assert isinstance(markdown_result, str)
    assert markdown_result.strip(), "GLM-OCR returned empty Markdown."

    output_path = output_dir / f"{pdf_path.stem}_raw_result.json"
    output_path.write_text(
        json.dumps(
            raw_result,
            ensure_ascii=False,
            indent=2,
        ),
        encoding="utf-8",
    )


def _extract_page(source_pdf: Path,output_dir: Path,) -> Path:
    output_pdf = output_dir / f"{source_pdf.stem}_one_page.pdf"

    with pymupdf.open(source_pdf) as source:
        assert source.page_count > 0, f"PDF has no pages: {source_pdf}"

        with pymupdf.open() as target:
            target.insert_pdf(
                source,
                from_page=5,
                to_page=5,
            )
            target.save(output_pdf)

    return output_pdf


def _assert_ollama_ready(ollama_url: str,model_name: str) -> None:
    try:
        with urlopen(
            f"{ollama_url}/api/tags",
            timeout=5,
        ) as response:
            payload = json.load(response)
    except (OSError, URLError, json.JSONDecodeError) as error:
        raise AssertionError(
            f"Ollama is not available at {ollama_url}."
        ) from error

    installed_models = {
        str(model.get("name") or model.get("model") or "")
        for model in payload.get("models", [])
        if isinstance(model, dict)
    }
    requested_model = model_name.partition(":")[0]

    assert any(
        installed.partition(":")[0] == requested_model
        for installed in installed_models
    ), (
        f"Ollama model {model_name!r} is not installed. "
        "Run: ollama pull glm-ocr:latest"
    )
