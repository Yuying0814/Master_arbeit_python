from __future__ import annotations
from pathlib import Path
from typing import Any


from preprocessing.mistral.mistral_client import MistralClient
from src.preprocessing.page.page_batch_task import PageBatchTask
from src.openai.batch_client import OpenAIBatchClient
from src.config import Config

class Preprocessor:
    pdf_path: Path
    ocr_result:dict[str,Any]
    pages:dict[str,Any]

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
    reg_map: dict[str,Any]

    openai_batch_client:OpenAIBatchClient
    mistral_client:MistralClient
    task_classification:PageBatchTask
    task_reg_sum_verification:PageBatchTask
    task_reg_page_verification:PageBatchTask
    task_add_description:PageBatchTask

    config:Config

    def __init__(self,config: Config):
        if not config.project_path.pdf_path.exists() or config.project_path.pdf_path.is_file():
            raise FileNotFoundError

        self.config = config
        self.pdf_path = config.project_path.pdf_path
        self.config = config
        self.openai_batch_client = OpenAIBatchClient(config.get_apikey("openai"))
        self.mistral_client = MistralClient(config.get_apikey("mistral"))

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
        except Exception as e:
            pass




