from typing import Any


from pathlib import Path

from src.models.preprocessing.register_output import RegisterMapOutput,RegisterIndexOutput
from src.models.llm.common import NormalizedTokenConsumption
from src.models.structuredOutputModel import StructuredOutputModel


class PreprocessorSnapshot(StructuredOutputModel):
    pdf_path:Path
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

class TaskModelsByName(StructuredOutputModel):
    ocr:str
    classify_pages: str
    verify_reg_sum_pages: str
    verify_reg_pages: str
    add_page_description: str
    extract_reg_index: str
    extract_reg_map: str

class PreprocessingTokenConsumption(StructuredOutputModel):
    classification: NormalizedTokenConsumption
    reg_sum_verification: NormalizedTokenConsumption
    reg_page_verification : NormalizedTokenConsumption
    reg_index_extraction : NormalizedTokenConsumption
    reg_map_extraction : NormalizedTokenConsumption

class PreprocessorOutput(StructuredOutputModel):
    pages: list[dict[str, Any]]
    register_map: RegisterMapOutput
    snapshot:PreprocessorSnapshot
    task_models: TaskModelsByName
    token_consumption: PreprocessingTokenConsumption
