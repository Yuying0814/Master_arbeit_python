from __future__ import annotations

import json
import inspect
import asyncio
import time

from pathlib import Path
from typing import Any

from src.models.preprocessing.register_output import RegisterIndexOutput, RegisterMapOutput
from src.models.preprocessing.preprocessor import PreprocessorSnapshot,TaskModelsByName,PreprocessorOutput,PreprocessingTokenConsumption,TimeConsumption
from src.models.preprocessing.page_output import PageClassification
from src.models.preprocessing.function_identifier import FunctionIdentifierInput,DeviceFunctionOutput
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
    ocr_path: Path
    original_pages: list[dict[str,Any]]
    pages: list[dict[str,Any]]
    time_consumption:TimeConsumption

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

    device_functions:DeviceFunctionOutput

    classifier: LLMTaskRunner | None
    reg_sum_verifier:LLMTaskRunner | None
    reg_page_verifier:LLMTaskRunner | None
    reg_index_extractor:LLMTaskRunner | None
    reg_map_extractor:LLMTaskRunner | None
    function_identifier:LLMTaskRunner|None

    config:PreprocessingConfig

    def __init__(
            self,
            config: PreprocessingConfig,
    ) -> None:

        self.config = config

        self.pdf_path = Path()
        self.ocr_result = {}
        self.ocr_path = Path()
        self.original_pages = []
        self.pages = []
        self.time_consumption = TimeConsumption()

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

        self.device_functions = DeviceFunctionOutput(device_functions=[])

        self.classifier = None
        self.reg_sum_verifier = None
        self.reg_page_verifier = None
        self.reg_index_extractor = None
        self.reg_map_extractor = None
        self.function_identifier = None


    async def run(self,pdf_path:str|Path) -> PreprocessorOutput:
        start_time = time.perf_counter()
        try:
            self.pdf_path = _validate_pdf_path(pdf_path)
            provider = self.config.ocr.provider
            model = self.config.ocr.model_name

            self.ocr_path = self.config.project_path.output_path/"ocr"/provider/model/f"{self.pdf_path.stem}.json"

            try:
                await self.pipeline()
            except Exception as error:
                await self.cleanup()
                raise RuntimeError("Preprocessing failed") from error
        finally:
            elapsed_time = time.perf_counter() - start_time
            self.time_consumption.total = elapsed_time

        return self.build_outputs()


    async def pipeline(self) -> None:
        print("=======================================================================\n")
        print("start running text preprocessor pipeline\n")
        print("=======================================================================\n")

        self.ocr_result = self._load_ocr_if_exists() or self.run_ocr()
        self.pages = self._get_pages()
        self.original_pages = self._get_pages()

        await self.classify_pages()
        self.update_page_candidates()

        reg_sum_verify_task = asyncio.create_task(self.verify_reg_sum_pages())
        reg_page_verify_task = asyncio.create_task(self.verify_reg_pages())

        try:
            await reg_sum_verify_task
            await self.extract_reg_index()

            await reg_page_verify_task

            self.refine_classification()
            await self.extract_reg_map()
            await self.identify_function()

        except Exception as error:
            for task in (reg_sum_verify_task, reg_page_verify_task):
                if not task.done():
                    task.cancel()

            await asyncio.gather(
                reg_sum_verify_task,
                reg_page_verify_task,
                return_exceptions=True,
            )

            raise RuntimeError("Pipeline failed") from error

    def run_ocr(self) -> dict[str,Any]:
        api_key = (
            self.config.get_apikey("mistral")
            if self.config.ocr.provider == "mistral"
            else None
        )

        ocr_task = OcrTask(self.config.ocr, api_key)

        try:
            ocr_result = ocr_task.run(self.pdf_path)

        except (RuntimeError,ValueError,TypeError) as error:
            raise RuntimeError(f"OCR failed\n") from error

        self.save_ocr_result(ocr_result)
        self.time_consumption.ocr = ocr_task.elapsed_time
        return ocr_result

    def save_ocr_result(self,ocr_result:dict[str,Any]) -> Path:

        output_path = self.ocr_path

        try:
            output_path.parent.mkdir(parents=True, exist_ok=True)
            with open(output_path,"w",encoding="utf-8") as file:
                file.write(json.dumps(ocr_result))
        except OSError as error:
            raise OSError(f"write ocr failed\n") from error

        return self.ocr_path

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
        print("\nPage candidates updated")

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
            task_name = "page_classification",
            task_config=task_config,
            api_key=self.config.get_apikey(task_config.model.provider),
            input_path=input_Path,
        )
        print("\nClassification task created")

        contents = await self.classifier.run(user_requests)

        if not getattr(self.classifier, "has_valid_output", True):
            raise RuntimeError("Task classification failed\n")

        parse_classification_content(
            contents = contents,
            user_requests = user_requests,
            pages = self.pages
        )

        print("Classification completed")
        self.time_consumption.page_classification = self.classifier.elapsed_time
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
            task_name="register_summary_page_verification",
            task_config=task_config,
            api_key=self.config.get_apikey(task_config.model.provider),
            input_path=input_path,
        )

        print("\nTask for verification of register summary pages created")

        contents = await self.reg_sum_verifier.run(user_requests)

        if not getattr(self.reg_sum_verifier, "has_valid_output", True):
            raise RuntimeError("Invalid output from register summary page verification")

        self.reg_sum_page_idx = parse_verification_contents(
            contents=contents,
            user_requests=user_requests,
            pages=candidate_pages,
        )

        print("Verification of register summary pages completed")
        self.time_consumption.register_summary_page_verification = self.reg_sum_verifier.elapsed_time
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
            task_name="register_page_verification",
            task_config=task_config,
            api_key=self.config.get_apikey(task_config.model.provider),
            input_path=inputPath,
        )

        print("\nTask for verification of register pages created")

        contents = await self.reg_page_verifier.run(user_requests)

        if not getattr(self.reg_page_verifier, "has_valid_output", True):
            raise RuntimeError("Invalid output from register page verification")

        self.reg_page_idx = parse_verification_contents(
            contents=contents,
            user_requests=user_requests,
            pages=page_candidates,
        )

        print("Verification of register pages completed")
        self.time_consumption.register_page_verification = self.reg_page_verifier.elapsed_time
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
            task_name="register_index_extraction",
            task_config=task_config,
            api_key=self.config.get_apikey(task_config.model.provider),
        )

        print("\nStart register index information extraction")

        result = await self.reg_index_extractor.run(user_input)

        if not getattr(self.reg_index_extractor, "has_valid_output", True):
            raise RuntimeError("Invalid output from register index information extraction")

        self.reg_summary = result
        print("Register index information extraction completed")
        self.time_consumption.register_summary_extraction = self.reg_index_extractor.elapsed_time
        return result

    async def extract_reg_map(self) -> RegisterMapOutput:
        if not self.reg_page_idx:
            print("No register page for register map extraction\n")
            self.reg_map= RegisterMapOutput(registers=[])
            return RegisterMapOutput(registers=[])

        task_config = self.config.task_configs.extract_reg_map

        selected_pages = _select_extraction_pages(
            pages=self.pages,
            page_index=self.reg_page_idx,
        )

        raw_input = {
                "pages": selected_pages,
                "registers": self.reg_summary.model_dump()["registers"],
            }

        user_input = json.dumps(
            raw_input,
            ensure_ascii=False,
        )

        # path = "D:/python/master_arbeit/data/output/input_data/input.json"
        # with open(path,"w",encoding="utf-8") as f:
        #     json.dump(raw_input,f)

        self.reg_map_extractor = LLMTaskRunner.load_from_task_config(
            task_name="register_map_extraction",
            task_config=task_config,
            api_key=self.config.get_apikey(task_config.model.provider),
        )

        print("\nStart register map extraction")

        result = await self.reg_map_extractor.run(user_input)

        if not getattr(self.reg_map_extractor, "has_valid_output", True):
            raise RuntimeError("Invalid output from register map extraction")

        self.reg_map = result
        print("Register map extraction completed")
        self.time_consumption.register_map_extraction = self.reg_map_extractor.elapsed_time
        return result

    async def identify_function(self) -> DeviceFunctionOutput:
        task_config = self.config.task_configs.identify_function

        function_identifier = LLMTaskRunner.load_from_task_config(
            task_name="device_function_identification",
            task_config=task_config,
            api_key=self.config.get_apikey(
                task_config.model.provider
            ),
        )

        function_identifier_input = (
            self._build_function_identifier_input()
        )

        if not function_identifier_input.pages:
            print("\nNo pages for function information extraction\n")
            device_functions = DeviceFunctionOutput(device_functions=[])
            self.device_functions = device_functions
            return device_functions

        user_input = function_identifier_input.model_dump_json()
        print("\nStart device function identification and extraction")
        device_functions = await function_identifier.run(user_input)

        self.function_identifier=function_identifier
        self.device_functions = device_functions
        self.time_consumption.device_function_identification = self.function_identifier.elapsed_time
        print("\nDevice function extraction completed")

        return device_functions

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
        print("\nRefinement of page indices completed")

        return True

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

        snapshot = self._build_preprocessor_snapshot()
        token_consumption = self._build_token_consumption_snapshot()
        task_models = self._build_task_models()

        return PreprocessorOutput(
            pages=self.pages,
            register_map=self.reg_map,
            snapshot=snapshot,
            task_models=task_models,
            token_consumption=token_consumption,
            time_consumption=self.time_consumption,
            device_functions=self.device_functions,
        )

    def _get_pages(self) -> list[dict[str,Any]]:
        raw_pages = self.ocr_result.get("pages")
        if not isinstance(raw_pages,list) or not raw_pages:
            raise ValueError("OCR returned no normalized pages.")

        pages = [
            {
                "index":page["index"],
                "markdown":page["markdown"],
                "tables":page["tables"],
            } for page in raw_pages]

        return remove_header_footer(pages)

    def _load_ocr_if_exists(self) -> dict[str,Any] | None:
        if not self.ocr_path.is_file():
            print(
                f"\n OCR result for {self.pdf_path} does not exist\n"
                f"Ready to run OCR"
            )
            return None

        try:
            with self.ocr_path.open("r", encoding="utf-8") as file:
                ocr_result = json.load(file)
        except json.JSONDecodeError:
            print(
                f"\nInvalid OCR cache of {self.pdf_path.stem}\nReady to run new ocr"
            )
            return None

        if not isinstance(ocr_result, dict):
            print(
                "\nInvalid OCR cache\nReady to run new OCR."
            )
            return None

        pages = ocr_result.get("pages")
        if not isinstance(pages, list) or not pages:
            print(
                f"\nOCR result for {self.pdf_path.stem} contains no valid pages.\n"
                "Ready to run new OCR."
            )
            return None
        print(
            f"\nOCR result of pdf {self.pdf_path.stem} exists\n"
            f"Skipping OCR"
        )
        return ocr_result

    def _build_function_identifier_input(self) -> FunctionIdentifierInput:
        return FunctionIdentifierInput(
            register_map=self.reg_map,
            pages=self.original_pages,
        )

    def _build_preprocessor_snapshot(self) -> PreprocessorSnapshot:
        return PreprocessorSnapshot(
            pdf_path = self.pdf_path,
            toc_page_idx = self.toc_page_idx,
            toc_entries = self.toc_entries,
            reg_page_idx_from_toc = self.reg_page_idx_from_toc,
            reg_page_idx_from_retrieval = self.reg_page_idx_from_retrieval,
            reg_page_idx_from_llm = self.reg_page_idx_from_llm,
            reg_page_candidate_idx = self.reg_page_candidate_idx,
            reg_page_idx = self.reg_page_idx,
            reg_sum_idx_from_toc = self.reg_sum_idx_from_toc,
            reg_sum_idx_from_retrieval = self.reg_sum_idx_from_retrieval,
            reg_sum_idx_from_llm = self.reg_sum_idx_from_llm,
            reg_sum_candidate_idx = self.reg_sum_candidate_idx,
            reg_sum_page_idx = self.reg_sum_page_idx,
            reg_summary = self.reg_summary,
            reg_map = self.reg_map,
            device_functions=self.device_functions,
        )

    def _build_token_consumption_snapshot(self) -> PreprocessingTokenConsumption:
        token_consumption= PreprocessingTokenConsumption(
            classification =_get_usage_from_task_runner(self.classifier),
            reg_sum_verification =_get_usage_from_task_runner(self.reg_sum_verifier),
            reg_page_verification =_get_usage_from_task_runner(self.reg_page_verifier),
            reg_index_extraction =_get_usage_from_task_runner(self.reg_index_extractor),
            reg_map_extraction =_get_usage_from_task_runner(self.reg_map_extractor),
            function_identification=_get_usage_from_task_runner(self.function_identifier),
        )
        return token_consumption

    def _build_task_models(self) -> TaskModelsByName:
        task_configs = self.config.task_configs

        task_models_by_name = {
            "ocr": self.config.ocr.model_name
        }

        for task_name in type(task_configs).model_fields:
            task_config = getattr(task_configs, task_name)
            model_name = task_config.model.model_name
            task_models_by_name[task_name] = model_name

        return TaskModelsByName.model_validate(task_models_by_name)

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
