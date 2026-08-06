from __future__ import annotations

from glmocr import GlmOcr
from pathlib import Path
from typing import Any, Literal


class GlmOcrClient:
    def __init__(
        self,
        url:str = "http://localhost:11434",
        layout_device: str = "cpu",
    ) -> None:
        self.url = url
        self.layout_device = layout_device

    def run_ocr(
        self,
        file_path: str | Path,
        model_name: str = "glm-ocr:latest",
        table_format: Literal["markdown", "html"] = "html",
        include_image: bool = True,
        connection_poor_size:int = 1,
        max_workers:int = 1,
        batch_size:int = 1,
    ) -> dict[str, Any]:


        file_path = Path(file_path).resolve()
        self._validate_pdf(file_path)

        if table_format != "html":
            raise ValueError("GLM-OCR supports HTML table output only.")

        try:
            with GlmOcr(
                mode="selfhosted",
                model=model_name,
                layout_device=self.layout_device,
                _dotted={
                    "pipeline.ocr_api.api_url": f"{self.url}/api/generate",
                    "pipeline.ocr_api.api_mode": "ollama_generate",
                    "pipeline.ocr_api.connection_pool_size": connection_poor_size,
                    "pipeline.max_workers": max_workers,
                    "pipeline.layout.batch_size": batch_size,
                    "pipeline.result_formatter.output_format": "both",
                },
            ) as parser:
                result = parser.parse(
                    file_path,
                    save_layout_visualization=include_image,
                )
        except Exception as error:
            raise RuntimeError(
                f"Failed to get local GLM-OCR result: {file_path}"
            ) from error

        raw_result = result.to_dict()
        if raw_result.get("error"):
            raise RuntimeError(
                f"GLM-OCR failed: {raw_result['error']}"
            )

        return raw_result

    @staticmethod
    def _validate_pdf(file_path: Path) -> None:
        if not file_path.is_file():
            raise FileNotFoundError(f"No such PDF file: {file_path}")

        if file_path.suffix.casefold() != ".pdf":
            raise ValueError(f"Input file must be a PDF: {file_path}")
