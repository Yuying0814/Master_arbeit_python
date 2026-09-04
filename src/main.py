
import asyncio
from pathlib import Path
from typing import Any


from src.chat.config import ChatConfig
from src.chat.main import start_chat
from src.preprocessing.config import PreprocessingConfig
from src.coding.config import CodingConfig
from src.workflow import run_preprocessor,run_coding_controller,get_major_version_result,run_preprocessing_and_coding

PROJECT_ROOT = Path(__file__).resolve().parents[1]

# ============================================================
# MODE SELECTION
# ============================================================
MODE = "preprocessing" # chat/ preprocessing /coding/ preprocessing and coding

# ============================================================
# GENERAL CONFIG.
# ============================================================
DEVICE_NAME = "ATMEGA8" # For preprocessing and coding

# preprocessing input
PDF_FILE: Path | str = Path(r"D:\python\master_arbeit\data\input_pdf\ATmega8.pdf")

# coding input
MAJOR_VERSION = 2
USER_REQUEST = ""

# local config
# BASE_URL = "http://129.187.200.113:11434"
BASE_URL = "100.118.198.6:11434"

# llm local batch config
MAX_CONCURRENCY = 4

# ocr local config
LAYOUT_DEVICE = "cpu"
CONNECTION_POOL_SIZE = 1
MAX_WORKERS = 1
BATCH_SIZE = 1

# ============================================================
# PATH CONFIG
# ============================================================
ENV_FILE: Path | str = "D:/python/master_arbeit/.env"
DATABASE_PATH: Path | str = "D:/python/master_arbeit/data/database_v2.db"
CODE_DIR: Path | str = "D:/python/master_arbeit/code"

# ============================================================
# Arduino-CLI CONFIG
# ============================================================
ENABLE_TEST_CODER = False
PORT = "COM6"
CLI_PATH = PROJECT_ROOT/"arduino"/"bin"/"arduino-cli.exe"
PACKAGE = "rp2040"
ARCHITECTURE = "rp2040"
BOARD = "generic"
BOARD_OPTIONS = {
    "flash": "4194304_0",
    "boot2": "boot2_w25q128jvxq_4_padded_checksum",
    "usbstack":"picosdk",
}

