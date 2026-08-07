from __future__ import annotations

from pathlib import Path
from typing import Any

from src.models.task_config import OcrConfig


class OcrTask:
    def __init__(self, config: OcrConfig, api_key: str|None = None) -> None:
        if config.provider == "mistral" and not api_key:
            raise ValueError("Mistral expects a valid API key.")

        self.config = config
        self.api_key = api_key

    def run(self,pdf: str | Path) -> dict[str, Any]:

        pdf = Path(pdf).resolve()
        if not pdf.is_file():
            raise FileNotFoundError(f"No such PDF file: {pdf}")

        raw_result = self._run_client(pdf)

        if not isinstance(raw_result, dict):
            raise TypeError("OCR client must return a dictionary.")

        pages = self._normalize_pages(raw_result)
        if not pages:
            raise ValueError("OCR result contains no pages.")

        return {
            "provider": self.config.provider,
            "model": raw_result.get("model") or self.config.model_name,
            "pages": pages,
            "raw_result": raw_result,
        }

    def _run_client(self,pdf: Path) -> dict[str, Any]:

        match self.config.provider:
            case "mistral":
                from src.llm.mistral.ocr.mistral_client import MistralClient

                assert self.api_key is not None
                client = MistralClient(self.api_key)

                return client.run_ocr(
                    file_path=pdf,
                    model_name=self.config.model_name,
                    table_format=self.config.table_format,
                    include_image=self.config.include_image,
                )
            case "glm":
                from src.llm.zai.ocr.ocr_client import GlmOcrClient

                client = GlmOcrClient(
                    url=self.config.url,
                    layout_device=self.config.layout_device,
                )

                return client.run_ocr(
                    file_path=pdf,
                    model_name=self.config.model_name,
                    table_format=self.config.table_format,
                    include_image=self.config.include_image,
                    connection_pool_size=self.config.connection_pool_size,
                    max_workers=self.config.max_workers,
                    batch_size=self.config.batch_size,
                )
            case _:
                raise ValueError(
                    f"Unsupported OCR provider: {self.config.provider}"
                )



    def _normalize_pages(self,raw_result: dict[str, Any]) -> list[dict[str, Any]]:
        match self.config.provider:
            case "mistral":
                return _normalize_mistral_pages(raw_result)
            case "glm":
                return _normalize_glm_pages(raw_result)
            case _:
                raise ValueError(
                    f"Unsupported OCR provider: {self.config.provider}"
                )


def _normalize_mistral_pages(raw_result: dict[str, Any],) -> list[dict[str, Any]]:

    raw_pages = raw_result.get("pages", [])
    if not isinstance(raw_pages, list):
        raise ValueError("Mistral OCR result must contain a pages list.")

    pages = []
    for page_index, page in enumerate(raw_pages):
        if not isinstance(page, dict):
            raise ValueError("Each Mistral OCR page must be a dictionary.")

        tables = page.get("tables", [])
        pages.append(
            {
                "index": page.get("index", page_index),
                "markdown": str(page.get("markdown", "")),
                "tables": tables if isinstance(tables, list) else [],
            }
        )

    return pages


def _normalize_glm_pages(raw_result: dict[str, Any],) -> list[dict[str, Any]]:

    raw_pages = raw_result.get("json_result", [])
    if not isinstance(raw_pages, list):
        raise ValueError("GLM-OCR result must contain a json_result list.")

    pages = []
    for page_index, regions in enumerate(raw_pages):
        if not isinstance(regions, list):
            raise ValueError("Each GLM-OCR page must contain a region list.")

        markdown_parts = []
        tables = []
        table_index = 0

        for region in regions:

            if not isinstance(region, dict):
                continue

            content = str(region.get("content") or "").strip()
            if not content:
                continue

            markdown_parts.append(content)

            if str(region.get("label", "")).casefold() == "table":
                tables.append(
                    {
                        "id":table_index,
                        "content":content,
                        "format":"html"
                    }
                )
                table_index += 1

        pages.append(
            {
                "index": page_index,
                "markdown": "\n\n".join(markdown_parts),
                "tables": tables,
            }
        )

    return pages
