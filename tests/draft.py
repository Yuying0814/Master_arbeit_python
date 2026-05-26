from src.preprocessing.mistral.mistral_client import MistralClient
from dotenv import load_dotenv
from pathlib import Path
from preprocessing.toc.find_toc_pages import find_toc_pages
import os

env_path = Path.cwd().parent / '.env'
load_dotenv(dotenv_path=env_path)
api_key = os.getenv("MISTRAL_API_KEY")
pdf = Path.cwd().parent / "data" / "input_pdf" / "ITG-3050-Register-Map.pdf"

client = MistralClient(api_key=api_key)
ocr_result = client.run_ocr(pdf)
pages = ocr_result["pages"]

outpages = find_toc_pages(pages)
pass
