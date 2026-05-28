from __future__ import annotations
from pathlib import Path
from typing import Any

import config
from preprocessing.mistral.mistral_client import MistralClient
from preprocessing.page.parse_results import parse_classification_content,parse_verification_content,parse_description_content
from src.preprocessing.page.page_batch_task import PageBatchTask
from src.openai.batch_client import OpenAIBatchClient
from src.config import Config


def all_classification_false(pages):
    pass


class Preprocessor:
    pdf_path: Path
    ocr_result:list[dict[str,Any]]
    pages:list[dict[str,Any]]

    toc_page_idx: list[int]
    toc_entries: list[dict[str,Any]]

    reg_page_idx_from_toc: list[int]
    reg_page_idx_from_retrieval: list[int]
    reg_page_idx_from_llm: list[int]
    reg_page_candidate_idx: list[int]
    reg_page_idx: list[int]

    reg_sum_idx_from_toc: list[int]
    reg_sum_idx_from_retrieval: list[int]
    reg_sum_idx_from_llm: list[int]
    reg_sum_candidate_idx: list[int]
    reg_sum_page_idx: list[int]

    reg_summary: list[dict[str,Any]]
    reg_map: list[dict[str,Any]]

    openai_batch_client: OpenAIBatchClient | None
    mistral_client: MistralClient | None
    task_classification: PageBatchTask | None
    task_reg_sum_verification: PageBatchTask | None
    task_reg_page_verification: PageBatchTask | None
    task_add_description: PageBatchTask | None

    config:Config

    def __init__(self,config: Config):
        if not config.project_path.pdf_path.exists() or config.project_path.pdf_path.is_file():
            raise FileNotFoundError

        self.config = config

        self.pdf_path = config.project_path.pdf_path
        self.ocr_result = []
        self.pages = []

        self.toc_page_idx = []
        self.toc_entries = []

        self.reg_page_idx_from_toc = []
        self.reg_page_idx_from_retrieval = []
        self.reg_page_idx_from_llm = []
        self.reg_page_candidate_idx = []

        self.reg_sum_idx_from_toc = []
        self.reg_sum_idx_from_retrieval = []
        self.reg_sum_idx_from_llm = []
        self.reg_sum_candidate_idx = []
        self.reg_sum_page_idx = []

        self.reg_sum_summary = []
        self.reg_map = []

        self.openai_batch_client = OpenAIBatchClient(config.get_apikey("openai"))
        self.mistral_client = MistralClient(config.get_apikey("mistral"))
        self.task_classification = None
        self.task_reg_sum_verification = None
        self.task_reg_page_verification = None
        self.task_add_description = None

    def run(self):
        self.pipeline()

    def pipeline(self):
        self.run_ocr()
        print("Ocr completed")

        self.classify_pages()
        print("Classification completed")

        self.get_page_candidates()
        print("Page candidates updated")

        self.create_verification_task()
        print("Verification task created")

        try:
            self.wait_and_collect(self.task_reg_sum_verification)
            self.task_reg_sum_verification.cleanup()

            if self.task_reg_sum_verification:
                self.reg_sum_page_idx = parse_verification_content()
            print("Start register map extraction")
            self.extract_reg_Index()
            print("Register index extraction completed")
            self.wait_and_collect(self.task_reg_page_verification)

            if self.task_reg_page_verification:
                self.reg_page_idx = parse_verification_content()

            self.refine_classification()
            print("Refinement completed")

            if not all_classification_false(self.pages):
                self.create_description_task()
                print("Description task created")
                print("Start register map extraction")

            self.extract_reg_map()
            print("Register map extraction completed")

            self.wait_and_collect(self.task_add_description)

            if self.task_add_description:
                self.pages = parse_description_content()
            print("Page description added")
        finally:
            self.cleanup()

    def run_ocr(self):
        ocr_config = config.MistralConfig.task.get("ocr_config")
        try:
            if not ocr_config:
                raise ValueError("OCR config not defined or not loaded")

            if
            self.mistral_client.run_ocr(**ocr_config)
        except Exception as e:




# Helper
def valid_mistral_config(config:dict[str,Any]) -> bool:
    required_keys = {"file_path"}
    optional_keys = {"model_name","table_format","include_image"}
    allowed_keys = required_keys | optional_keys

    missing_keys = required_keys - set(config.keys())
    extra_keys = set(config.keys()) - allowed_keys

    return not missing_keys and not extra_keys

def valid_openai_config(config:dict[str,Any]) -> bool:
    allowed_keys = {"model","prompt_path","text_format","tools","max_output_tokens"}


