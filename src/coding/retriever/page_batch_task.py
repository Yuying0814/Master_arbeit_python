from typing import Any
from pathlib import Path
from src.openai.batch_task import OpenAIBatchTask
from src.openai.valid_format import ValidTextFormat

class PageBatchTask(OpenAIBatchTask):
    pages:list[dict[str,Any]]

    def __init__(self,api_key:str,input_path:Path,pages:list[dict[str,Any]],
                 *, model: str | None = None,
                 instructions: str | None = None,
                 max_output_tokens: int | None = None,
                 ) -> None:

        super().__init__(
            api_key = api_key,
            input_path = input_path,
            model = model,
            instructions = instructions,
            text_format = "text",
            max_output_tokens= max_output_tokens,
        )

        self.pages = pages

    @classmethod
    def load_from_task_config(cls,api_key:str,input_path:Path,pages:list[dict[str,Any]],task_config):
        config = _rebuild_config(task_config)
        return cls(
            api_key=api_key,
            input_path=input_path,
            pages=pages,
            **config,
        )

def _rebuild_config(task_config: dict[str, Any]):
    pass

def _load_instructions(prompt_path:str|Path|None) -> str:
    if not prompt_path:
        return "You are a helpful assistant."

    prompt_path = Path(prompt_path)
    return Path(prompt_path).read_text(encoding="utf-8")
