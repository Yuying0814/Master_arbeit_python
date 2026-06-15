from __future__ import annotations

import json
import inspect
import asyncio

from pathlib import Path
from typing import Any

from src.models.page_output import PageClassification
from src.llm.llm_task import LLMTask
from src.preprocessing.page.build_page_request import build_page_requests
from src.preprocessing.retrieval.find_relevant_page_range import find_relevant_page_range
from src.preprocessing.toc.resolve_toc_entries import resolve_toc_entries
from src.preprocessing.toc.toc_entry import extract_toc_entries
from src.preprocessing.mistral.mistral_client import MistralClient
from src.preprocessing.page.parse_results import parse_classification_content,parse_verification_contents
from src.preprocessing.toc.find_toc_pages import find_toc_pages
from src.preprocessing.utils.text_utils import remove_header_footer
from src.preprocessing.config import PreprocessingConfig

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

    task_classification: LLMTask | None
    task_reg_sum_verification:LLMTask | None
    task_reg_page_verification:LLMTask | None
    task_reg_index_extraction:LLMTask | None
    task_reg_map_extraction:LLMTask | None

    mistral_client: MistralClient

    config:PreprocessingConfig

    def __init__(self,config: PreprocessingConfig):
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
        self.reg_page_idx = []

        self.reg_sum_idx_from_toc = []
        self.reg_sum_idx_from_retrieval = []
        self.reg_sum_idx_from_llm = []
        self.reg_sum_candidate_idx = []
        self.reg_sum_page_idx = []

        self.reg_summary = {}
        self.reg_map = {}

        self.task_classification = None
        self.task_reg_sum_verification = None
        self.task_reg_page_verification = None
        self.task_reg_index_extraction = None
        self.task_reg_map_extraction = None

        self.mistral_client = MistralClient(config.get_apikey("mistral"))

    async def run(self):
        try:
            await self.pipeline()
            self.save_outputs()
        except Exception:
            await self.cleanup()
            raise

    async def pipeline(self):
        print("-----------------------------------------------------------------------\n")
        print("start running text preprocessor pipeline\n")
        print("-----------------------------------------------------------------------\n")
        self.run_ocr()
        await self.classify_pages()
        self.get_page_candidates()

        reg_sum_verify_task = asyncio.create_task(self.verify_reg_sum_pages())
        reg_page_verify_task = asyncio.create_task(self.verify_reg_pages())

        try:
            print("Waiting for completion of verification task for register summary pages:\n")
            await reg_sum_verify_task
            await self.extract_reg_index()

            print("Waiting for completion of verification task for register pages:\n")
            await reg_page_verify_task

            self.refine_classification()
            await self.extract_reg_map()

        except Exception:
            for task in (reg_sum_verify_task, reg_page_verify_task):
                if not task.done():
                    task.cancel()

            await asyncio.gather(
                reg_sum_verify_task,
                reg_page_verify_task,
                return_exceptions=True,
            )

            raise

    def run_ocr(self):
        ocr_config = self.config.mistral.task.get("ocr")
        if not _valid_mistral_config(ocr_config):
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

        toc_pages = _get_pages_by_ocr_index(pages,self.toc_page_idx)
        self.toc_entries = extract_toc_entries(toc_pages)

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

    async def classify_pages(self):
        task_config = self.config.llm_task_config.classify_pages
        task_name = inspect.currentframe().f_code.co_name
        input_Path = self.config.project_path.input_path/f"{task_name}.jsonl"

        user_requests = build_page_requests(
            request_name=task_name,
            all_pages = self.pages,
        )

        if not user_requests:
            print("No pages for classification task\n")
            return

        self.task_classification = LLMTask.load_from_task_config(
            task_config=task_config,
            api_key=self.config.get_apikey(task_config.model.provider),
            input_path=input_Path,
        )
        print("Classification task created\n")
        print("Waiting for completion of classification task for all pages:\n")

        contents = await self.task_classification.run(user_requests)

        if not getattr(self.task_classification, "has_valid_output", True):
            raise RuntimeError("Task classification failed\n")

        parse_classification_content(
            contents = contents,
            user_requests = user_requests,
            pages = self.pages)

        print("Classification completed\n")

    async def verify_reg_sum_pages(self):
        if not self.reg_sum_candidate_idx:
            self.reg_sum_page_idx = []
            print("No verification task for register summary\n")
            return []

        task_config = self.config.llm_task_config.verify_reg_sum_pages
        task_name = inspect.currentframe().f_code.co_name
        input_path = self.config.project_path.input_path/f"{task_name}.jsonl"

        candidate_pages = _get_pages_by_ocr_index(self.pages, self.reg_sum_candidate_idx)

        user_requests = build_page_requests(
            request_name=task_name,
            all_pages = self.pages,
            candidate_pages = candidate_pages,
        )

        self.task_reg_sum_verification = LLMTask.load_from_task_config(
            task_config=task_config,
            api_key=self.config.get_apikey(task_config.model.provider),
            input_path=input_path,
        )

        print("Task for verification of register summary pages created\n")

        contents = await self.task_reg_sum_verification.run(user_requests)

        if not getattr(self.task_reg_sum_verification, "has_valid_output", True):
            raise RuntimeError("Invalid output from register summary page verification")

        self.reg_sum_page_idx = parse_verification_contents(
            contents=contents,
            user_requests=user_requests,
            pages=candidate_pages,
        )

        print("Verification of register summary pages completed\n")
        return self.reg_sum_page_idx

    async def verify_reg_pages(self):
        if not self.reg_page_candidate_idx:
            self.reg_page_idx = []
            print("No verification task for register map\n")
            return []

        task_config = self.config.llm_task_config.verify_reg_pages
        task_name = inspect.currentframe().f_code.co_name
        inputPath = self.config.project_path.input_path/f"{task_name}.jsonl"

        page_candidates = _get_pages_by_ocr_index(self.pages,self.reg_page_candidate_idx)

        user_requests = build_page_requests(
            request_name=task_name,
            all_pages = self.pages,
            candidate_pages = page_candidates,
        )

        self.task_reg_page_verification = LLMTask.load_from_task_config(
            task_config=task_config,
            api_key=self.config.get_apikey(task_config.model.provider),
            input_path=inputPath,
        )

        print("Task for verification of register pages created\n")

        contents = await self.task_reg_page_verification.run(user_requests)

        if not getattr(self.task_reg_page_verification, "has_valid_output", True):
            raise RuntimeError("Invalid output from register page verification")

        self.reg_page_idx = parse_verification_contents(
            contents=contents,
            user_requests=user_requests,
            pages=page_candidates,
        )

        print("Verification of register pages completed\n")
        return self.reg_page_idx

    async def extract_reg_index(self):
        if not self.reg_sum_page_idx:
            print("No register summary page for index information extraction\n")
            self.reg_summary = {}
            return {}

        task_config = self.config.llm_task_config.extract_reg_index

        selected_pages = _select_extraction_pages(
            pages=self.pages,
            page_index=self.reg_sum_page_idx,
        )

        user_input = json.dumps(
            {
                "pages": selected_pages,
            },
            ensure_ascii=False,
        )

        self.task_reg_index_extraction = LLMTask.load_from_task_config(
            task_config=task_config,
            api_key=self.config.get_apikey(task_config.model.provider),
        )

        print("Start register index information extraction\n")

        result = await self.task_reg_index_extraction.run(user_input)

        if not getattr(self.task_reg_index_extraction, "has_valid_output", True):
            raise RuntimeError("Invalid output from register index information extraction")

        self.reg_summary = result
        print("Register index information extraction completed\n")
        return result

    async def extract_reg_map(self):
        if not self.reg_page_idx:
            print("No register page for register map extraction\n")
            self.reg_map = {}
            return {}

        task_config = self.config.llm_task_config.extract_reg_map

        selected_pages = _select_extraction_pages(
            pages=self.pages,
            page_index=self.reg_page_idx,
        )

        user_input = json.dumps(
            {
                "pages": selected_pages,
                "registers": self.reg_summary.get("registers", [])
            },
            ensure_ascii=False,
        )

        self.task_reg_map_extraction = LLMTask.load_from_task_config(
            task_config=task_config,
            api_key=self.config.get_apikey(task_config.model.provider),
        )

        print("Start register map extraction\n")

        result = await self.task_reg_map_extraction.run(user_input)

        if not getattr(self.task_reg_map_extraction, "has_valid_output", True):
            raise RuntimeError("Invalid output from register map extraction")

        self.reg_map = result
        print("Register map extraction completed\n")
        return result

    def refine_classification(self):
        sum_page_diff_idx = set(self.reg_sum_page_idx) ^ set(self.reg_sum_idx_from_llm)
        reg_page_diff_idx = set(self.reg_page_idx) ^ set(self.reg_page_idx_from_llm)

        page_index_map = {page["index"]: page for page in self.pages}

        for index in sum_page_diff_idx:
            classification = page_index_map[index].setdefault(
                "classification",
                PageClassification.get_default_value(),
            )
            classification["is_register_summary_relevant"] = (
                not classification["is_register_summary_relevant"]
            )

        for index in reg_page_diff_idx:
            classification = page_index_map[index].setdefault(
                "classification",
                PageClassification.get_default_value(),
            )
            classification["is_register_map_relevant"] = (
                not classification["is_register_map_relevant"]
            )

        print("Refinement completed\n")

    # def create_add_description_task(self):
    #     if all_classification_false(self.pages):
    #         for page in self.pages:
    #             page["description"] = PageDescription.get_default_value()
    #         print("All pages are not relevant to any topics\n")
    #         self.task_add_description = None
    #         return
    #
    #     config = self.config.openai.task["add_page_description"]
    #     name = inspect.currentframe().f_code.co_name
    #     input_path = self.config.project_path.input_path / f"{name}.jsonl"
    #
    #     page_candidates = [
    #         page
    #         for page in self.pages
    #         if any(bool(value) for value in page.get("classification", {}).values())
    #     ]
    #
    #     self.task_add_description = PageBatchTask(
    #         pages=page_candidates,
    #         batch_client=self.openai_batch_client,
    #         input_path=input_path,
    #         task_config=config,
    #     )
    #
    #     PageBatchTask.run_with_retry(self.task_add_description.submit_batch)
    #     print("Description task created\n")
    #
    # @staticmethod
    # def wait_and_collect(task:PageBatchTask):
    #     if not task:
    #         return
    #
    #     PageBatchTask.run_with_retry(task.wait_batch)
    #     PageBatchTask.run_with_retry(task.collect_batch_output)
    #     task.retry_batch()
    #
    #     if not task.has_valid_output:
    #         raise RuntimeError(f"Invalid output from {task.name}")
    #
    async def cleanup(self) -> None:
        cleanup_tasks = []

        if self.task_classification is not None:
            cleanup_tasks.append(self.task_classification.cleanup())

        if self.task_reg_sum_verification is not None:
            cleanup_tasks.append(self.task_reg_sum_verification.cleanup())

        if self.task_reg_page_verification is not None:
            cleanup_tasks.append(self.task_reg_page_verification.cleanup())

        if cleanup_tasks:
            await asyncio.gather(
                *cleanup_tasks,
                return_exceptions=True,
            )

    def save_outputs(self):
        name = self.pdf_path.stem
        output_dir = self.config.project_path.output_path / name
        output_dir.mkdir(parents=True, exist_ok=True)

        _write_json(
            output_dir / f"{name}_preprocessor_snapshot.json",
            _build_preprocessor_snapshot(self),
        )

        _write_json(
            output_dir / f"{name}_register_map.json",
            self.reg_map,
        )

        _write_json(
            output_dir / f"{name}_pages.json",
            self.pages,
        )

        _write_json(
            output_dir / f"{name}_token_consumption.json",
            _build_token_consumption_snapshot(self),
        )

