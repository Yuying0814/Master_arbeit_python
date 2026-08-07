import os
import sys
import asyncio

from pydantic import Field
from pathlib import Path



PROJECT_ROOT = Path(__file__).resolve().parents[1]
PROMPT_PATH = PROJECT_ROOT/"prompts"
sys.path.insert(0, str(PROJECT_ROOT))

from dotenv import load_dotenv
from typing import Any

from src.llm.ocr_task import OcrTask
from src.models.structuredOutputModel import StructuredOutputModel

from src.coding.retriever.retriever import PageRetriever
from src.models.retriever import BinaryClassifierOutput, RetrievalTopic
from src.models.task_config import TaskConfig, ModelConfig, OcrConfig

class Test(StructuredOutputModel):
    random_number: int = Field(
        description="Random number generated from 0 to 10",
    )
    content: str = Field(
        description="Content of the message, randomly say something in max.1000 tokens",
    )

def _read_instructions(prompt_path:str|Path|None) -> str:
    if not prompt_path:
        return "You are a helpful assistant."

    prompt_path = Path(prompt_path)
    return Path(prompt_path).read_text(encoding="utf-8")

def run_ocr(api_key:str, pdf_path:Path) -> list[dict[str,Any]]:
    ocr_result = OcrTask(
        OcrConfig(
            provider="mistral",
            model_name="mistral-ocr-latest",
        ),
        api_key,
    ).run(pdf_path)
    return ocr_result["pages"]

async def run():
    pdf_path = PROJECT_ROOT / "data" / "input_pdf" / "lis3dh.pdf"
    input_path = PROJECT_ROOT / "data" / "input" / "retriever_draft.jsonl"
    sys.path.insert(0, str(PROJECT_ROOT))
    load_dotenv(dotenv_path=PROJECT_ROOT/".env")
    openai_api_key = os.getenv("OPENAI_API_KEY", "").strip()
    mistral_api_key = os.getenv("MISTRALAI_API_KEY", "").strip()

    pages = run_ocr(mistral_api_key,pdf_path)
    start_index = 23
    end_index = 35

    selected_pages = pages[start_index:end_index + 1]

    task_config = TaskConfig(
        model = ModelConfig(
            provider = "openai",
            is_batch=True,
            model_name="gpt-5-mini",
            temperature=0.0,
            max_tokens=2000,
        ),
        system = _read_instructions(PROMPT_PATH/"prompt_retriever.txt"),
        output_format = BinaryClassifierOutput,
    )

    retriever = PageRetriever.load_from_task_config(
        pages = selected_pages,
        task_config = task_config,
        api_key = openai_api_key,
        input_path = input_path,
    )

    topics = [RetrievalTopic(
        topic_keywords=[
            "register map",
            "register address",
            "register table",
            "memory map",
            "address map",
        ],
        topic_description=(
            "Pages that list the detailed registers, including register names, functions,"
            "addresses, access types, reset values, and bit-field layout."
        ),
    ),
    RetrievalTopic(
        topic_keywords=[
            "digital interface",
            "I2C",
            "SPI",
            "serial interface",
            "communication protocol",
            "read write operation",
        ],
        topic_description=(
            "Pages that describe the digital communication interface, including I2C or SPI "
            "protocol behavior, read/write sequences, device addressing, and bus timing."
        ),
    ),
    RetrievalTopic(
        topic_keywords=[
            "data conversion",
            "raw data",
            "output data",
            "temperature conversion",
            "measurement result",
            "physical value",
        ],
        topic_description=(
            "Pages that explain how raw register values are converted into physical values, "
            "including formulas, scaling factors, resolution, units, and example calculations."
        ),
    ),
]
    result = await retriever.run(topics)
    print(result)
    return result

def test():
    asyncio.run(run())
    pass

if __name__ == "__main__":
    test()
