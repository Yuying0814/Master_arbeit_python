
from typing import Any


from pathlib import Path

from openai.openai_task import OpenAITask
from src.openai.batch_task import OpenAIBatchTask
from src.models.retriever import RetrievalRequest,RetrievalResponse
from src.models.task_config import CodingTaskConfigs
from src.llm.normal_llm_processor import LLMTask

class Retriever:
    classifier:

    log:list

    def __init__(self,api_key: str,*, provider:str, model:str = None, instructions:str = None, max_output_tokens:int = None):
        self.provider = provider
        self.instructions = instructions if instructions is not None else ""
        self.max_output_tokens = max_output_tokens if max_output_tokens is not None else 500

    def run(self,retrieval_request: RetrievalRequest):
        pass



    @classmethod
    def load_from_task_config(cls,api_key:str,task_config:CodingTaskConfigs) -> "Retriever":

        return cls(
            api_key = api_key,
        )


    prompt_path = Path(prompt_path)
    return Path(prompt_path).read_text(encoding="utf-8")