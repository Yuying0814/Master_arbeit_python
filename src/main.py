
import asyncio
from pathlib import Path
from typing import Any


from src.chat.config import ChatConfig
from src.chat.main import start_chat
from src.preprocessing.config import PreprocessingConfig
from src.coding.config import CodingConfig
from src.workflow import run_preprocessor,run_coding_controller,get_latest_data

PROJECT_ROOT = Path(__file__).resolve().parents[1]

# ============================================================
# MODE
# ============================================================
MODE = "chat" # chat/ single_file / multiple_files

# ============================================================
# General configuration for single_file/multiple_files
# ============================================================
DEVICE_NAME = ""
DEVICE_NAMES = [""]
USER_REQUEST = ""

# ============================================================
# Path configuration
# ============================================================
PDF_FILE: Path | str = PROJECT_ROOT / "data"/ "input_pdf" / "ITG-3050-Register-Map.pdf"
PDF_DIR: Path | str = PROJECT_ROOT / "data"/ "input_pdf"
ENV_FILE: Path | str = "D:/python/master_arbeit/.env"
DATABASE_PATH: Path | str = "D:/python/master_arbeit/data/database.db"
CODE_DIR: Path | str = "D:/python/master_arbeit/temp"
CLI_PATH = PROJECT_ROOT/"arduino"/"bin"/"arduino-cli.exe"

# ============================================================
# Model configuration
# ============================================================
PREPROCESSOR_TASK_MODEL_SETTINGS: dict[str, dict[str, Any]] = {
    "ocr":{
        "provider": "mistral",
        "model_name": "mistral-ocr-latest",
        "include_image": False,
        "table_format": "html",
        # Following settings are applied only for local glm-ocr
        "url": "http://localhost:11434",
        "layout_device": "cpu",
        "connection_pool_size": 1,
        "max_workers": 1,
        "batch_size": 1,
    },

    "classify_pages": {
        "provider": "openai",
        "is_batch": True,
        "model_name": "gpt-5-mini",
        "thinking_effort": "medium",
        "temperature": 0.0,
        "max_tokens": 10000,
    },
    "verify_reg_sum_pages": {
        "provider": "openai",
        "is_batch": True,
        "model_name": "gpt-5-mini",
        "thinking_effort": "medium",
        "temperature": 0.0,
        "max_tokens": 10000,
    },
    "verify_reg_pages": {
        "provider": "openai",
        "is_batch": True,
        "model_name": "gpt-5-mini",
        "thinking_effort": "medium",
        "temperature": 0.0,
        "max_tokens": 10000,
    },
    "extract_reg_index": {
        "provider": "openai",
        "model_name": "gpt-5-mini",
        "thinking_effort": "medium",
        "temperature": 0.0,
        "max_tokens": 20000,
    },
    "extract_reg_map": {
        "provider": "openai",
        "model_name": "gpt-5-mini",
        "thinking_effort": "high",
        "temperature": 0.0,
        "max_tokens": 100000,
    },
}
CODING_TASK_MODEL_SETTINGS: dict[str, dict[str, Any]] = {
    "planning": {
        "provider": "openai",
        "model_name": "gpt-5-mini",
        "thinking_effort": "high",
        "temperature": 0.0,
        "max_tokens": 100000,
    },
    "retrieval": {
        "provider": "openai",
        "model_name": "gpt-5-mini",
        "thinking_effort": "high",
        "temperature": 0.0,
        "max_tokens": 5000,
    },
    "coding": {
        "provider": "openai",
        "model_name": "gpt-5-mini",
        "thinking_effort": "high",
        "temperature": 0.0,
        "max_tokens": 20000,
    },
    "verification_semantic": {
        "provider": "openai",
        "model_name": "gpt-5-mini",
        "thinking_effort": "high",
        "temperature": 0.0,
        "max_tokens": 10000,
    },
    "verification_test_coder": {
        "provider": "openai",
        "model_name": "gpt-5-mini",
        "thinking_effort": "high",
        "temperature": 0.0,
        "max_tokens": 10000,
    },
}
# ============================================================
# chat model configuration
# ============================================================
CHAT_TASK_SETTINGS: dict[str, dict[str, Any]] = {
    "ocr": {
        "provider": "mistral",
        "model_name": "mistral-ocr-latest",
        "include_image": False,
        "table_format": "html",
        # Following settings are applied only for local glm-ocr
        "url": "http://localhost:11434",
        "layout_device": "cpu",
        "connection_pool_size": 1,
        "max_workers": 1,
        "batch_size": 1,
    },
    "chat": {
        "provider": "ollama",
        "is_batch": False,
        "model_name": "qwen3:8b",
        "thinking_effort": None,
        "temperature": 0.0,
        "max_tokens": 2000,
    },
    "identify_name": {
        "provider": "ollama",
        "is_batch": False,
        "model_name": "qwen3:8b",
        "thinking_effort": None,
        "temperature": 0.0,
        "max_tokens": 2000,
    },
}
# ============================================================
# END OF CONFIGURATION
# ============================================================


