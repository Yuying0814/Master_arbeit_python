import sys
import asyncio
from pathlib import Path
from typing import Any,Literal

PROJECT_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(PROJECT_ROOT))

from src.preprocessing.config import PreprocessingConfig
from src.preprocessing.preprocessor import Preprocessor


MODE:Literal["single_test","multiple_test"] = "single_test"
PDF_DIR:Path|str = ...  # Enter pdf dir here for multiple_test
PDF_FILE:Path|str = ...  # Enter pdf path here for single_test
ENV_FILE:Path|str = ""  # Enter .env path here

def configure_preprocessing_models(config: PreprocessingConfig) -> None:
    """Configure model settings for the current preprocessing run."""
    """Available settings for each task:
        provider: str, "openai", "ollama"
        is_batch: bool, True, False (better not change)
        model_name: str, "gpt-5-mini", "gpt-5.4", ...
        temperature: int
        max_tokens: int
    """
    model_settings: dict[str, dict[str, Any]] = {
        "classify_pages": {
            "provider": "openai",
            "is_batch": True,
            "model_name": "gpt-5-mini",
            "temperature": 0.0,
            "max_tokens": 2000,
        },
        "verify_reg_sum_pages": {
            "provider": "openai",
            "is_batch": True,
            "model_name": "gpt-5-mini",
            "temperature": 0.0,
            "max_tokens": 1000,
        },
        "verify_reg_pages": {
            "provider": "openai",
            "is_batch": True,
            "model_name": "gpt-5-mini",
            "temperature": 0.0,
            "max_tokens": 1000,
        },
        # "add_page_description": {
        #     "provider": "openai",
        #     "is_batch": True,
        #     "model_name": "gpt-5-mini",
        #     "temperature": 0.0,
        #     "max_tokens": 2000,
        # },
        "extract_reg_index": {
            "provider": "openai",
            "is_batch": False,
            "model_name": "gpt-5-mini",
            "temperature": 0.0,
            "max_tokens": 8000,
        },
        "extract_reg_map": {
            "provider": "openai",
            "is_batch": False,
            "model_name": "gpt-5-mini",
            "temperature": 0.0,
            "max_tokens": 30000,
        },
    }

    for task_name, settings in model_settings.items():
        task_config = getattr(config.llm_task_config, task_name)

        for field_name, value in settings.items():
            setattr(task_config.model, field_name, value)

async def run_preprocessor(pdf_file:Path|str) -> None:
    """Run the preprocessing pipeline for one PDF."""

    pdf_file = Path(pdf_file)
    env_file = Path(ENV_FILE)

    config = PreprocessingConfig.load_config(pdf=pdf_file,env=env_file)
    configure_preprocessing_models(config)

    preprocessor = Preprocessor(config)
    await preprocessor.run()


if __name__ == "__main__":
    match MODE:
        case "single_test":
            print(f"\n==============================")
            print(f"Running tests for: {PDF_FILE.stem}")
            print(f"==============================\n")

            # test_without_preprocessing(pdf_name)
            asyncio.run(run_preprocessor(PDF_FILE))

        case "multiple_test":
            pdf_files = sorted(Path(PDF_DIR).glob("*.pdf"))

            for pdf_file in pdf_files:
                print(f"\n==============================")
                print(f"Running tests for: {pdf_file.stem}")
                print(f"==============================\n")

                # test_without_preprocessing(pdf_name)
                asyncio.run(run_preprocessor(pdf_file))


