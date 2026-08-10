from __future__ import annotations

import json
import inspect
import asyncio

from pathlib import Path
from typing import Any

from src.models.preprocessing.register_output import RegisterIndexOutput, RegisterMapOutput
from src.models.preprocessing.preprocessor import PreprocessorSnapshot,TaskModelsByName,PreprocessorOutput,PreprocessingTokenConsumption
from src.models.preprocessing.page_output import PageClassification
from src.models.llm.common import NormalizedTokenConsumption

from src.llm.ocr_task import OcrTask
from src.llm.llm_task_runner import LLMTaskRunner
from src.preprocessing.page.build_page_request import build_page_requests
from src.preprocessing.retrieval.find_relevant_page_range import find_relevant_page_range
from src.preprocessing.toc.resolve_toc_entries import resolve_toc_entries
from src.preprocessing.toc.toc_entry import extract_toc_entries
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

    reg_summary: RegisterIndexOutput
    reg_map: RegisterMapOutput

    classifier: LLMTaskRunner | None
    reg_sum_verifier:LLMTaskRunner | None
    reg_page_verifier:LLMTaskRunner | None
    reg_index_extractor:LLMTaskRunner | None
    reg_map_extractor:LLMTaskRunner | None

    config:PreprocessingConfig

    def __init__(
            self,
            config: PreprocessingConfig,
            ocr_result:dict[str,Any]|None = None,
    ) -> None:

        self.config = config

        self.pdf_path = Path()
        self.ocr_result = ocr_result if ocr_result else {}
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

        self.reg_summary = RegisterIndexOutput(registers=[])
        self.reg_map = RegisterMapOutput(registers=[])

        self.classifier = None
        self.reg_sum_verifier = None
        self.reg_page_verifier = None
        self.reg_index_extractor = None
        self.reg_map_extractor = None


    async def run(self,pdf_path:str|Path) -> PreprocessorOutput:
        self.pdf_path = _validate_pdf_path(pdf_path)
        try:
            await self.pipeline()
            return self.build_outputs()
        except Exception:
            await self.cleanup()
            raise

    async def pipeline(self) -> None:
        print("-----------------------------------------------------------------------\n")
        print("start running text preprocessor pipeline\n")
        print("-----------------------------------------------------------------------\n")
        self.run_ocr()
        await self.classify_pages()
        self.update_page_candidates()

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

    def run_ocr(self) -> list[dict[str,Any]]:
        if not self.ocr_result:
            api_key = (
                self.config.get_apikey("mistral")
                if self.config.ocr.provider == "mistral"
                else None
            )

            ocr_task = OcrTask(self.config.ocr, api_key)

            try:
                self.ocr_result = ocr_task.run(self.pdf_path)
            except (RuntimeError,ValueError,TypeError) as error:
                raise RuntimeError(f"OCR failed\n") from error

        raw_pages = self.ocr_result.get("pages")
        if not isinstance(raw_pages,list) or not raw_pages:
            raise ValueError("OCR returned no normalized pages.")

        pages = [
            {
                "index":page["index"],
                "markdown":page["markdown"],
                "tables":page["tables"],
            } for page in raw_pages]

        self.pages = remove_header_footer(pages)
        print("Ocr completed\n")

        return pages

    def save_ocr_result(self,**opts) -> bool:
        if "output_path" in opts and opts["output_path"]:
            output_path = Path(opts["output_path"])
        else:
            output_path = self.config.project_path.output_path/"ocr.json"
        try:
            with open(output_path,"w",encoding="utf-8") as file:
                file.write(json.dumps(self.ocr_result))
        except OSError as error:
            raise OSError(f"write ocr failed\n") from error

        return True

    def update_page_candidates(self) -> bool:
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

        return True

    async def classify_pages(self) -> bool:
        task_config = self.config.task_configs.classify_pages
        task_name = inspect.currentframe().f_code.co_name
        input_Path = self.config.project_path.input_path/f"{task_name}.jsonl"

        user_requests = build_page_requests(
            request_name=task_name,
            all_pages = self.pages,
        )

        if not user_requests:
            print("No pages for classification task\n")
            return True

        self.classifier = LLMTaskRunner.load_from_task_config(
            task_config=task_config,
            api_key=self.config.get_apikey(task_config.model.provider),
            input_path=input_Path,
        )
        print("Classification task created\n")
        print("Waiting for completion of classification task for all pages:\n")

        contents = await self.classifier.run(user_requests)

        if not getattr(self.classifier, "has_valid_output", True):
            raise RuntimeError("Task classification failed\n")

        parse_classification_content(
            contents = contents,
            user_requests = user_requests,
            pages = self.pages)

        print("Classification completed\n")
        return True

    async def verify_reg_sum_pages(self) -> list[int]:
        if not self.reg_sum_candidate_idx:
            self.reg_sum_page_idx = []
            print("No verification task for register summary\n")
            return []

        task_config = self.config.task_configs.verify_reg_sum_pages
        task_name = inspect.currentframe().f_code.co_name
        input_path = self.config.project_path.input_path/f"{task_name}.jsonl"

        candidate_pages = _get_pages_by_ocr_index(self.pages, self.reg_sum_candidate_idx)

        user_requests = build_page_requests(
            request_name=task_name,
            all_pages = self.pages,
            candidate_pages = candidate_pages,
        )

        self.reg_sum_verifier = LLMTaskRunner.load_from_task_config(
            task_config=task_config,
            api_key=self.config.get_apikey(task_config.model.provider),
            input_path=input_path,
        )

        print("Task for verification of register summary pages created\n")

        contents = await self.reg_sum_verifier.run(user_requests)

        if not getattr(self.reg_sum_verifier, "has_valid_output", True):
            raise RuntimeError("Invalid output from register summary page verification")

        self.reg_sum_page_idx = parse_verification_contents(
            contents=contents,
            user_requests=user_requests,
            pages=candidate_pages,
        )

        print("Verification of register summary pages completed\n")
        return self.reg_sum_page_idx

    async def verify_reg_pages(self) -> list[int]:
        if not self.reg_page_candidate_idx:
            self.reg_page_idx = []
            print("No verification task for register map\n")
            return []

        task_config = self.config.task_configs.verify_reg_pages
        task_name = inspect.currentframe().f_code.co_name
        inputPath = self.config.project_path.input_path/f"{task_name}.jsonl"

        page_candidates = _get_pages_by_ocr_index(self.pages,self.reg_page_candidate_idx)

        user_requests = build_page_requests(
            request_name=task_name,
            all_pages = self.pages,
            candidate_pages = page_candidates,
        )

        self.reg_page_verifier = LLMTaskRunner.load_from_task_config(
            task_config=task_config,
            api_key=self.config.get_apikey(task_config.model.provider),
            input_path=inputPath,
        )

        print("Task for verification of register pages created\n")

        contents = await self.reg_page_verifier.run(user_requests)

        if not getattr(self.reg_page_verifier, "has_valid_output", True):
            raise RuntimeError("Invalid output from register page verification")

        self.reg_page_idx = parse_verification_contents(
            contents=contents,
            user_requests=user_requests,
            pages=page_candidates,
        )

        print("Verification of register pages completed\n")
        return self.reg_page_idx

    async def extract_reg_index(self) -> RegisterIndexOutput:
        if not self.reg_sum_page_idx:
            print("No register summary page for index information extraction\n")
            self.reg_summary = RegisterIndexOutput(registers=[])
            return RegisterIndexOutput(registers=[])

        task_config = self.config.task_configs.extract_reg_index

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

        self.reg_index_extractor = LLMTaskRunner.load_from_task_config(
            task_config=task_config,
            api_key=self.config.get_apikey(task_config.model.provider),
        )

        print("Start register index information extraction\n")

        result = await self.reg_index_extractor.run(user_input)

        if not getattr(self.reg_index_extractor, "has_valid_output", True):
            raise RuntimeError("Invalid output from register index information extraction")

        self.reg_summary = result
        print("Register index information extraction completed\n")
        return result

    async def extract_reg_map(self) -> RegisterMapOutput:
        if not self.reg_page_idx:
            print("No register page for register map extraction\n")
            self.reg_map= RegisterMapOutput(registers=[])
            return RegisterMapOutput(registers=[])

        task_config = self.config.task_configs  .extract_reg_map

        selected_pages = _select_extraction_pages(
            pages=self.pages,
            page_index=self.reg_page_idx,
        )

        user_input = json.dumps(
            {
                "pages": selected_pages,
                "registers": self.reg_summary.model_dump()["registers"],
            },
            ensure_ascii=False,
        )

        self.reg_map_extractor = LLMTaskRunner.load_from_task_config(
            task_config=task_config,
            api_key=self.config.get_apikey(task_config.model.provider),
        )

        print("Start register map extraction\n")

        result = await self.reg_map_extractor.run(user_input)

        if not getattr(self.reg_map_extractor, "has_valid_output", True):
            raise RuntimeError("Invalid output from register map extraction")

        self.reg_map = result
        print("Register map extraction completed\n")
        return result

    def refine_classification(self) -> bool:
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

        return True

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
    async def cleanup(self) -> bool:
        cleanup_tasks = []

        if self.classifier is not None:
            cleanup_tasks.append(self.classifier.cleanup())

        if self.reg_sum_verifier is not None:
            cleanup_tasks.append(self.reg_sum_verifier.cleanup())

        if self.reg_page_verifier is not None:
            cleanup_tasks.append(self.reg_page_verifier.cleanup())

        if cleanup_tasks:
            await asyncio.gather(
                *cleanup_tasks,
                return_exceptions=True,
            )
        return True

    def build_outputs(self)-> PreprocessorOutput:

        snapshot = _build_preprocessor_snapshot(self)
        token_consumption = _build_token_consumption_snapshot(self)
        task_models = _build_task_models(self)

        return PreprocessorOutput(
            pages=self.pages,
            register_map=self.reg_map,
            snapshot=snapshot,
            task_models=task_models,
            token_consumption=token_consumption,
        )

