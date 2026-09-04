from pathlib import Path

from src.chat.tools import ChatTools
from src.data_manager.data_manager import DataManager
from src.models.data_manager import MajorVersionResult, OperationFeedback


TASK_MODELS = {
    "classify_pages": "test-model",
    "verify_reg_sum_pages": "test-model",
    "verify_reg_pages": "test-model",
    "add_page_description": "test-model",
    "extract_reg_index": "test-model",
    "extract_reg_map": "test-model",
}

REGISTER_MAP = {
    "registers": [
        {
            "index": 0,
            "name": "CTRL",
            "is_multi_address": False,
            "physical_address": [],
            "register_description": "Control register.",
            "width_bits": 8,
            "type_write_read": "RW",
            "field_parts": [],
            "category": "control",
            "source": [],
            "default_value": "0x00",
            "default_value_description": "Reset value.",
        }
    ]
}


def _save_version(
        manager: DataManager,
        digest: str,
        label: str,
        timestamp: str,
) -> OperationFeedback:
    return manager.save_preprocessing_result(
        device_name="TEST_DEVICE",
        input_pdf_sha256=digest,
        pages=[{"index": 0, "markdown": label}],
        register_map=REGISTER_MAP,
        snapshot={"pdf_path": Path(f"{label}.pdf")},
        pages_created_at=timestamp,
        register_map_created_at=timestamp,
        snapshot_created_at=timestamp,
        token_consumption={"classification": {}},
        task_models=TASK_MODELS,
    )


def test_data_manager_models_cover_public_get_methods(tmp_path: Path) -> None:
    database_path = tmp_path / "database.db"

    with DataManager(database_path) as manager:
        first = _save_version(
            manager,
            "a" * 64,
            "A",
            "2026-08-09T00:00:00Z",
        )
        second = _save_version(
            manager,
            "b" * 64,
            "B",
            "2026-08-09T00:00:01Z",
        )

        first_pk = first.details.version_pk
        second_pk = second.details.version_pk
        major_result = manager.get_major_version_result("TEST_DEVICE", 1)

        assert isinstance(major_result, MajorVersionResult)
        assert len(major_result.documents) == 2
        assert len(major_result.register_maps) == 2
        assert manager.get_latest_version("TEST_DEVICE").version_minor == 1
        assert manager.get_version_result("TEST_DEVICE", first_pk).version_pk == first_pk
        assert len(manager.get_major_version_register_maps("TEST_DEVICE", 1)) == 2
        assert manager.get_version_snapshot(first_pk).version_pk == first_pk
        assert manager.get_major_version_task_models("TEST_DEVICE", 1).task_models.model_dump() == TASK_MODELS
        assert manager.get_version_task_models(first_pk).task_models.model_dump() == TASK_MODELS
        assert manager.get_version_token_consumption(first_pk).version_pk == first_pk
        assert manager.get_version_pk("TEST_DEVICE", 1, 1) == second_pk
        assert manager.get_version_info(first_pk).version_pk == first_pk
        assert len(manager.get_versions_by_pdf("TEST_DEVICE", "a" * 64)) == 1


def test_data_manager_update_and_delete_feedback(tmp_path: Path) -> None:
    database_path = tmp_path / "database.db"

    with DataManager(database_path) as manager:
        first = _save_version(
            manager,
            "a" * 64,
            "A",
            "2026-08-09T00:00:00Z",
        )
        second = _save_version(
            manager,
            "b" * 64,
            "B",
            "2026-08-09T00:00:01Z",
        )

        first_pk = first.details.version_pk
        second_pk = second.details.version_pk

        update = manager.update_register_map_field(
            first_pk,
            "$.registers[0].name",
            "CONTROL",
        )
        assert update.succeeded is True
        assert update.details["changed"] is True

        deletion = manager.delete_version(second_pk)
        assert deletion.succeeded is True
        assert deletion.details["version_pk"] == second_pk

        major_deletion = manager.delete_major_version("TEST_DEVICE", 1)
        assert major_deletion.succeeded is True
        assert major_deletion.details["deleted_versions"] == 1

        device_deletion = manager.delete_device("TEST_DEVICE")
        assert device_deletion.succeeded is True


def test_all_data_manager_get_update_delete_methods_are_registered() -> None:
    registered_names = {
        tool.__name__
        for tool in ChatTools.__new__(ChatTools).as_tools()
    }

    expected_names = {
        "get_latest_version",
        "get_major_version_register_maps",
        "get_major_version_result",
        "get_major_version_task_models",
        "get_version_info",
        "get_version_pk",
        "get_version_result",
        "get_version_snapshot",
        "get_version_task_models",
        "get_version_token_consumption",
        "get_versions_by_pdf",
        "update_register_map_field",
        "reassign_version_identity",
        "delete_version",
        "delete_major_version",
        "delete_device",
    }

    assert expected_names <= registered_names


def test_chat_tools_serialize_data_manager_models(tmp_path: Path) -> None:
    database_path = tmp_path / "database.db"

    with DataManager(database_path) as manager:
        feedback = _save_version(
            manager,
            "a" * 64,
            "A",
            "2026-08-09T00:00:00Z",
        )
        version_pk = feedback.details.version_pk

    tools = ChatTools.__new__(ChatTools)
    tools.database_path = database_path
    tools._confirm = lambda action, parameters: True

    major_result = tools.get_major_version_result("TEST_DEVICE", 1)
    update_result = tools.update_register_map_field(
        version_pk,
        "$.registers[0].name",
        "CONTROL",
    )

    assert major_result["documents"][0]["pdf_sha256"] == "a" * 64
    assert update_result["success"] is True
    assert update_result["succeeded"] is True
    assert update_result["details"]["changed"] is True
