"""Global configuration for the Textvorarbeiter project."""

import os
from dotenv import load_dotenv
from pathlib import Path
from dataclasses import dataclass

#
@dataclass(frozen=True)
class APIKey:
    openai_api_key: str
    mistral_api_key: str

#
def load_api_key():
    load_dotenv(dotenv_path=ENV_DIR)
    return APIKey(
        openai_api_key=os.getenv("OPENAI_API_KEY",""),
        mistral_api_key=os.getenv("MISTRAL_API_KEY",""),
    )


# Path definition
ROOT_FILE = Path(__file__).resolve().parents[1]
ENV_DIR = ROOT_FILE / '.env'
DATA_DIR = ROOT_FILE / 'data'
INPUT_PDF_DIR = DATA_DIR / 'input_pdf'
OUTPUT_JSONL_DIR = DATA_DIR / 'output_jsonl'
OUTPUT_OCR_DIR = DATA_DIR / 'output_ocr'
PROMPTS_DIR = ROOT_FILE / 'prompts'
SRC_DIR = ROOT_FILE / 'src'
PDFS_DIR = DATA_DIR / 'pdfs'

# API KEY
API_KEY = load_api_key()
