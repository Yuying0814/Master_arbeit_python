from pathlib import Path
from typing import Any

from mistralai.client import Mistral
from src.config import API_KEY,INPUT_PDF_DIR



def run_mistral_ocr(file_path: Path) -> dict[str,Any]:
    """Run Mistral OCR on a local PDF file and return a OCRResponse object"""

    if not file_path.exists():
        raise FileNotFoundError(f"PDF file not found: {file_path}")

    if not file_path.is_file():
        raise ValueError(f"Path is not a file: {file_path}")

    uploaded_pdf = None

    with Mistral(api_key=API_KEY.mistral_api_key) as client:
        try:
            with file_path.open("rb") as pdf_file:
                # Upload the PDF and obtain a temporary file identifier
                uploaded_pdf = client.files.upload(
                    file={
                        "file_name": file_path.name,
                        "content": pdf_file,
                    },
                    purpose="ocr",
                )

            # Create a signed URL for OCR processing
            signed_url = client.files.get_signed_url(
                file_id=uploaded_pdf.id,
            )

            # Extract structured text, tables, and page metadata from the PDF
            ocr_response = client.ocr.process(
                model="mistral-ocr-latest",
                document={
                    "type": "document_url",
                    "document_url": signed_url.url,
                },
                table_format="html",
                include_image_base64=False,
            )

            # Return a OCRResponse object
            return ocr_response.model_dump()

        finally:
            if uploaded_pdf is not None:
                # Remove the temporary uploaded file from mistral cloud
                client.files.delete(file_id=uploaded_pdf.id)

