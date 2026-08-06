import warnings
from pathlib import Path
from typing import Any, Literal
from mistralai.client import Mistral


class MistralClient:
    mistral_client: Mistral

    def __init__(self,api_key:str) -> None:
        self.mistral_client = Mistral(api_key=api_key)

    def run_ocr(self,
                file_path:Path|str,
                model_name:str = "mistral-ocr-latest",
                table_format:Literal["markdown","html"] = "html",
                include_image:bool = True) -> dict[str,Any]:
        file_path = Path(file_path).resolve()

        if not file_path.exists():
            raise FileNotFoundError(f"PDF file not found: {file_path}")

        if not file_path.is_file():
            raise ValueError(f"Path is not a file: {file_path}")

        file_id = self.upload_pdf(file_path)

        try:
            signed_url = self.get_signed_url(file_id)
            ocr_result = self.get_ocr_result(
                signed_url,
                model_name,
                table_format,
                include_image)
            return ocr_result
        finally:
            self.delete_uploaded_file(file_id)


    def upload_pdf(self,file_path:Path) -> str:
        try:
            with file_path.open("rb") as pdf_file:
                uploaded_pdf = self.mistral_client.files.upload(
                    file={
                        "file_name": file_path.name,
                        "content": pdf_file,
                    },
                    purpose="ocr",
                )
            return uploaded_pdf.id
        except Exception as error:
            raise RuntimeError(f"Failed to upload PDF file: {file_path}") from error

    def get_signed_url(self,file_id:str) -> str:
        try:
            signed_url = self.mistral_client.files.get_signed_url(file_id=file_id)
            return signed_url.url
        except Exception as error:
            raise RuntimeError(f"Failed to get signed URL: {file_id}") from error


    def get_ocr_result(self,
                       signed_url:str,
                       model_name:str,
                       table_format:Literal["markdown","html"],
                       include_image:bool) -> dict[str,Any]:
        try:
            ocr_response = self.mistral_client.ocr.process(
                model=model_name,
                document={
                    "type": "document_url",
                    "document_url": signed_url,
                },
                table_format=table_format,
                include_image_base64=include_image,
            )
            return ocr_response.model_dump()
        except Exception as error:
            raise RuntimeError(f"Failed to get OCR result: {signed_url}") from error


    def delete_uploaded_file(self,file_id:str) -> None:
        try:
            self.mistral_client.files.delete(file_id=file_id)
        except Exception as error:
            warnings.warn(f"Failed to delete uploaded file: {file_id}\n{error}")