# Helper
def _valid_mistral_config(config:dict[str,Any]) -> bool:
    if not config:
        return False
    required_keys = {"file_path"}
    optional_keys = {"model_name","table_format","include_image"}
    allowed_keys = required_keys | optional_keys

    missing_keys = required_keys - set(config.keys())
    extra_keys = set(config.keys()) - allowed_keys

    return not missing_keys and not extra_keys

# def _all_classification_false(pages: list[dict[str, Any]]) -> bool:
#     for page in pages:
#         classification = page.get("classification", {})
#         if any(bool(value) for value in classification.values()):
#             return False
#
#     return True

def _get_pages_by_ocr_index(pages:list[dict[str,Any]],page_indices) -> list[dict[str,Any]]:
    page_index_map = {page["index"]: page for page in pages}
    return [page_index_map[page_index] for page_index in page_indices]

def _select_extraction_pages(pages:list[dict[str,Any]],page_index:list[int]) -> list[dict[str,Any]]:
    selected_pages = _get_pages_by_ocr_index(
        pages,
        page_index,
    )

    return [
        {
            "index": page["index"],
            "markdown": page["markdown"],
            "tables": page.get("tables", []),
        }
        for page in selected_pages
    ]

def _make_json_safe(value: Any) -> Any:
    if isinstance(value, Path):
        return str(value)

    if isinstance(value, dict):
        return {
            str(key): _make_json_safe(item)
            for key, item in value.items()
        }

    if isinstance(value, list):
        return [
            _make_json_safe(item)
            for item in value
        ]

    if isinstance(value, tuple):
        return [
            _make_json_safe(item)
            for item in value
        ]

    if isinstance(value, (str, int, float, bool)) or value is None:
        return value

    return str(value)