# ============================================================
# TASK MODEL CONFIG
# ============================================================
PREPROCESSOR_TASK_MODEL_SETTINGS: dict[str, dict[str, Any]] = {
    "ocr":{
        "provider": "mistral",
        "model_name": "mistral-ocr-latest",
        "include_image": False,
        "table_format": "html",
        # Following settings are applied only for local glm-ocr
        "url": BASE_URL,
        "layout_device": LAYOUT_DEVICE,
        "connection_pool_size": CONNECTION_POOL_SIZE,
        "max_workers": MAX_WORKERS,
        "batch_size": BATCH_SIZE,
    },

    "classify_pages": {
        "provider": "openai",
        "is_batch": True,
        "model_name": "gpt-5-mini",
        "thinking_effort": "medium",
        "temperature": None,
        "max_tokens": 10000,
        "timeout": 36000,
        "base_url":BASE_URL,
        "ollama_batch_concurrency": MAX_CONCURRENCY,
    },
    "verify_reg_sum_pages": {
        "provider": "openai",
        "is_batch": True,
        "model_name": "gpt-5-mini",
        "thinking_effort": "medium",
        "temperature": None,
        "max_tokens": 10000,
        "timeout": 36000,
        "base_url":BASE_URL,
        "ollama_batch_concurrency": MAX_CONCURRENCY,
    },
    "verify_reg_pages": {
        "provider": "openai",
        "is_batch": True,
        "model_name": "gpt-5-mini",
        "thinking_effort": "medium",
        "temperature": None,
        "max_tokens": 10000,
        "timeout": 36000,
        "base_url":BASE_URL,
        "ollama_batch_concurrency": MAX_CONCURRENCY,
    },
    "extract_reg_index": {
        "provider": "openai",
        "model_name": "gpt-5-mini",
        "thinking_effort": "medium",
        "temperature": None,
        "max_tokens": 80000,
        "timeout": 36000,
        "base_url":BASE_URL,
    },
    "extract_reg_map": {
        "provider": "openai",
        "model_name": "gpt-5-mini",
        "thinking_effort": "medium",
        "temperature": None,
        "max_tokens": 100000,
        "timeout": 36000,
        "base_url":BASE_URL,
    },
    "identify_function": {
        "provider": "openai",
        "model_name": "gpt-5-mini",
        "thinking_effort": "medium",
        "temperature": None,
        "max_tokens": 80000,
        "timeout": 36000,
        "base_url": BASE_URL,
    },
}
CODING_TASK_MODEL_SETTINGS: dict[str, dict[str, Any]] = {
    "planning": {
        "provider": "openai",
        "model_name": "gpt-5-mini",
        "thinking_effort": "medium",
        "temperature": None,
        "max_tokens": 60000,
        "timeout": 7200,
        "base_url":BASE_URL,
    },
    "retrieval": {
        "provider": "openai",
        "is_batch": True,
        "model_name": "gpt-5-mini",
        "thinking_effort": "medium",
        "temperature": None,
        "max_tokens": 10000,
        "timeout": 7200,
        "base_url":BASE_URL,
        "ollama_batch_concurrency": MAX_CONCURRENCY,
    },
    "coding": {
        "provider": "openai",
        "model_name": "gpt-5-mini",
        "thinking_effort": "medium",
        "temperature": None,
        "max_tokens": 100000,
        "timeout": 7200,
        "base_url":BASE_URL,

    },
    "verification_semantic": {
        "provider": "openai",
        "model_name": "gpt-5-mini",
        "thinking_effort": "medium",
        "temperature": None,
        "max_tokens": 60000,
        "timeout": 7200,
        "base_url":BASE_URL,
    },
    "verification_test_coder": {
        "provider": "openai",
        "model_name": "gpt-5-mini",
        "thinking_effort": "medium",
        "temperature": None,
        "max_tokens": 30000,
        "timeout": 7200,
        "base_url":BASE_URL,
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
        "temperature": None,
        "max_tokens": 50000,
        "base_url":BASE_URL,
    },
    "identify_name": {
        "provider": "ollama",
        "is_batch": False,
        "model_name": "qwen3:8b",
        "thinking_effort": None,
        "temperature": None,
        "max_tokens": 2000,
        "base_url":BASE_URL,
    },
}
# ============================================================
# END OF CONFIGURATION
# ============================================================

def main():
    preprocessing_config = PreprocessingConfig.load_config(
        env=ENV_FILE,
    )
    coding_config = CodingConfig.load_config(
        code_dir=CODE_DIR,
        cli_path=CLI_PATH,
        env=ENV_FILE,
        package=PACKAGE,
        architecture=ARCHITECTURE,
        board=BOARD,
        enable_test_coder=ENABLE_TEST_CODER,
        board_options=BOARD_OPTIONS,
        port=PORT,
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
    version_major = MAJOR_VERSION

    match MODE.casefold():
        case "chat":
            start_chat(
                chat_config=chat_config,
                preprocessing_config=preprocessing_config,
                coding_config=coding_config,
            )

        case "preprocessing":
            asyncio.run(
                run_preprocessor(
                    config=preprocessing_config,
                    pdf_path=Path(PDF_FILE),
                    database_path=DATABASE_PATH,
                    device_name=device_name,
                )
            )

        case "coding":
            result = get_major_version_result(
                database_path=DATABASE_PATH,
                device_name=device_name,
                version_major=version_major,
            )

            asyncio.run(
                run_coding_controller(
                    config=coding_config,
                    driver_name=device_name,
                    version_major=version_major,
                    documents=result.documents,
                    register_maps=result.register_maps,
                    device_functions=result.device_functions,
                    user_request=USER_REQUEST,
                )
            )

        case "preprocessing and coding":
            asyncio.run(
                run_preprocessing_and_coding(
                    preprocessing_config=preprocessing_config,
                    coding_config=coding_config,
                    device_name=device_name,
                    pdf_path=Path(PDF_FILE),
                    database_path=DATABASE_PATH,
                    user_request=USER_REQUEST,
                )
            )

        case _:
            raise ValueError(f"Unsupported MODE: {MODE}")


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

if __name__ == "__main__":
    main()