# def _all_classification_false(pages: list[dict[str, Any]]) -> bool:
#     for page in pages:
#         classification = page.get("classification", {})
#         if any(bool(value) for value in classification.values()):
#             return False
#
#     return

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

def _build_preprocessor_snapshot(preprocessor: Preprocessor) -> PreprocessorSnapshot:
    return PreprocessorSnapshot(
        pdf_path = preprocessor.pdf_path,
        toc_page_idx = preprocessor.toc_page_idx,
        toc_entries = preprocessor.toc_entries,
        reg_page_idx_from_toc = preprocessor.reg_page_idx_from_toc,
        reg_page_idx_from_retrieval = preprocessor.reg_page_idx_from_retrieval,
        reg_page_idx_from_llm = preprocessor.reg_page_idx_from_llm,
        reg_page_candidate_idx = preprocessor.reg_page_candidate_idx,
        reg_page_idx = preprocessor.reg_page_idx,
        reg_sum_idx_from_toc = preprocessor.reg_sum_idx_from_toc,
        reg_sum_idx_from_retrieval = preprocessor.reg_sum_idx_from_retrieval,
        reg_sum_idx_from_llm = preprocessor.reg_sum_idx_from_llm,
        reg_sum_candidate_idx = preprocessor.reg_sum_candidate_idx,
        reg_sum_page_idx = preprocessor.reg_sum_page_idx,
        reg_summary = preprocessor.reg_summary,
        reg_map = preprocessor.reg_map,
    )

