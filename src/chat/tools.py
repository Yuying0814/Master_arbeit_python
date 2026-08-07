from __future__ import annotations

import asyncio
import hashlib
import json
import uuid
from collections.abc import Callable
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

from src.chat.config import ChatConfig
from src.coding.config import CodingConfig
from src.coding.controller.controller import Controller
from src.data_manager.data_manager import DataManager
from src.llm.ocr_task import OcrTask
from src.llm.llm_single_task import LLMSingleTask
from src.preprocessing.config import PreprocessingConfig
from src.preprocessing.preprocessor import Preprocessor


class QuitChatRequested(BaseException):
    pass


def read_user_input(prompt: str) -> str:
    value = input(prompt)
    if "quit" in value.casefold():
        raise QuitChatRequested
    return value

class ChatTools:
    def __init__(
            self,
            chat_config: ChatConfig,
            preprocessing_config:PreprocessingConfig,
            coding_config:CodingConfig
    ) -> None:
        self.chat_config = chat_config
        self.database_path = chat_config.project_path.database_path
        self.preprocessing_config = preprocessing_config
        self.coding_config = coding_config
        self.preprocessing_sessions: dict[str, dict[str, Any]] = {}

    def inspect_preprocessing_pdf(
            self,
            pdf_path: str,
            expected_device_name: str | None = None,
    ) -> dict[str, Any]:
        """Inspect a PDF with OCR and identify its device name.

        Args:
            pdf_path: Required path to the PDF datasheet.
            expected_device_name: Optional user-provided name for consistency checking.
        """

        try:
            path = _validate_pdf_path(pdf_path)
            expected_device_name = _optional_text(expected_device_name)
            device_names = self.list_devices()

            api_key = (
                self.chat_config.get_apikey("mistral")
                if self.chat_config.ocr.provider == "mistral"
                else None
            )
            ocr_result = OcrTask(self.chat_config.ocr,api_key).run(path)

            if not ocr_result.get("pages"):
                raise ValueError("OCR returned no pages.")

            task = LLMSingleTask.load_from_task_config(
                self.chat_config.task_configs.identify_name
            )

            task.add_user_inputs(
                _device_identification_input(
                    device_names,
                    expected_device_name,
                    ocr_result["pages"],
                )
            )

            identification = asyncio.run(task.run())
            detected_device_name = str(identification["detected_device_name"]).strip()

            if not detected_device_name:
                raise ValueError("Device identification returned an empty name.")

            existing_device_name = _optional_text(
                identification["existing_device_name"]
            )
            existing_devices = {
                name.casefold():name for name in device_names
            }

            if existing_device_name is not None:
                existing_device_name = existing_devices.get(
                    existing_device_name.casefold()
                )

                if existing_device_name is None:
                    raise ValueError(
                        "Device identification returned an unknown existing device name."
                    )
            else:
                existing_device_name = existing_devices.get(
                    detected_device_name.casefold()
                )

            is_consistent = bool(identification["is_consistent"])
            if existing_device_name is None or expected_device_name is None:
                is_consistent = True

            requires_confirmation = (
                existing_device_name is not None and not is_consistent
            )

            selected_device_name = existing_device_name or detected_device_name

            session_id = uuid.uuid4().hex
            self.preprocessing_sessions[session_id] = {
                "detected_device_name": detected_device_name,
                "existing_device_name": existing_device_name,
                "expected_device_name": expected_device_name,
                "is_consistent": is_consistent,
                "pdf_path": path,
                "ocr_result": ocr_result,
            }

            return {
                "success": True,
                "status": "device_confirmation_required" if requires_confirmation else "ready",
                "requires_confirmation": requires_confirmation,
                "preprocessing_session_id": session_id,
                "device_name":None if requires_confirmation else selected_device_name,
                "detected_device_name":detected_device_name,
                "existing_device_name":existing_device_name,
                "expected_device_name":expected_device_name,
                "new_device_name":detected_device_name,
                "is_consistent": is_consistent,
            }
        except Exception as error:
            return {
                "success": False,
                "status": "failed",
                "error": str(error),
            }

    def run_preprocessor(self,preprocessing_session_id:str,device_name:str,) -> dict[str,Any]:
        """Run preprocessing with OCR data from an inspection session.

        Args:
            preprocessing_session_id: Required session ID returned by PDF inspection.
            device_name: Required detected or confirmed existing device name.
        """

        try:
            session = self.preprocessing_sessions.get(preprocessing_session_id)
            if session is None:
                raise LookupError("Preprocessing session not found.")

            device_name = device_name.strip()
            if not device_name:
                raise ValueError("Device name must not be empty.")

            pdf_sha256 = _calculate_sha256(session["pdf_path"])

            existing_devices = {
                name.casefold():name for name in self.list_devices()
            }

            existing_device_name = existing_devices.get(device_name.casefold())
            allowed_new_names = {session["detected_device_name"].casefold()}

            if existing_device_name is None and device_name.casefold() not in allowed_new_names:
                raise ValueError(
                    "Device name must be the detected name or an existing device name."
                )

            if existing_device_name is not None:
                matched_device_name = session["existing_device_name"]

                if matched_device_name is None or existing_device_name.casefold() != matched_device_name.casefold():
                    raise ValueError(
                        "Device name must be the identified existing device name."
                    )

                device_name = existing_device_name
                pdf_used = self._check_pdf_used(
                    device_name,
                    pdf_sha256,
                )

                if pdf_used:
                    approved = self._confirm(
                        "rerun preprocessor with a previously processed pdf",
                        {
                            "detected_device_name":session["detected_device_name"],
                            "selected_device_name":device_name,
                            "pdf_path":str(session["pdf_path"]),
                        },
                    )

                    if not approved:
                        self.preprocessing_sessions.pop(preprocessing_session_id, None)
                        return {"success":False,"status":"cancelled"}

            config = self.preprocessing_config

            preprocessor = Preprocessor(
                config,
                session["ocr_result"],
            )
            result = asyncio.run(preprocessor.run(session["pdf_path"]))

            completed_at = datetime.now(timezone.utc).isoformat()

            with DataManager(self.database_path) as manager:
                result = manager.save_preprocessing_result(
                    device_name=device_name,
                    input_pdf_sha256=pdf_sha256,
                    pages=result["pages"],
                    register_map=result["register_map"],
                    snapshot=result["snapshot"],
                    pages_created_at=completed_at,
                    register_map_created_at=completed_at,
                    snapshot_created_at=completed_at,
                    task_models=result["task_models"],
                    token_consumption=result["token_consumption"],
                )

            self.preprocessing_sessions.pop(preprocessing_session_id, None)
            return {
                "success":True,
                "status":"completed",
                "device_name":result["device_name"],
                "version_pk":result["version_pk"],
                "version_major":result["version_major"],
                "version_minor":result["version_minor"],
            }
        except Exception as error:
            return {
                "success":False,
                "status":"failed",
                "error":str(error),
            }

    def run_coding_controller(
            self,
            device_name:str,
            version_major:int,
            user_request:str|None=None,
    ) -> dict[str,Any]:
        """Generate a sensor driver from a stored preprocessing version.

        Args:
            device_name: Required existing device name.
            version_major: Major preprocessed version to code.
            user_request: Optional driver requirements; uses the controller default when omitted.
        """

        try:
            device_name = device_name.strip()
            if not device_name:
                raise ValueError("Device name must not be empty.")

            existing_devices = {
                name.casefold():name for name in self.list_devices()
            }
            device_name = existing_devices.get(device_name.casefold())
            if device_name is None:
                raise LookupError("Device not found.")

            versions = self.list_versions(device_name)

            available_major_versions = sorted({
                version["version_major"] for version in versions
            })
            if not available_major_versions:
                raise LookupError(
                    f"No preprocessing versions found for device: {device_name}"
                )

            if version_major is None:
                task_models_by_major = {}
                for major_version in available_major_versions:
                    task_models_by_major[major_version] = self.get_major_task_model_map(
                        device_name,
                        major_version
                    )

                while True:
                    print(f"\nAvailable major versions for {device_name}:")
                    for major_version, task_models in task_models_by_major.items():
                        print(f"v{major_version}")
                        for task_name, model_name in sorted(task_models.items()):
                            print(f"  {task_name}: {model_name}\n")

                    value = read_user_input("\nSelect a major version: ").strip()
                    try:
                        selected_version = int(value)
                    except ValueError:
                        print("Please enter a valid major version.")
                        continue

                    if selected_version in available_major_versions:
                        version_major = selected_version
                        break
                    print("Please select one of the available major versions.")

            elif version_major not in available_major_versions:
                raise LookupError(
                    f"Major version not found: {device_name} v{version_major}"
                )

            major_result = self.get_major_version_result(
                device_name,
                    version_major,
            )
            pages = []
            for version in major_result["pages"]:
                for page in version["pages"]:
                    pages.append({**page,"index":len(pages)})

            if not pages:
                raise ValueError(
                    f"No pages found for device: {device_name} v{version_major}"
                )

            coding_config = self.coding_config
            controller = Controller.load_controller(
                driver_name=device_name,
                config=coding_config,
                pages=pages,
                register_map=major_result["register_map"],
            )
            completed = asyncio.run(
                controller.run(
                    version_major=version_major,
                    user_request=_optional_text(user_request)),
            )

            if not completed:
                return {
                    "success":False,
                    "status":"failed",
                    "error":"Coding controller did not produce accepted files.",
                }

            return {
                "success":True,
                "status":"completed",
                "device_name":device_name,
                "version_major":version_major,
                "output_path":self.coding_config.project_path.code_dir / device_name,
            }
        except Exception as error:
            return {
                "success":False,
                "status":"failed",
                "error":str(error),
            }

    def list_devices(self) -> list[str]:
        """Return all stored device names; no parameters are required."""
        with DataManager(self.database_path) as manager:
            return manager.list_devices()

    def list_versions(self, device_name: str) -> list[dict[str, Any]]:
        """Return all preprocessing-versions for a device.

        Args:
            device_name: Required existing device name.
        """
        with DataManager(self.database_path) as manager:
            return manager.list_versions(device_name)

    def list_task_models(self,device_name: str,) -> list[dict[str, Any]]:
        """Return recorded task models for every preprocessing-version of a device.

        Args:
            device_name: Required existing device name.
        """
        with DataManager(self.database_path) as manager:
            return manager.list_task_models(device_name)

    def get_major_version_result(self,device_name: str,version_major: int,) -> dict[str, Any]:
        """Return all pages of processed PDF and the latest register map for a major preprocessing-version.

        Args:
            device_name: Required existing device name.
            version_major: Required major version number.
        """
        with DataManager(self.database_path) as manager:
            return manager.get_major_version_result(
                device_name,
                version_major,
            )

    def get_major_task_model_map(self,device_name: str,version_major: int,) -> dict[str,str]:
        """Return the task-model mapping(what task uses what model) for a certain major preprocessing-version.

        Args:
            device_name: Required existing device name.
            version_major: Required major version number.
        """
        with DataManager(self.database_path) as manager:
            return manager.get_major_task_model_map(
                device_name,
                version_major,
            )

    def get_register_map(self,device_name: str,version_major: int,) -> dict[str, Any]:
        """Return the latest register map for a major preprocessing-version.

        Args:
            device_name: Required existing device name.
            version_major: Required major version number.
        """
        with DataManager(self.database_path) as manager:
            return manager.get_register_map(
                device_name,
                version_major,
            )

    def get_snapshot(self,device_name: str,version_major: int,version_minor: int,) -> dict[str, Any]:
        """Return the preprocessing snapshot for an exact preprocessing-version.

        Args:
            device_name: Required existing device name.
            version_major: Required major version number.
            version_minor: Required minor version number.
        """
        with DataManager(self.database_path) as manager:
            return manager.get_snapshot(
                device_name,
                version_major,
                version_minor,
            )

    def get_task_models(self, version_pk: int) -> list[dict[str, Any]]:
        """Return task model records for one preprocessing version.

        Args:
            version_pk: Required database identifier of the version.
        """
        with DataManager(self.database_path) as manager:
            return manager.get_task_models(version_pk)

    def get_token_consumption(self,version_pk: int,) -> dict[str,Any]:
        """Return token consumption for one preprocessing version.

        Args:
            version_pk: Required database identifier of the version.
        """
        with DataManager(self.database_path) as manager:
            return manager.get_token_consumption(version_pk)

    def get_version_pk(
            self,
            device_name: str,
            version_major: int,
            version_minor: int,
    ) -> int:
        """Return the database identifier of an exact preprocessing version.

        Args:
            device_name: Required existing device name.
            version_major: Required major version number.
            version_minor: Required minor version number.
        """
        with DataManager(self.database_path) as manager:
            return manager.get_version_pk(
                device_name,
                version_major,
                version_minor,
            )

    def get_info_of_version_pk(self,version_pk:int,) -> dict[str,Any]:
        """Return version identity and metadata for a database version ID.

        Args:
            version_pk: Required database identifier of the version.
        """
        with DataManager(self.database_path) as manager:
            return manager.get_info_of_version_pk(version_pk)

    def find_versions_by_pdf(self,device_name: str,pdf_sha256: str,) -> list[dict[str, Any]]:
        """Find device versions created from a PDF SHA-256 value.

        Args:
            device_name: Required existing device name.
            pdf_sha256: Required 64-character SHA-256 value.
        """
        with DataManager(self.database_path) as manager:
            return manager.find_versions_by_pdf(
                device_name,
                pdf_sha256,
            )

    def update_register_map_field(self,version_pk: int,json_path: str,new_value: Any,) -> dict[str, Any]:
        """Update one register-map field after code-level user approval.

        Args:
            version_pk: Required database identifier of the version.
            json_path: Required JSON path of the field to update.
            new_value: Required replacement value for the field.
        """
        return self._write_with_confirmation(
            "update_register_map_field",
            {
                "version_pk": version_pk,
                "json_path": json_path,
                "new_value": new_value,
            },
            lambda manager: manager.update_register_map_field(
                version_pk,
                json_path,
                new_value,
            ),
        )

    def reassign_version_identity(
            self,
            version_pk:int,
            device_name:str|None=None,
            version_major:int|None=None,
            version_minor:int|None=None,
    ) -> dict[str,Any]:
        """Reassign a preprocessing version after code-level user approval.

        Args:
            version_pk: Required database identifier of the version.
            device_name: Optional existing destination device name.
            version_major: Optional replacement major version number.
            version_minor: Optional replacement minor version number.
        """
        with DataManager(self.database_path) as m:
            row_info =  m.get_info_of_version_pk(version_pk)

        return self._write_with_confirmation(
            "reassign_version_identity",
            {
                "version_pk":version_pk,
                "old_device_name": row_info["device_name"],
                "old_version_major": row_info["version_major"],
                "old_version_minor": row_info["version_minor"],
                "new_device_name":device_name if device_name is not None else row_info["device_name"],
                "new_version_major":version_major if version_major is not None else row_info["version_major"],
                "new_version_minor":version_minor if version_minor is not None else row_info["version_minor"],
            },
            lambda manager: manager.reassign_version_identity(
                version_pk,
                device_name=device_name,
                version_major=version_major,
                version_minor=version_minor,
            ),
        )

    def delete_version(self, version_pk: int) -> dict[str, Any]:
        """Delete one preprocessing version after code-level user approval.

        Args:
            version_pk: Required database identifier of the version.
        """
        return self._write_with_confirmation(
            "delete_version",
            {"version_pk": version_pk},
            lambda manager: manager.delete_version(version_pk),
        )

    def delete_major_version(self,device_name: str,version_major: int,) -> dict[str, Any]:
        """Delete a complete major version after code-level user approval.

        Args:
            device_name: Required existing device name.
            version_major: Required major version number to delete.
        """
        return self._write_with_confirmation(
            "delete_major_version",
            {
                "device_name": device_name,
                "version_major": version_major,
            },
            lambda manager: manager.delete_major_version(
                device_name,
                version_major,
            ),
        )

    def delete_device(self, device_name: str) -> dict[str, Any]:
        """Delete a device and its related data after code-level user approval.

        Args:
            device_name: Required existing device name to delete.
        """
        return self._write_with_confirmation(
            "delete_device",
            {"device_name": device_name},
            lambda manager: manager.delete_device(device_name),
        )

    def _write_with_confirmation(
            self,
            action: str,
            parameters: dict[str, Any],
            operation: Callable[[DataManager],
            dict[str, Any]],) -> dict[str, Any]:

        if not self._confirm(action,parameters):
            return {"success": False, "status": "cancelled"}

        with DataManager(self.database_path) as manager:
            result = operation(manager)

        return {
            "success": True,
            "status": "completed",
            **result,
        }

    def _check_pdf_used(self,device_name: str,pdf_sha256: str,) -> bool:
        existing_versions = self.list_versions(device_name)
        latest_major_version = max(
            version["version_major"] for version in existing_versions
        ) if existing_versions else None

        matching_versions = [
            version for version in existing_versions
            if version["version_major"] == latest_major_version
               and version["input_pdf_sha256"] == pdf_sha256
        ]

        return bool(matching_versions)

    @staticmethod
    def _confirm(action:str,parameters:dict[str,Any],) -> bool:
        print(f"\nRequested action: {action}")
        print(json.dumps(parameters,ensure_ascii=False,indent=2,default=str))

        while True:
            answer = read_user_input("Approve? [yes/no]: ").strip().casefold()
            if answer in {"y","yes"}:
                return True
            if answer in {"","n","no"}:
                return False
            print("Please enter 'yes' or 'no'.")

    def as_tools(self) -> list[Callable[..., Any]]:
        return [
            self.inspect_preprocessing_pdf,
            self.run_preprocessor,
            self.run_coding_controller,
            self.list_devices,
            self.list_versions,
            self.list_task_models,
            self.get_major_version_result,
            self.get_major_task_model_map,
            self.get_register_map,
            self.get_snapshot,
            self.get_task_models,
            self.get_token_consumption,
            self.get_version_pk,
            self.get_info_of_version_pk,
            self.find_versions_by_pdf,
            self.update_register_map_field,
            self.reassign_version_identity,
            self.delete_version,
            self.delete_major_version,
            self.delete_device,
        ]


