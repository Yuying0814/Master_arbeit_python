from __future__ import annotations

import json
import inspect
from pathlib import Path
from typing import Any

from src.openai.openai_task import OpenAITask
from src.models.page_output import PageDescription
from src.preprocessing.retrieval.find_relevant_page_range import find_relevant_page_range
from src.preprocessing.toc.resolve_toc_entries import resolve_toc_entries
from src.preprocessing.toc.toc_entry import extract_toc_entries
from src.preprocessing.mistral.mistral_client import MistralClient
from src.preprocessing.page.parse_results import parse_classification_content,parse_verification_content,parse_description_content
from src.preprocessing.toc.find_toc_pages import find_toc_pages
from src.preprocessing.utils.text_utils import remove_header_footer
from src.preprocessing.page.page_batch_task import PageBatchTask
from src.openai.batch_client import OpenAIBatchClient
from src.config import Config

class Preprocessor:
    pdf_path: Path
    ocr_result:dict[str,Any]
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

    reg_summary: dict[str,Any]
    reg_map: dict[str,Any]

    openai_batch_client: OpenAIBatchClient
    mistral_client: MistralClient
    task_classification: PageBatchTask | None
    task_reg_sum_verification: PageBatchTask | None
    task_reg_page_verification: PageBatchTask | None
    task_add_description: PageBatchTask | None

    config:Config

    def __init__(self,config: Config):
        if not config.project_path.pdf_path.exists() or not config.project_path.pdf_path.is_file():
            raise FileNotFoundError

        self.config = config

        self.pdf_path = config.project_path.pdf_path
        self.ocr_result = {}
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

        self.reg_summary = {}
        self.reg_map = {}

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
        self.classify_pages()
        self.get_page_candidates()
        self.create_verification_task()

        try:
            print("Waiting for completion of verification task for register summary pages\n")
            self.wait_and_collect(self.task_reg_sum_verification)
            self.reg_sum_page_idx = parse_verification_content(self.task_reg_sum_verification)
            self.extract_reg_index()

            print("Waiting for completion of verification task for register pages\n")
            self.wait_and_collect(self.task_reg_page_verification)
            self.reg_page_idx = parse_verification_content(self.task_reg_page_verification)
            self.refine_classification()
            self.create_add_description_task()
            self.extract_reg_map()

            print("Waiting for completion of adding page descriptions\n")
            self.wait_and_collect(self.task_add_description)
            parse_description_content(self.task_add_description,self.pages)
        finally:
            self.cleanup()

    def run_ocr(self):
        ocr_config = self.config.mistral.task.get("ocr")
        if not valid_mistral_config(ocr_config):
           raise ValueError("OCR config not defined or not loaded\n")

        try:
            self.ocr_result = self.mistral_client.run_ocr(**ocr_config)
        except RuntimeError as error:
            raise RuntimeError(f"OCR failed\n") from error

        pages = [
            {
                "index":page["index"],
                "markdown":page["markdown"],
                "tables":page["tables"],
            } for page in self.ocr_result.get("pages")]

        self.pages = remove_header_footer(pages)
        print("Ocr completed\n")

    def save_ocr_result(self,**opts):
        if "output_path" in opts and opts["output_path"]:
            output_path = Path(opts["output_path"])
        else:
            output_path = self.config.project_path.output_path/"ocr.json"
        try:
            with open(output_path,"w",encoding="utf-8") as file:
                file.write(json.dumps(self.ocr_result))
        except OSError as error:
            raise OSError(f"write ocr failed\n") from error

    def get_page_candidates(self):
        pages = find_toc_pages(self.pages)
        self.toc_page_idx = [
            page["index"] for page in pages if page["result_toc"]["is_toc"]
        ]

        self.toc_entries = extract_toc_entries(
            [
                pages[i] for i in self.toc_page_idx
            ]
        )
        self.reg_page_idx_from_toc,self.reg_sum_idx_from_toc = resolve_toc_entries(self.toc_entries)

        pages = find_relevant_page_range(pages)
        self.reg_page_idx_from_retrieval = [
            page["index"] for page in pages if page["result_retrieval"]["is_reg_map_relevant"]
        ]
        self.reg_sum_idx_from_retrieval =[
            page["index"] for page in pages if page["result_retrieval"]["is_reg_sum_relevant"]
        ]

        self.reg_page_idx_from_llm = [
            page["index"] for page in pages if page["classification"]["is_register_map_relevant"]
        ]
        self.reg_sum_idx_from_llm = [
            page["index"] for page in pages if page["classification"]["is_register_summary_relevant"]
        ]

        self.reg_page_candidate_idx= sorted(set(self.reg_page_idx_from_toc+self.reg_page_idx_from_retrieval+self.reg_page_idx_from_llm))
        self.reg_sum_candidate_idx = sorted(set(self.reg_sum_idx_from_toc+self.reg_sum_idx_from_retrieval+self.reg_sum_idx_from_llm))
        print("Page candidates updated\n")

    def classify_pages(self):
        config = self.config.openai.task["classify_pages"]
        name = inspect.currentframe().f_code.co_name
        inputPath = self.config.project_path.input_path/f"{name}.json"

        self.task_classification = PageBatchTask(
            pages=self.pages,
            batch_client=self.openai_batch_client,
            input_path=inputPath,
            task_config=config,
        )
        print("Classification task created\n")
        self.task_classification.run()

        if not self.task_classification.has_valid_output:
            raise RuntimeError("Task classification failed\n")

        parse_classification_content(self.task_classification,self.pages)
        print("Classification completed\n")

    def create_verification_task(self):
        self.verify_reg_sum_pages()
        self.verify_reg_pages()
        print("Verification tasks created\n")

    def verify_reg_sum_pages(self):
        if not self.reg_sum_candidate_idx:
            self.task_reg_sum_verification = None
            print("No verification task for register summary\n")
            return

        config = self.config.openai.task["verify_reg_sum_pages"]
        name = inspect.currentframe().f_code.co_name
        inputPath = self.config.project_path.input_path/f"{name}.json"
        page_candidates = [
            self.pages[index]
            for index in self.reg_sum_candidate_idx
        ]

        self.task_reg_sum_verification = PageBatchTask(
            pages = page_candidates,
            batch_client = self.openai_batch_client,
            input_path = inputPath,
            task_config=config,
        )

        PageBatchTask.run_with_retry(self.task_reg_sum_verification.submit_batch)
        print("Task for verification of register summary pages created\n")

    def verify_reg_pages(self):
        if not self.reg_page_candidate_idx:
            self.task_reg_page_verification = None
            print("No verification task for register map\n")
            return

        config = self.config.openai.task["verify_reg_pages"]
        name = inspect.currentframe().f_code.co_name
        inputPath = self.config.project_path.input_path/f"{name}.json"
        page_candidates = [
            self.pages[index]
            for index in self.reg_page_candidate_idx
        ]

        self.task_reg_page_verification = PageBatchTask(
            pages = page_candidates,
            batch_client = self.openai_batch_client,
            input_path = inputPath,
            task_config=config,
        )

        PageBatchTask.run_with_retry(self.task_reg_page_verification.submit_batch)
        print("Task for verification of register pages created\n")

    def extract_reg_index(self):
        if not self.reg_sum_page_idx:
            print("No register summary page for index information extraction\n")
            return

        config = self.config.openai.task["extract_reg_index"]
        pages = [
            {
            "index": page["index"],
            "markdown": page["markdown"],
            "tables": page["tables"]
            } for page in self.pages]

        user = json.dumps(
            {
                "pages": [pages[index] for index in self.reg_sum_page_idx]
            }
        )
        print("Start register index information extraction\n")
        task_reg_index_extraction = OpenAITask(
            api_key=self.config.get_apikey("openai"),
            user = user,
            task_config=config,
        )
        self.reg_summary = task_reg_index_extraction.run()
        print("Register index extraction completed\n")

    def extract_reg_map(self):
        if not self.reg_page_idx:
            print("No register page for register map extraction\n")
            return
        config = self.config.openai.task["extract_reg_map"]
        pages = [
            {
            "index": page["index"],
            "markdown": page["markdown"],
            "tables": page["tables"]
            } for page in self.pages]

        if not self.reg_summary or "registers" not in self.reg_summary or not self.reg_summary["registers"]:
            registers = []
        else:
            registers = self.reg_summary["registers"]

        user = json.dumps(
            {
                "pages": [pages[index] for index in self.reg_page_idx],
                "registers":registers
            }
        )

        print("Start register map extraction\n")
        task_reg_map_extraction = OpenAITask(
            api_key=self.config.get_apikey("openai"),
            user = user,
            task_config=config,
        )
        self.reg_map = task_reg_map_extraction.run()
        print("Register map extraction completed\n")

    def refine_classification(self):
        sum_page_diff_idx = set(self.reg_sum_page_idx) ^ set(self.reg_sum_idx_from_llm)
        reg_page_diff_idx = set(self.reg_page_idx) ^ set(self.reg_page_idx_from_llm)

        for index in sum_page_diff_idx:
            classification = self.pages[index]["classification"]
            classification["is_register_summary_relevant"] = (
                not classification["is_register_summary_relevant"]
            )

        for index in reg_page_diff_idx:
            classification = self.pages[index]["classification"]
            classification["is_register_map_relevant"] = (
                not classification["is_register_map_relevant"]
            )
        print("Refinement completed\n")

    def create_add_description_task(self):
        if all_classification_false(self.pages):
            for page in self.pages:
                page["description"] = PageDescription.get_default_value()
            print("All pages are not relevant to any topics\n")
            self.task_add_description = None
            return

        config = self.config.openai.task["add_page_description"]
        name = inspect.currentframe().f_code.co_name
        input_path = self.config.project_path.input_path / f"{name}.jsonl"

        page_candidates = [
            page
            for page in self.pages
            if any(bool(value) for value in page.get("classification", {}).values())
        ]

        self.task_add_description = PageBatchTask(
            pages=page_candidates,
            batch_client=self.openai_batch_client,
            input_path=input_path,
            task_config=config,
        )

        PageBatchTask.run_with_retry(self.task_add_description.submit_batch)
        print("Description task created\n")

    @staticmethod
    def wait_and_collect(task:PageBatchTask):
        if not task:
            return

        PageBatchTask.run_with_retry(task.wait_batch)
        PageBatchTask.run_with_retry(task.collect_batch_output)
        task.retry_batch()

        if not task.has_valid_output:
            raise RuntimeError(f"Invalid output from {task.name}")

    def cleanup(self):
        if self.task_reg_sum_verification:
            self.task_reg_sum_verification.cleanup()

        if self.task_reg_page_verification:
            self.task_reg_page_verification.cleanup()

        if self.task_add_description:
            self.task_add_description.cleanup()

# Helper
def valid_mistral_config(config:dict[str,Any]) -> bool:
    if not config:
        return False
    required_keys = {"file_path"}
    optional_keys = {"model_name","table_format","include_image"}
    allowed_keys = required_keys | optional_keys

    missing_keys = required_keys - set(config.keys())
    extra_keys = set(config.keys()) - allowed_keys

    return not missing_keys and not extra_keys

def valid_openai_config(config:dict[str,Any]) -> bool:
    if not config:
        return False
    allowed_keys = {"model","prompt_path","text_format","tools","max_output_tokens"}
    return set(config.keys()).issubset(allowed_keys)

def all_classification_false(pages: list[dict[str, Any]]) -> bool:
    for page in pages:
        classification = page.get("classification", {})
        if any(bool(value) for value in classification.values()):
            return False

    return True