def _build_preprocessor_snapshot(preprocessor: Preprocessor) -> dict[str, Any]:
    return {
        "pdf_path": preprocessor.pdf_path,
        "toc_page_idx": preprocessor.toc_page_idx,
        "toc_entries": preprocessor.toc_entries,
        "reg_page_idx_from_toc": preprocessor.reg_page_idx_from_toc,
        "reg_page_idx_from_retrieval": preprocessor.reg_page_idx_from_retrieval,
        "reg_page_idx_from_llm": preprocessor.reg_page_idx_from_llm,
        "reg_page_candidate_idx": preprocessor.reg_page_candidate_idx,
        "reg_page_idx": preprocessor.reg_page_idx,
        "reg_sum_idx_from_toc": preprocessor.reg_sum_idx_from_toc,
        "reg_sum_idx_from_retrieval": preprocessor.reg_sum_idx_from_retrieval,
        "reg_sum_idx_from_llm": preprocessor.reg_sum_idx_from_llm,
        "reg_sum_candidate_idx": preprocessor.reg_sum_candidate_idx,
        "reg_sum_page_idx": preprocessor.reg_sum_page_idx,
        "reg_summary": preprocessor.reg_summary,
        "reg_map": preprocessor.reg_map,
    }

def _build_token_consumption_snapshot(preprocessor: Preprocessor) -> dict[str,Any]:
    token_consumption = {}

    token_consumption["classification"] = _get_usage_from_task(preprocessor.task_classification)
    token_consumption["reg_sum_verification"] = _get_usage_from_task(preprocessor.task_reg_sum_verification)
    token_consumption["reg_page_verification"] = _get_usage_from_task(preprocessor.task_reg_page_verification)
    token_consumption["reg_index_extraction"] = _get_usage_from_task(preprocessor.task_reg_index_extraction)
    token_consumption["reg_map_extraction"] = _get_usage_from_task(preprocessor.task_reg_map_extraction)

    return token_consumption

def _get_usage_from_task(task:LLMTask | None) -> dict[str,Any]:
    if task is not None:
        return {
        "final_usage": getattr(task, "final_usage",{}),
        "total_usage": getattr(task, "total_usage",{}),
    }
    else:
        return{
            "final_usage": {},
            "total_usage": {},
        }

def _write_json(output_path: Path, data: Any) -> None:
    output_path.parent.mkdir(parents=True, exist_ok=True)

    output_path.write_text(
        json.dumps(
            _make_json_safe(data),
            ensure_ascii=False,
            indent=2,
        ),
        encoding="utf-8",
    )