def configure_models(
        preprocessing_config: PreprocessingConfig,
        coding_config: CodingConfig,
        chat_config: ChatConfig,
) -> None:
    """Configure model settings for the current runs."""

    for task_name, settings in PREPROCESSOR_TASK_MODEL_SETTINGS.items():
        if task_name == "ocr":
            ocr_config = getattr(preprocessing_config,"ocr")
            for field_name,value in settings.items():
                setattr(ocr_config, field_name, value)
            continue

        task_config = getattr(preprocessing_config.task_configs, task_name)

        for field_name, value in settings.items():
            setattr(task_config.model, field_name, value)

    for task_name, settings in CODING_TASK_MODEL_SETTINGS.items():
        task_config = getattr(coding_config.task_configs, task_name)

        for field_name, value in settings.items():
            setattr(task_config.model, field_name, value)

    for task_name, settings in CHAT_TASK_SETTINGS.items():
        if task_name == "ocr":
            ocr_config = getattr(chat_config,"ocr")
            for field_name,value in settings.items():
                setattr(ocr_config, field_name, value)
            continue
        task_config = getattr(chat_config.task_configs, task_name)

        for field_name, value in settings.items():
            setattr(task_config.model, field_name, value)

def main():
    preprocessing_config = PreprocessingConfig.load_config(
        pdf=PDF_FILE,
        env=ENV_FILE,
    )
    coding_config = CodingConfig.load_config(
        code_dir=CODE_DIR,
        cli_path=CLI_PATH,
        env=ENV_FILE,
    )
    chat_config = ChatConfig.load_config(
        env=ENV_FILE,
        database=DATABASE_PATH,
    )

    configure_models(
        preprocessing_config=preprocessing_config,
        coding_config=coding_config,
        chat_config=chat_config,
    )

    device_name = DEVICE_NAME.strip()
    match MODE.casefold():
        case "chat":
            start_chat(
                chat_config=chat_config,
                preprocessing_config=preprocessing_config,
                coding_config=coding_config,
            )

        case "single_file":

            if not device_name:
                raise ValueError("DEVICE_NAME must not be empty.")

            result = asyncio.run(
                    run_preprocessor(
                        config=preprocessing_config,
                        pdf_path=Path(PDF_FILE),
                        database_path=DATABASE_PATH,
                        device_name=device_name,
                    )
            )

            data = get_latest_data(
                database_path=Path(DATABASE_PATH),
                device_name=result["device_name"],
            )

            asyncio.run(
                run_coding_controller(
                    config=coding_config,
                    driver_name=result["device_name"],
                    version_major=result["version_major"],
                    pages=data["pages"],
                    register_map=data["register_map"],
                    user_request=USER_REQUEST if USER_REQUEST else None,
                )
            )

        case "multiple_files":
            folder = Path(PDF_DIR)
            if not folder.is_dir():
                raise NotADirectoryError(f"Folder does not exist:{folder}")

            pdf_files = sorted(folder.glob("*.pdf"))
            device_names = [name.strip() for name in DEVICE_NAMES]

            if not pdf_files:
                raise FileNotFoundError(f"No PDF files found in:{folder}")
            if len(pdf_files) != len(device_names):
                raise ValueError(
                    "PDF file count must match DEVICE_NAMES count."
                )

            if any(not name for name in device_names):
                raise ValueError("DEVICE_NAMES must not contain empty names.")

            for pdf_path, current_device_name in zip(
                    pdf_files,
                    device_names,
                    strict=True,
            ):
                asyncio.run(
                    run_preprocessor(
                        config=preprocessing_config,
                        pdf_path=pdf_path,
                        database_path=DATABASE_PATH,
                        device_name=current_device_name,
                    )
                )

            unique_device_names = list(dict.fromkeys(device_names))
            for name in unique_device_names:
                data = get_latest_data(
                    database_path=Path(DATABASE_PATH),
                    device_name=name
                )

                asyncio.run(
                    run_coding_controller(
                        config=coding_config,
                        driver_name=name,
                        version_major=data["version_major"],
                        pages=data["pages"],
                        register_map=data["register_map"],
                        user_request=USER_REQUEST if USER_REQUEST else None,
                    )
                )

        case _:
            raise ValueError(f"Unsupported MODE: {MODE}")


if __name__ == "__main__":
    main()
