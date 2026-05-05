from src.config import INPUT_PDF_DIR
from src.text_vorverarbeiter.ocr.mistral_ocr import run_mistral_ocr
from src.text_vorverarbeiter.models.pages import pages_from_ocr


file_path =INPUT_PDF_DIR/"ITG-3050-Register-Map.pdf"
ocr_data= run_mistral_ocr(file_path)
pages = pages_from_ocr(ocr_data)