def build_tools(
        chat_config: ChatConfig,
        preprocessing_config:PreprocessingConfig,
        coding_config:CodingConfig,
) -> list[Callable[..., Any]]:
    return ChatTools(
        chat_config=chat_config,
        preprocessing_config=preprocessing_config,
        coding_config=coding_config,
    ).as_tools()

def _device_identification_input(
        device_names: list[str],
        expected_device_name: str | None,
        ocr_pages: list[dict[str, Any]],
) -> str:
    pages = [
        {
            "index": page.get("index"),
            "markdown": str(page.get("markdown", ""))[:12000],
        }
        for page in ocr_pages[:10]
    ]
    return json.dumps(
        {
            "device_names":device_names,
            "expected_device_name": expected_device_name,
            "pages": pages,
        },
        ensure_ascii=False,
    )

def _validate_pdf_path(pdf_path: str) -> Path:
    path = Path(pdf_path).expanduser().resolve()
    if not path.is_file():
        raise FileNotFoundError(f"PDF file not found: {path}")
    if path.suffix.casefold() != ".pdf":
        raise ValueError(f"Expected a PDF file: {path}")
    return path


def _optional_text(value: str | None) -> str | None:
    if value is None:
        return None
    return value.strip() or None

def _calculate_sha256(pdf_path: Path) -> str:
    digest = hashlib.sha256()
    with pdf_path.open("rb") as file:
        for chunk in iter(lambda: file.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()
