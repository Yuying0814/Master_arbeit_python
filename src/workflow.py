import hashlib
import json
import warnings

from pathlib import Path
from typing import Any
from datetime import datetime, timezone

from src.models.data_manager import MajorVersionResult,VersionResult,DocumentRecord, RegisterMapRecord
from src.models.preprocessing.preprocessor import PreprocessorOutput

from src.data_manager.data_manager import DataManager
from src.preprocessing.preprocessor import Preprocessor
from src.preprocessing.config import PreprocessingConfig
from src.coding.controller.controller import Controller
from src.coding.config import CodingConfig

async def run_preprocessor(
        config: PreprocessingConfig,
        pdf_path: Path,
        database_path: str | Path,
        device_name: str,
) -> VersionResult:
    pdf_path = Path(pdf_path).expanduser().resolve()
    device_name = device_name.strip()

    if not device_name:
        raise ValueError("device_name must not be empty.")

    preprocessor = Preprocessor(
        config,
    )
    try:
        preprocessing_result = await preprocessor.run(pdf_path)
        completed_at = datetime.now(timezone.utc).isoformat()
        with DataManager(database_path) as manager:
            existing_names = manager.list_all_devices()
            for existing_name in existing_names:
                if existing_name.casefold().strip() == device_name.casefold().strip():
                    device_name = existing_name
                    break

            feedback = manager.save_preprocessing_result(
                device_name=device_name,
                pdf_name = pdf_path.stem,
                input_pdf_sha256=_calculate_sha256(pdf_path),
                pages=preprocessing_result.pages,
                register_map=preprocessing_result.register_map,
                snapshot=preprocessing_result.snapshot,
                pages_created_at=completed_at,
                register_map_created_at=completed_at,
                snapshot_created_at=completed_at,
                token_consumption=preprocessing_result.token_consumption,
                task_models=preprocessing_result.task_models,
            )

            version_info = feedback.details

            message = {
                "success": True,
                "status": "completed",
                "operation_feedback": feedback.model_dump(mode="json"),
            }

            print(
                f"\n PDF successfully processed\n"
                f"{json.dumps(message, indent=4)}"
            )

            save_preprocessing_outputs(
                device_name=device_name,
                version=f"v{version_info.version_major}_{version_info.version_minor}",
                output_dir=config.project_path.output_path,
                result=preprocessing_result,
            )

            version_result = manager.get_version_result(
                device_name = version_info.device_name,
                version_pk= version_info.version_pk,
            )

        return version_result

    except Exception as err:
        message = {
            "success": False,
            "status": "failed",
            "error": str(err),
        }
        print(message)
        raise RuntimeError("Preprocessing failed") from err

def get_major_version_result(
        database_path: Path|str,
        device_name: str,
        version_major:int,
) -> MajorVersionResult:

    database_path = Path(database_path).expanduser().resolve()
    with DataManager(database_path) as manager:
        result = manager.get_major_version_result(
            device_name=device_name,
            version_major=version_major,
        )

        return result

async def run_coding_controller(
        config:CodingConfig,
        driver_name:str,
        version_major:int,
        documents:list[DocumentRecord],
        register_maps:list[RegisterMapRecord],
        user_request:str = "",
) -> bool:
    controller = Controller.load_controller(
        driver_name=driver_name,
        config=config,
        documents=documents,
        register_maps=register_maps,
    )

    try:
        completed,code_dir = await controller.run(user_request=user_request, version_major=version_major)

        message = {
            "success": completed,
            "status": "completed",
            "details": f"Code written to {code_dir}",
        }

        print(
            f"\n Coding completed\n"
            f"{json.dumps(message, indent=4)}"
        )
        return completed
    except Exception as err:
        message = {
            "success": False,
            "status": "failed",
            "error": str(err),
        }
        print(message)
        raise RuntimeError("Coding failed") from err


async def run_preprocessing_and_coding(
        preprocessing_config: PreprocessingConfig,
        coding_config: CodingConfig,
        device_name:str,
        pdf_path: Path,
        database_path: str | Path,
        user_request: str = ""
):
    version_result = await run_preprocessor(
        config=preprocessing_config,
        pdf_path=pdf_path,
        database_path=database_path,
        device_name=device_name
    )

    data = get_major_version_result(
        database_path=database_path,
        device_name=version_result.device_name,
        version_major=version_result.version_major,
    )

    completed = await run_coding_controller(
        config=coding_config,
        driver_name=version_result.device_name,
        version_major=version_result.version_major,
        documents=data.documents,
        register_maps=data.register_maps,
        user_request=user_request,
    )

    return completed

def save_preprocessing_outputs(
        device_name:str,
        version: str,
        output_dir:Path,
        result:PreprocessorOutput,
) -> bool:

    _write_json(
        output_dir /device_name/version/"preprocessor_snapshot.json",
        result.snapshot.model_dump(),
    )

    _write_json(
        output_dir /device_name/version/"register_map.json",
        result.register_map.model_dump(),
    )

    _write_json(
        output_dir /device_name/version/"pages.json",
        result.pages,
    )

    _write_json(
        output_dir /device_name/version/"token_consumption.json",
        result.token_consumption.model_dump(),
    )

    _write_json(
        output_dir /device_name/version/"task_models.json",
        result.task_models.model_dump(),
    )

    _write_json(
        output_dir /device_name/version/"time_consumption.json",
        result.time_consumption.model_dump(),
    )


    return True


def _calculate_sha256(pdf_path: Path) -> str:
    digest = hashlib.sha256()
    with pdf_path.open("rb") as file:
        for chunk in iter(lambda: file.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()

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