def _build_token_consumption_snapshot(preprocessor: Preprocessor) -> PreprocessingTokenConsumption:
    token_consumption= PreprocessingTokenConsumption(
        classification =_get_usage_from_task_runner(preprocessor.classifier),
        reg_sum_verification =_get_usage_from_task_runner(preprocessor.reg_sum_verifier),
        reg_page_verification =_get_usage_from_task_runner(preprocessor.reg_page_verifier),
        reg_index_extraction =_get_usage_from_task_runner(preprocessor.reg_index_extractor),
        reg_map_extraction =_get_usage_from_task_runner(preprocessor.reg_map_extractor)
    )
    return token_consumption

def _build_task_models(preprocessor: Preprocessor) -> TaskModelsByName:
    task_configs = preprocessor.config.task_configs

    task_models_by_name = {
        "ocr":preprocessor.config.ocr.model_name
    }

    for task_name in type(task_configs).model_fields:
        task_config = getattr(task_configs, task_name)
        model_name = task_config.model.model_name
        task_models_by_name[task_name] = model_name

    return TaskModelsByName.model_validate(task_models_by_name)

def _get_usage_from_task_runner(task: LLMTaskRunner | None) -> NormalizedTokenConsumption:
    if task is None:
        return NormalizedTokenConsumption()

    return task.token_consumption

def _validate_pdf_path(pdf_path: str|Path) -> Path:
    path = Path(pdf_path).expanduser().resolve()
    if not path.is_file():
        raise FileNotFoundError(f"PDF file not found: {path}")
    if path.suffix.casefold() != ".pdf":
        raise ValueError(f"Expected a PDF file: {path}")
    return path
