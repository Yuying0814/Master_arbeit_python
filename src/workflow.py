import hashlib
import json

from pathlib import Path
from typing import Any
from datetime import datetime, timezone

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
) -> dict[str, Any]:
    pdf_path = Path(pdf_path).expanduser().resolve()
    device_name = device_name.strip()

    if not device_name:
        raise ValueError("device_name must not be empty.")

    preprocessor = Preprocessor(
        config,
    )

    preprocessing_result = await preprocessor.run(pdf_path)
    completed_at = datetime.now(timezone.utc).isoformat()
    with DataManager(database_path) as manager:
        existing_names = manager.list_devices()
        for existing_name in existing_names:
            if existing_name.casefold().strip() == device_name.casefold().strip():
                device_name = existing_name
                break

        result = manager.save_preprocessing_result(
            device_name=device_name,
            input_pdf_sha256=_calculate_sha256(pdf_path),
            pages=preprocessing_result["pages"],
            register_map=preprocessing_result["register_map"],
            snapshot=preprocessing_result["snapshot"],
            pages_created_at=completed_at,
            register_map_created_at=completed_at,
            snapshot_created_at=completed_at,
            token_consumption=preprocessing_result["token_consumption"],
            task_models=preprocessing_result["task_models"],
        )

        version = manager.get_latest_version(device_name)

        save_preprocessing_outputs(
            device_name=device_name,
            version=f"v{version[0]}_{version[1]}",
            output_dir=config.project_path.output_path,
            result=preprocessing_result,
        )

    return result

def get_latest_major_result(
        database_path: Path,
        device_name:str,
) -> dict[str,Any]:
    with DataManager(database_path) as manager:
        latest_version = manager.get_latest_version(device_name)
        result = manager.get_major_version_result(
            device_name=device_name,
            version_major=latest_version[0],
        )

        return result



async def run_coding_controller(
        config:CodingConfig,
        driver_name:str,
        version_major:int,
        documents:list[dict[str,Any]],
        register_maps:list[dict[str,Any]],
        user_request:str | None = None,
) -> bool:
    controller = Controller.load_controller(
        driver_name=driver_name,
        config=config,
        documents=documents,
        register_maps=register_maps,
    )

    return await controller.run(user_request=user_request,version_major=version_major)

def save_preprocessing_outputs(
        device_name:str,
        version: str,
        output_dir:Path,
        result:dict[str,Any],
) -> bool:

    _write_json(
        output_dir /device_name/version/"preprocessor_snapshot.json",
        result["snapshot"],
    )

    _write_json(
        output_dir /device_name/version/"register_map.json",
        result["register_map"],
    )

    _write_json(
        output_dir /device_name/version/"pages.json",
        result["pages"],
    )

    _write_json(
        output_dir /device_name/version/"token_consumption.json",
        result["token_consumption"],
    )

    _write_json(
        output_dir /device_name/version/"task_models.json",
        result["task_models"],
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
