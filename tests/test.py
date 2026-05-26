from src.config import INPUT_PDF_DIR
from src.preprocessing.mistral.mistral_client import run_mistral_ocr
from src.preprocessing.models.pages import pages_from_ocr


file_path =INPUT_PDF_DIR/"ITG-3050-Register-Map.pdf"
ocr_data= run_mistral_ocr(file_path)
pages = pages_from_ocr(ocr_data)

