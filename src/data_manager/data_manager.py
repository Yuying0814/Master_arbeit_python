from __future__ import annotations

import sqlite3
import json

from pathlib import Path
from contextlib import contextmanager
from collections.abc import Iterator
from typing import Any
from uuid import uuid4

from src.models.data_manager.data_manager import (
    VersionInfo, MajorVersionNumber, MajorTaskModelInfo, TaskModelInfo,
    MajorPdfInfo,VersionResult, MajorVersionResult, DocumentRecord, RegisterMapRecord,
    DeviceFunctionsRecord,
    SnapshotRecord, PreprocessingTokenConsumptionRecord, OperationFeedback, LatestVersion,
    MajorVersionDeletionRecord, RenumberedMajorVersion,
    PreprocessorSnapshot, TaskModelsByName,
)

from src.models.preprocessing.preprocessor import PreprocessingTokenConsumption
from src.models.preprocessing.register_output import RegisterMapOutput
from src.models.preprocessing.function_identifier import DeviceFunctionOutput


class SchemaMismatchError(RuntimeError):
    pass


SCHEMA_SQL = """
CREATE TABLE IF NOT EXISTS change_records (
    change_id INTEGER PRIMARY KEY AUTOINCREMENT,
    operation_id TEXT NOT NULL CHECK (length(trim(operation_id)) > 0),
    operation_name TEXT NOT NULL CHECK (length(trim(operation_name)) > 0),
    action TEXT NOT NULL CHECK (action IN ('INSERT', 'UPDATE', 'DELETE')),
    table_name TEXT NOT NULL CHECK (length(trim(table_name)) > 0),
    record_key_json TEXT NOT NULL CHECK (json_valid(record_key_json)),
    column_names TEXT CHECK (
    column_names IS NULL
    OR (
        json_valid(column_names)
        AND json_type(column_names) = 'array'
    )
),
    json_path TEXT,
    old_value_json TEXT CHECK (old_value_json IS NULL OR json_valid(old_value_json)),
    new_value_json TEXT CHECK (new_value_json IS NULL OR json_valid(new_value_json)),
    changed_at TEXT NOT NULL CHECK (length(trim(changed_at)) > 0)
);

CREATE INDEX IF NOT EXISTS idx_change_records_operation_id
ON change_records (operation_id);

CREATE TABLE IF NOT EXISTS devices (
    device_name TEXT PRIMARY KEY
        CHECK (length(trim(device_name)) > 0 AND device_name = trim(device_name))
);

CREATE TABLE IF NOT EXISTS documents (
    document_id INTEGER PRIMARY KEY AUTOINCREMENT,
    input_pdf_sha256 TEXT NOT NULL UNIQUE CHECK (
        length(input_pdf_sha256) = 64
        AND input_pdf_sha256 NOT GLOB '*[^0-9a-f]*'
    ),
    pdf_name TEXT NOT NULL CHECK (
        length(trim(pdf_name)) > 0
        AND pdf_name = trim(pdf_name)
    )
);

CREATE TABLE IF NOT EXISTS preprocessing_versions (
    version_pk INTEGER PRIMARY KEY AUTOINCREMENT,
    device_name TEXT NOT NULL,
    version_major INTEGER NOT NULL CHECK (version_major >= 1),
    version_minor INTEGER NOT NULL CHECK (version_minor >= 0),
    input_pdf_sha256 TEXT NOT NULL CHECK (
        length(input_pdf_sha256) = 64
        AND input_pdf_sha256 NOT GLOB '*[^0-9a-f]*'
    ),
    pages_json TEXT NOT NULL CHECK (json_valid(pages_json)),
    pages_json_created_at TEXT NOT NULL CHECK (
        length(trim(pages_json_created_at)) > 0
    ),
    register_map_json TEXT NOT NULL CHECK (json_valid(register_map_json)),
    register_map_created_at TEXT NOT NULL CHECK (
        length(trim(register_map_created_at)) > 0
    ),
    register_map_modified_at TEXT NOT NULL CHECK (
        length(trim(register_map_modified_at)) > 0
    ),
    snapshot_json TEXT NOT NULL CHECK (json_valid(snapshot_json)),
    snapshot_created_at TEXT NOT NULL CHECK (
        length(trim(snapshot_created_at)) > 0
    ),
    token_consumption TEXT NOT NULL CHECK (json_valid(token_consumption)),
    device_functions TEXT NOT NULL CHECK (json_valid(device_functions)),

    FOREIGN KEY (device_name) REFERENCES devices (device_name)
        ON UPDATE CASCADE ON DELETE CASCADE,
    
    FOREIGN KEY (input_pdf_sha256)
        REFERENCES documents (input_pdf_sha256)
        ON UPDATE RESTRICT
        ON DELETE RESTRICT,
    
    UNIQUE (device_name, version_major, version_minor),
    UNIQUE (device_name, version_major, input_pdf_sha256)
);

CREATE TABLE IF NOT EXISTS task_models (
    version_pk INTEGER NOT NULL,
    task_name TEXT NOT NULL CHECK (length(trim(task_name)) > 0),
    model_name TEXT NOT NULL CHECK (length(trim(model_name)) > 0),
    PRIMARY KEY (version_pk, task_name),
    FOREIGN KEY (version_pk) REFERENCES preprocessing_versions (version_pk)
        ON UPDATE CASCADE ON DELETE CASCADE
);
"""

EXPECTED_COLUMNS = {
    "devices": (
        "device_name",

    ),

    "documents":(
        "document_id",
        "input_pdf_sha256",
        "pdf_name",
    ),

    "preprocessing_versions": (
        "version_pk",
        "device_name",
        "version_major",
        "version_minor",
        "input_pdf_sha256",
        "pages_json",
        "pages_json_created_at",
        "register_map_json",
        "register_map_created_at",
        "register_map_modified_at",
        "snapshot_json",
        "snapshot_created_at",
        "token_consumption",
        "device_functions",
    ),

    "task_models": (
        "version_pk",
        "task_name",
        "model_name",
    ),

    "change_records": (
        "change_id",
        "operation_id",
        "operation_name",
        "action",
        "table_name",
        "record_key_json",
        "column_names",
        "json_path",
        "old_value_json",
        "new_value_json",
        "changed_at",
    ),
}

AUDIT_TRIGGER_SQL = """
CREATE TRIGGER IF NOT EXISTS audit_insert_devices
AFTER INSERT ON devices
FOR EACH ROW
BEGIN
    INSERT INTO change_records (
        operation_id,
        operation_name,
        action,
        table_name,
        record_key_json,
        column_names,
        json_path,
        old_value_json,
        new_value_json,
        changed_at
    )
    VALUES (
        current_operation_id(),
        current_operation_name(),
        'INSERT',
        'devices',
        json_object('device_name', NEW.device_name),
        NULL,
        NULL,
        NULL,
        json_object('device_name', NEW.device_name),
        strftime('%Y-%m-%dT%H:%M:%fZ', 'now')
    );
END;

CREATE TRIGGER IF NOT EXISTS audit_update_devices
AFTER UPDATE ON devices
FOR EACH ROW
WHEN OLD.device_name IS NOT NEW.device_name
BEGIN
    INSERT INTO change_records (
        operation_id,
        operation_name,
        action,
        table_name,
        record_key_json,
        column_names,
        json_path,
        old_value_json,
        new_value_json,
        changed_at
    )
    VALUES (
        current_operation_id(),
        current_operation_name(),
        'UPDATE',
        'devices',
        json_object('device_name', NEW.device_name),
        json_array('device_name'),
        NULL,
        json_object('device_name', OLD.device_name),
        json_object('device_name', NEW.device_name),
        strftime('%Y-%m-%dT%H:%M:%fZ', 'now')
    );
END;

CREATE TRIGGER IF NOT EXISTS audit_delete_devices
AFTER DELETE ON devices
FOR EACH ROW
BEGIN
    INSERT INTO change_records (
        operation_id,
        operation_name,
        action,
        table_name,
        record_key_json,
        column_names,
        json_path,
        old_value_json,
        new_value_json,
        changed_at
    )
    VALUES (
        current_operation_id(),
        current_operation_name(),
        'DELETE',
        'devices',
        json_object('device_name', OLD.device_name),
        NULL,
        NULL,
        json_object('device_name', OLD.device_name),
        NULL,
        strftime('%Y-%m-%dT%H:%M:%fZ', 'now')
    );
END;

CREATE TRIGGER IF NOT EXISTS audit_insert_preprocessing_versions
AFTER INSERT ON preprocessing_versions
FOR EACH ROW
BEGIN
    INSERT INTO change_records (
        operation_id,
        operation_name,
        action,
        table_name,
        record_key_json,
        column_names,
        json_path,
        old_value_json,
        new_value_json,
        changed_at
    )
    VALUES (
        current_operation_id(),
        current_operation_name(),
        'INSERT',
        'preprocessing_versions',
        json_object(
            'version_pk', NEW.version_pk,
            'device_name', NEW.device_name,
            'version_major', NEW.version_major,
            'version_minor', NEW.version_minor
        ),
        NULL,
        NULL,
        NULL,
        json_object(
            'version_pk', NEW.version_pk,
            'device_name', NEW.device_name,
            'version_major', NEW.version_major,
            'version_minor', NEW.version_minor,
            'input_pdf_sha256', NEW.input_pdf_sha256,
            'pages_json_created_at', NEW.pages_json_created_at,
            'register_map_created_at', NEW.register_map_created_at,
            'register_map_modified_at', NEW.register_map_modified_at,
            'snapshot_created_at', NEW.snapshot_created_at
        ),
        strftime('%Y-%m-%dT%H:%M:%fZ', 'now')
    );
END;

CREATE TRIGGER IF NOT EXISTS validate_update_preprocessing_versions
BEFORE UPDATE ON preprocessing_versions
FOR EACH ROW
BEGIN
    SELECT CASE
        WHEN OLD.version_pk IS NOT NEW.version_pk
            OR OLD.input_pdf_sha256 IS NOT NEW.input_pdf_sha256
            OR OLD.pages_json IS NOT NEW.pages_json
            OR OLD.pages_json_created_at IS NOT NEW.pages_json_created_at
            OR OLD.register_map_created_at IS NOT NEW.register_map_created_at
            OR OLD.snapshot_json IS NOT NEW.snapshot_json
            OR OLD.snapshot_created_at IS NOT NEW.snapshot_created_at
            OR OLD.token_consumption IS NOT NEW.token_consumption
            OR OLD.device_functions IS NOT NEW.device_functions
        THEN RAISE(
        ABORT,'immutable preprocessing version fields cannot be updated'
        )
    END;

    SELECT CASE
        WHEN OLD.register_map_json IS NOT NEW.register_map_json
            AND (
                OLD.device_name IS NOT NEW.device_name
                OR OLD.version_major IS NOT NEW.version_major
                OR OLD.version_minor IS NOT NEW.version_minor
            )
        THEN RAISE(
        ABORT,'register_map_json cannot be updated with version identity fields'
        )
    END;

    SELECT CASE
        WHEN OLD.register_map_modified_at IS NOT NEW.register_map_modified_at
            AND OLD.register_map_json IS NEW.register_map_json
        THEN RAISE(
            ABORT,'register_map_modified_at can only be updated with register_map_json'
        )
    END;

    SELECT CASE
        WHEN OLD.register_map_json IS NOT NEW.register_map_json
            AND current_json_path() IS NULL
        THEN RAISE(
            ABORT,'json_path is required for register_map_json updates'
        )
    END;

    SELECT CASE
        WHEN OLD.register_map_json IS NOT NEW.register_map_json
            AND current_json_path() = '$'
        THEN RAISE(
            ABORT,'the whole register_map_json cannot be replaced or deleted'
        )
    END;
END;

CREATE TRIGGER IF NOT EXISTS audit_update_preprocessing_versions
AFTER UPDATE ON preprocessing_versions
FOR EACH ROW
WHEN OLD.device_name IS NOT NEW.device_name
    OR OLD.version_major IS NOT NEW.version_major
    OR OLD.version_minor IS NOT NEW.version_minor
    OR OLD.register_map_json IS NOT NEW.register_map_json
    OR OLD.register_map_modified_at IS NOT NEW.register_map_modified_at
BEGIN
    INSERT INTO change_records (
        operation_id,
        operation_name,
        action,
        table_name,
        record_key_json,
        column_names,
        json_path,
        old_value_json,
        new_value_json,
        changed_at
    )
    VALUES (
        current_operation_id(),
        current_operation_name(),
        'UPDATE',
        'preprocessing_versions',
        json_object(
            'version_pk', NEW.version_pk,
            'device_name', NEW.device_name,
            'version_major', NEW.version_major,
            'version_minor', NEW.version_minor
        ),
(
    SELECT json_group_array(column_name)
    FROM (
        SELECT 1 AS position, 'device_name' AS column_name
        WHERE OLD.device_name IS NOT NEW.device_name
        UNION ALL

        SELECT 2, 'version_major'
        WHERE OLD.version_major IS NOT NEW.version_major
        UNION ALL

        SELECT 3, 'version_minor'
        WHERE OLD.version_minor IS NOT NEW.version_minor
        UNION ALL

        SELECT 4, 'register_map_json'
        WHERE OLD.register_map_json IS NOT NEW.register_map_json
        UNION ALL

        SELECT 5, 'register_map_modified_at'
        WHERE OLD.register_map_modified_at IS NOT NEW.register_map_modified_at
        ORDER BY position
    )
),

        CASE
            WHEN OLD.register_map_json IS NOT NEW.register_map_json
            THEN current_json_path()
        END,

        CASE
            WHEN OLD.register_map_json IS NOT NEW.register_map_json
            THEN json_object(
                'json_type', json_type(OLD.register_map_json, current_json_path()),
                'value', json_extract(OLD.register_map_json, current_json_path()),
                'register_map_modified_at', OLD.register_map_modified_at
            )
            ELSE json_object(
                'device_name', OLD.device_name,
                'version_major', OLD.version_major,
                'version_minor', OLD.version_minor
            )
        END,
        CASE
            WHEN OLD.register_map_json IS NOT NEW.register_map_json
            THEN json_object(
                'json_type', json_type(NEW.register_map_json, current_json_path()),
                'value', json_extract(NEW.register_map_json, current_json_path()),
                'register_map_modified_at', NEW.register_map_modified_at
            )
            ELSE json_object(
                'device_name', NEW.device_name,
                'version_major', NEW.version_major,
                'version_minor', NEW.version_minor
            )
        END,
        strftime('%Y-%m-%dT%H:%M:%fZ', 'now')
    );
END;

CREATE TRIGGER IF NOT EXISTS audit_delete_preprocessing_versions
AFTER DELETE ON preprocessing_versions
FOR EACH ROW
BEGIN
    INSERT INTO change_records (
        operation_id,
        operation_name,
        action,
        table_name,
        record_key_json,
        column_names,
        json_path,
        old_value_json,
        new_value_json,
        changed_at
    )
    VALUES (
        current_operation_id(),
        current_operation_name(),
        'DELETE',
        'preprocessing_versions',
        json_object(
            'version_pk', OLD.version_pk,
            'device_name', OLD.device_name,
            'version_major', OLD.version_major,
            'version_minor', OLD.version_minor
        ),
        NULL,
        NULL,
        json_object(
            'version_pk', OLD.version_pk,
            'device_name', OLD.device_name,
            'version_major', OLD.version_major,
            'version_minor', OLD.version_minor,
            'input_pdf_sha256', OLD.input_pdf_sha256,
            'pages_json_created_at', OLD.pages_json_created_at,
            'register_map_created_at', OLD.register_map_created_at,
            'register_map_modified_at', OLD.register_map_modified_at,
            'snapshot_created_at', OLD.snapshot_created_at
        ),
        NULL,
        strftime('%Y-%m-%dT%H:%M:%fZ', 'now')
    );
END;

CREATE TRIGGER IF NOT EXISTS audit_insert_task_models
AFTER INSERT ON task_models
FOR EACH ROW
BEGIN
    INSERT INTO change_records (
        operation_id,
        operation_name,
        action,
        table_name,
        record_key_json,
        column_names,
        json_path,
        old_value_json,
        new_value_json,
        changed_at
    )
    VALUES (
        current_operation_id(),
        current_operation_name(),
        'INSERT',
        'task_models',
        json_object(
            'version_pk', NEW.version_pk,
            'task_name', NEW.task_name
        ),
        NULL,
        NULL,
        NULL,
        json_object(
            'version_pk', NEW.version_pk,
            'task_name', NEW.task_name,
            'model_name', NEW.model_name
        ),
        strftime('%Y-%m-%dT%H:%M:%fZ', 'now')
    );
END;

CREATE TRIGGER IF NOT EXISTS audit_update_task_models
BEFORE UPDATE ON task_models
FOR EACH ROW
WHEN OLD.version_pk IS NOT NEW.version_pk
    OR OLD.task_name IS NOT NEW.task_name
    OR OLD.model_name IS NOT NEW.model_name
BEGIN
    SELECT RAISE(
        ABORT,'task_models records cannot be updated'
    );
END;

CREATE TRIGGER IF NOT EXISTS audit_delete_task_models
AFTER DELETE ON task_models
FOR EACH ROW
BEGIN
    INSERT INTO change_records (
        operation_id,
        operation_name,
        action,
        table_name,
        record_key_json,
        column_names,
        json_path,
        old_value_json,
        new_value_json,
        changed_at
    )
    VALUES (
        current_operation_id(),
        current_operation_name(),
        'DELETE',
        'task_models',
        json_object(
            'version_pk', OLD.version_pk,
            'task_name', OLD.task_name
        ),
        NULL,
        NULL,
        json_object(
            'version_pk', OLD.version_pk,
            'task_name', OLD.task_name,
            'model_name', OLD.model_name
        ),
        NULL,
        strftime('%Y-%m-%dT%H:%M:%fZ', 'now')
    );
END;

CREATE TRIGGER IF NOT EXISTS audit_insert_documents
AFTER INSERT ON documents
FOR EACH ROW
BEGIN
    INSERT INTO change_records (
        operation_id,
        operation_name,
        action,
        table_name,
        record_key_json,
        column_names,
        json_path,
        old_value_json,
        new_value_json,
        changed_at
    )
    VALUES (
        current_operation_id(),
        current_operation_name(),
        'INSERT',
        'documents',
        json_object(
            'document_id', NEW.document_id,
            'input_pdf_sha256', NEW.input_pdf_sha256
        ),
        NULL,
        NULL,
        NULL,
        json_object(
            'document_id', NEW.document_id,
            'input_pdf_sha256', NEW.input_pdf_sha256,
            'pdf_name', NEW.pdf_name
        ),
        strftime('%Y-%m-%dT%H:%M:%fZ', 'now')
    );
END;


CREATE TRIGGER IF NOT EXISTS validate_update_documents
BEFORE UPDATE ON documents
FOR EACH ROW
BEGIN
    SELECT CASE
        WHEN OLD.document_id IS NOT NEW.document_id
            OR OLD.input_pdf_sha256 IS NOT NEW.input_pdf_sha256
        THEN RAISE(
            ABORT,
            'document_id and input_pdf_sha256 cannot be updated'
        )
    END;
END;


CREATE TRIGGER IF NOT EXISTS audit_update_documents
AFTER UPDATE ON documents
FOR EACH ROW
WHEN OLD.pdf_name IS NOT NEW.pdf_name
BEGIN
    INSERT INTO change_records (
        operation_id,
        operation_name,
        action,
        table_name,
        record_key_json,
        column_names,
        json_path,
        old_value_json,
        new_value_json,
        changed_at
    )
    VALUES (
        current_operation_id(),
        current_operation_name(),
        'UPDATE',
        'documents',
        json_object(
            'document_id', NEW.document_id,
            'input_pdf_sha256', NEW.input_pdf_sha256
        ),
        json_array('pdf_name'),
        NULL,
        json_object(
            'pdf_name', OLD.pdf_name
        ),
        json_object(
            'pdf_name', NEW.pdf_name
        ),
        strftime('%Y-%m-%dT%H:%M:%fZ', 'now')
    );
END;


CREATE TRIGGER IF NOT EXISTS audit_delete_documents
AFTER DELETE ON documents
FOR EACH ROW
BEGIN
    INSERT INTO change_records (
        operation_id,
        operation_name,
        action,
        table_name,
        record_key_json,
        column_names,
        json_path,
        old_value_json,
        new_value_json,
        changed_at
    )
    VALUES (
        current_operation_id(),
        current_operation_name(),
        'DELETE',
        'documents',
        json_object(
            'document_id', OLD.document_id,
            'input_pdf_sha256', OLD.input_pdf_sha256
        ),
        NULL,
        NULL,
        json_object(
            'document_id', OLD.document_id,
            'input_pdf_sha256', OLD.input_pdf_sha256,
            'pdf_name', OLD.pdf_name
        ),
        NULL,
        strftime('%Y-%m-%dT%H:%M:%fZ', 'now')
    );
END;

CREATE TRIGGER IF NOT EXISTS cleanup_orphan_documents
AFTER DELETE ON preprocessing_versions
FOR EACH ROW
BEGIN
    DELETE FROM documents
    WHERE input_pdf_sha256 = OLD.input_pdf_sha256
      AND NOT EXISTS (
          SELECT 1
          FROM preprocessing_versions
          WHERE input_pdf_sha256 = OLD.input_pdf_sha256
      );
END;
"""

EXPECTED_TRIGGERS = (
    "audit_insert_devices",
    "audit_update_devices",
    "audit_delete_devices",

    "audit_insert_preprocessing_versions",
    "validate_update_preprocessing_versions",
    "audit_update_preprocessing_versions",
    "audit_delete_preprocessing_versions",

    "audit_insert_task_models",
    "audit_update_task_models",
    "audit_delete_task_models",

    "audit_insert_documents",
    "audit_update_documents",
    "audit_delete_documents",
    "validate_update_documents",
    "cleanup_orphan_documents",
)


class DataManager:
    def __init__(self, db_path: str | Path) -> None:
        self.db_path = Path(db_path).expanduser().resolve()
        self._connection: sqlite3.Connection | None = None

        self._current_operation_id = None
        self._current_operation_name = None
        self._current_json_path = None

    def connect(self) -> sqlite3.Connection:
        if self._connection is not None:
            return self._connection
        if self.db_path.exists() and self.db_path.is_dir():
            raise IsADirectoryError(self.db_path)

        self.db_path.parent.mkdir(parents=True, exist_ok=True)
        self._connection = sqlite3.connect(self.db_path, timeout=30.0)
        self._connection.row_factory = sqlite3.Row
        self._connection.execute("PRAGMA foreign_keys = ON")

        self._connection.create_function(
            "current_operation_id",
            0,
            self._get_operation_id,
        )

        self._connection.create_function(
            "current_operation_name",
            0,
            self._get_operation_name,
        )

        self._connection.create_function(
            "current_json_path",
            0,
            self._get_current_json_path,
        )

        return self._connection

    @property
    def connection(self) -> sqlite3.Connection:
        if self._connection is None:
            raise RuntimeError("Database is not connected")
        return self._connection

    def _get_operation_id(self) -> str:
        return self._current_operation_id

    def _get_operation_name(self) -> str:
        return self._current_operation_name

    def _get_current_json_path(self) -> str:
        return self._current_json_path

    def initialize(self) -> None:
        self._check_table_fields()

        try:
            self.connection.executescript("BEGIN IMMEDIATE;\n" + SCHEMA_SQL + AUDIT_TRIGGER_SQL)
            self._check_triggers()

            errors = self.connection.execute("PRAGMA foreign_key_check").fetchall()
            if errors:
                raise SchemaMismatchError(f"Foreign-key errors: {errors}")
            self.connection.commit()
        except Exception:
            if self.connection.in_transaction:
                self.connection.rollback()
            raise

# List-tools
    def list_all_devices(self) -> list[str]:
        rows = self.connection.execute(
            "SELECT device_name FROM devices ORDER BY device_name"
        ).fetchall()
        return [row["device_name"] for row in rows]

    def list_all_versions(self, device_name: str) -> list[VersionInfo]:
        rows = self.connection.execute(
            """
            SELECT
                preprocessing_versions.device_name,
                preprocessing_versions.version_pk,
                preprocessing_versions.version_major,
                preprocessing_versions.version_minor,
                preprocessing_versions.input_pdf_sha256,
                documents.pdf_name,
                preprocessing_versions.pages_json_created_at,
                preprocessing_versions.register_map_created_at,
                preprocessing_versions.register_map_modified_at,
                preprocessing_versions.snapshot_created_at
            FROM preprocessing_versions
            JOIN documents
                ON documents.input_pdf_sha256 =
                   preprocessing_versions.input_pdf_sha256
            WHERE preprocessing_versions.device_name = ?
            ORDER BY
                preprocessing_versions.version_major,
                preprocessing_versions.version_minor
            """,
            (device_name,),
        ).fetchall()
        return [VersionInfo.model_validate(dict(row)) for row in rows]

    def list_all_major_version_task_models(self,device_name: str,) -> list[MajorTaskModelInfo]:
        with self._read_transaction():
            major_version_numbers = self.list_all_major_version_numbers(device_name)

            return [
                self.get_major_version_task_models(
                    device_name=device_name,
                    version_major = major_version,
                )
                for major_version in major_version_numbers.major_versions
            ]

    def list_all_major_version_numbers(self,device_name:str) -> MajorVersionNumber:
        versions = self.list_all_versions(device_name)

        major_versions = {
            version.version_major
            for version in versions
        }

        return MajorVersionNumber(
            device_name=device_name,
            major_versions=tuple(sorted(major_versions)),
        )

    def list_all_major_version_pdfs(self,device_name:str) -> list[MajorPdfInfo]:
        with self._read_transaction():
            major_version_numbers = self.list_all_major_version_numbers(device_name)

            return [
                self.get_major_version_pdfs(
                    device_name=device_name,
                    version_major = major_version,
                )
                for major_version in major_version_numbers.major_versions
            ]


# Get-tools
    def get_latest_version(self, device_name: str) -> LatestVersion:
        row = self.connection.execute(
            """
            SELECT version_pk, version_major, version_minor
            FROM preprocessing_versions
            WHERE device_name = ?
            ORDER BY version_major DESC, version_minor DESC
            LIMIT 1
            """,
            (device_name,),
        ).fetchone()

        if row is None:
            raise LookupError(f"No versions found for device: {device_name}")

        return LatestVersion(
            device_name=device_name,
            version_pk = row["version_pk"],
            version_major=row["version_major"],
            version_minor=row["version_minor"],
        )

    def get_major_version_pdfs(self, device_name:str, version_major:int,) -> MajorPdfInfo:
        rows = self.connection.execute(
            """
            SELECT documents.pdf_name
            FROM preprocessing_versions
            JOIN documents
                ON documents.input_pdf_sha256 =
                   preprocessing_versions.input_pdf_sha256
            WHERE preprocessing_versions.device_name = ?
              AND preprocessing_versions.version_major = ?
            ORDER BY preprocessing_versions.version_minor
            """,
            (
                device_name,
                version_major,
            ),
        ).fetchall()

        if not rows:
            raise LookupError(
                f"Major version not found: "
                f"{device_name} v{version_major}"
            )

        return MajorPdfInfo(
            device_name=device_name,
            version_major=version_major,
            pdfs = [row["pdf_name"]for row in rows]
        )


    def get_major_version_result(self, device_name: str, version_major: int) -> MajorVersionResult:
        with self._read_transaction():
            if not self._device_exists(device_name):
                raise LookupError(f"Device not found: {device_name}")

            rows = self.connection.execute(
                """
                SELECT
                    version_pk,
                    version_minor,
                    input_pdf_sha256,
                    pages_json,
                    register_map_json,
                    device_functions
                FROM preprocessing_versions
                WHERE device_name = ?
                  AND version_major = ?
                ORDER BY version_minor
                """,
                (device_name, version_major),
            ).fetchall()

            if not rows:
                raise LookupError(
                    f"Major version not found: "
                    f"{device_name} v{version_major}"
                )

            return MajorVersionResult(
                device_name=device_name,
                version_major=version_major,
                documents=[
                    DocumentRecord(
                        device_name=device_name,
                        version_pk=row["version_pk"],
                        version_major=version_major,
                        version_minor=row["version_minor"],
                        pdf_sha256=row["input_pdf_sha256"],
                        pages=json.loads(row["pages_json"]),
                    ) for row in rows
                ],
                register_maps=[
                    RegisterMapRecord(
                        device_name=device_name,
                        version_pk=row["version_pk"],
                        version_major=version_major,
                        version_minor=row["version_minor"],
                        pdf_sha256=row["input_pdf_sha256"],
                        register_map=json.loads(row["register_map_json"]),
                    ) for row in rows
                ],
                device_functions=[
                    DeviceFunctionsRecord(
                        device_name=device_name,
                        version_pk=row["version_pk"],
                        version_major=version_major,
                        version_minor=row["version_minor"],
                        pdf_sha256=row["input_pdf_sha256"],
                        device_functions=json.loads(row["device_functions"]),
                    ) for row in rows
                ],
            )

    def get_version_result(self, device_name: str, version_pk:int) -> VersionResult:
        row = self.connection.execute(
            """
            SELECT *
            FROM preprocessing_versions
            WHERE device_name = ?
              AND version_pk = ?
            """,
            (device_name, version_pk),
        ).fetchone()

        if row is None:
            raise LookupError(
                f"VersionInfo not found: {device_name}\n "
                f"version_pk {version_pk}"
            )

        return VersionResult(
            device_name=device_name,
            version_pk=version_pk,
            version_major=row["version_major"],
            version_minor=row["version_minor"],
            input_pdf_sha256=row["input_pdf_sha256"],
            pages_json=json.loads(row["pages_json"]),
            pages_json_created_at=row["pages_json_created_at"],
            register_map_json=json.loads(row["register_map_json"]),
            register_map_created_at=row["register_map_created_at"],
            register_map_modified_at=row["register_map_modified_at"],
            device_functions=json.loads(row["device_functions"]),
            snapshot_json=json.loads(row["snapshot_json"]),
            snapshot_created_at=row["snapshot_created_at"],
            token_consumption=json.loads(row["token_consumption"]),
        )

    def get_version_pdf(self, device_name:str, version_pk:int):
        row = self.connection.execute(
            """
            SELECT documents.pdf_name
            FROM preprocessing_versions
            JOIN documents
                ON documents.input_pdf_sha256 =
                   preprocessing_versions.input_pdf_sha256
            WHERE preprocessing_versions.device_name = ?
              AND preprocessing_versions.version_pk = ?
            LIMIT 1
            """,
            (
                device_name,
                version_pk,
            ),
        ).fetchone()

        if row is None:
            raise LookupError(f"PDF not found: version_pk={version_pk}")

        return row["pdf_name"]

    def get_major_version_register_maps(self, device_name: str, version_major: int) -> list[RegisterMapRecord]:
        rows = self.connection.execute(
            """
            SELECT version_pk, register_map_json, input_pdf_sha256, version_minor
            FROM preprocessing_versions
            WHERE device_name = ?
                AND version_major = ?
            ORDER BY version_minor ASC
            """,
            (device_name, version_major),
        ).fetchall()

        if not rows:
            raise LookupError(f"Major version {version_major} of device {device_name} not found")

        return [
            RegisterMapRecord(
                device_name=device_name,
                version_pk=row["version_pk"],
                version_major=version_major,
                version_minor=row["version_minor"],
                pdf_sha256=row["input_pdf_sha256"],
                register_map=json.loads(row["register_map_json"]),
            ) for row in rows
        ]

    def get_version_snapshot(self, version_pk:int) -> SnapshotRecord:
        with self._read_transaction():
            version_info = self.get_version_info(version_pk)

            row = self.connection.execute(
                """
                SELECT device_name, version_major, version_minor, snapshot_json
                FROM preprocessing_versions
                WHERE version_pk = ?
                LIMIT 1
                """,
                (version_pk,),

            ).fetchone()

            if row is None:
                raise LookupError(
                    f"Snapshot not found: version_pk={version_pk}"
                )

            snapshot = PreprocessorSnapshot.model_validate_json(
                row["snapshot_json"]
            )

        return SnapshotRecord(
            device_name = version_info.device_name,
            version_pk = version_pk,
            version_major = version_info.version_major,
            version_minor = version_info.version_minor,
            snapshot=snapshot,
        )

    def get_major_version_task_models(self, device_name: str, version_major: int,) -> MajorTaskModelInfo:
        with self._read_transaction():
            rows = self.connection.execute(
                """
                SELECT
                    preprocessing_versions.version_pk,
                    preprocessing_versions.version_minor,
                    task_models.task_name,
                    task_models.model_name
                FROM preprocessing_versions
                LEFT JOIN task_models
                    ON task_models.version_pk = preprocessing_versions.version_pk
                WHERE preprocessing_versions.device_name = ?
                  AND preprocessing_versions.version_major = ?
                ORDER BY
                    preprocessing_versions.version_minor,
                    task_models.task_name
                """,
                (device_name, version_major),
            ).fetchall()

        if not rows:
            raise LookupError(
                f"Major version not found: {device_name} v{version_major}"
            )

        task_models_by_version_pk: dict[int, dict[str, str]] = {}

        for row in rows:
            task_models_by_name = task_models_by_version_pk.setdefault(
                row["version_pk"],
                {},
            )
            if row["task_name"] is not None:
                task_models_by_name[row["task_name"]] = row["model_name"]

        reference_version_pk, reference_task_models = next(
            iter(task_models_by_version_pk.items())
        )

        for version_pk, task_models_by_name in task_models_by_version_pk.items():
            if task_models_by_name != reference_task_models:
                raise RuntimeError(
                    "Inconsistent task-model mappings in "
                    f"{device_name} v{version_major}: "
                    f"version_pk={reference_version_pk} and "
                    f"version_pk={version_pk}"
                )

        return MajorTaskModelInfo(
            device_name = device_name,
            version_major=version_major,
            task_models=TaskModelsByName.model_validate(reference_task_models),
        )

    def get_version_task_models(self, version_pk: int) -> TaskModelInfo:
        with self._read_transaction():
            version_info = self.get_version_info(version_pk)

            rows = self.connection.execute(
                """
                SELECT task_name, model_name
                FROM task_models
                WHERE version_pk = ?
                """,
                (version_pk,),
            ).fetchall()

            task_models_by_name = {
                row["task_name"]: row["model_name"]
                for row in rows
            }

        return TaskModelInfo(
            device_name = version_info.device_name,
            version_pk = version_pk,
            version_major = version_info.version_major,
            version_minor= version_info.version_minor,
            task_models= TaskModelsByName.model_validate(task_models_by_name),
        )

    def get_version_token_consumption(self,version_pk:int)->PreprocessingTokenConsumptionRecord:
        with self._read_transaction():
            version_info = self.get_version_info(version_pk)

            row = self.connection.execute(
                """
                SELECT token_consumption
                FROM preprocessing_versions
                WHERE version_pk = ?
                LIMIT 1
                """,
                (version_pk,),
            ).fetchone()

            if row is None:
                raise LookupError(
                    f"Token consumption not found: version_pk={version_pk}"
                )

        return PreprocessingTokenConsumptionRecord(
            device_name = version_info.device_name,
            version_pk = version_pk,
            version_major = version_info.version_major,
            version_minor = version_info.version_minor,
            token_consumption=PreprocessingTokenConsumption.model_validate_json(
                row["token_consumption"]
            ),
        )

    def get_version_pk(self,device_name: str,version_major:int,version_minor:int)->int:
        row = self.connection.execute(
            """
            SELECT version_pk
            FROM preprocessing_versions
            WHERE device_name = ?
                AND version_major = ?
                AND version_minor = ?
            LIMIT 1
            """,
            (device_name,version_major,version_minor),
        ).fetchone()

        if row is None:
            raise LookupError(
                f"VersionInfo not found: "
                f"{device_name} v{version_major}.{version_minor}"
            )
        return row["version_pk"]

    def get_version_info(self,version_pk:int)->VersionInfo:
        row = self.connection.execute(
            """
            SELECT
                preprocessing_versions.device_name,
                preprocessing_versions.version_pk,
                preprocessing_versions.version_major,
                preprocessing_versions.version_minor,
                preprocessing_versions.input_pdf_sha256,
                documents.pdf_name,
                preprocessing_versions.pages_json_created_at,
                preprocessing_versions.register_map_created_at,
                preprocessing_versions.register_map_modified_at,
                preprocessing_versions.snapshot_created_at
            FROM preprocessing_versions
            JOIN documents
                ON documents.input_pdf_sha256 =
                   preprocessing_versions.input_pdf_sha256
            WHERE preprocessing_versions.version_pk = ?
            """,
            (version_pk,),
        ).fetchone()

        if row is None:
            raise LookupError(f"VersionInfo not found: \n version_pk {version_pk}")

        return VersionInfo.model_validate(dict(row))

    def _device_exists(self, device_name: str) -> bool:
        row = self.connection.execute(
            "SELECT 1 FROM devices WHERE device_name = ? LIMIT 1",
            (device_name,),
        ).fetchone()
        return row is not None

# Insert-tool
    def save_preprocessing_result(
            self,
            *,
            device_name: str,
            pdf_name:str,
            input_pdf_sha256: str,
            pages: list[dict[str,Any]],
            register_map: RegisterMapOutput,
            device_functions: DeviceFunctionOutput,
            snapshot: PreprocessorSnapshot,
            pages_created_at: str,
            register_map_created_at: str,
            snapshot_created_at: str,
            token_consumption: PreprocessingTokenConsumption,
            task_models: TaskModelsByName | dict[str, str],
    ) -> OperationFeedback:

        device_name = device_name.strip()

        register_map = RegisterMapOutput.model_validate(register_map)
        device_functions = DeviceFunctionOutput.model_validate(device_functions)
        snapshot = PreprocessorSnapshot.model_validate(snapshot)
        token_consumption = PreprocessingTokenConsumption.model_validate(
            token_consumption
        )
        task_models = TaskModelsByName.model_validate(task_models)

        pages_json = json.dumps(
            pages,
            ensure_ascii=False,
            separators=(",", ":"),
            allow_nan=False,
        )
        register_map_json = json.dumps(
            register_map.model_dump(mode="json"),
            ensure_ascii=False,
            separators=(",", ":"),
            allow_nan=False,
        )
        device_functions_json = json.dumps(
            device_functions.model_dump(mode="json"),
            ensure_ascii=False,
            separators=(",", ":"),
            allow_nan=False,
        )
        snapshot_json = json.dumps(
            snapshot.model_dump(mode="json"),
            ensure_ascii=False,
            separators=(",", ":"),
            allow_nan=False,
        )
        token_consumption_json = json.dumps(
            token_consumption.model_dump(mode="json"),
            ensure_ascii=False,
            separators=(",", ":"),
            allow_nan=False,
        )

        task_model_set = []

        for task_name, model_name in task_models.model_dump(mode="json").items():
            task_model_set.append(
                (
                    task_name.strip(),
                    model_name.strip(),
                )
            )

        with self._write_operation("save_preprocessing_result") as operation_id:
            # devices
            self.connection.execute(
                "INSERT OR IGNORE INTO devices (device_name) VALUES (?)",
                (device_name,),
            )

            version_major, version_minor = self._get_next_version(
                device_name,
                input_pdf_sha256,
                task_model_set,
            )

            # documents
            self.connection.execute(
                """
                INSERT INTO documents (
                    input_pdf_sha256,
                    pdf_name
                )
                VALUES (?, ?)
                
                ON CONFLICT(input_pdf_sha256) DO UPDATE
                SET pdf_name = excluded.pdf_name
                WHERE documents.pdf_name IS NOT excluded.pdf_name
                """,
                (
                    input_pdf_sha256,
                    pdf_name,
                ),
            )

            cursor = self.connection.execute(
                """
                INSERT INTO preprocessing_versions (
                    device_name,
                    version_major,
                    version_minor,
                    input_pdf_sha256,
                    pages_json,
                    pages_json_created_at,
                    register_map_json,
                    register_map_created_at,
                    register_map_modified_at,
                    snapshot_json,
                    snapshot_created_at,
                    token_consumption,
                    device_functions
                ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
                """,
                (
                    device_name,
                    version_major,
                    version_minor,
                    input_pdf_sha256,
                    pages_json,
                    pages_created_at,
                    register_map_json,
                    register_map_created_at,
                    register_map_created_at,
                    snapshot_json,
                    snapshot_created_at,
                    token_consumption_json,
                    device_functions_json,
                ),
            )
            version_pk = cursor.lastrowid

            self.connection.executemany(
                """
                INSERT INTO task_models (
                    version_pk,
                    task_name,
                    model_name
                ) VALUES (?, ?, ?)
                """,
                (
                    (version_pk, task_name, model_name)
                    for task_name, model_name in task_model_set
                ),
            )

        version_info = self.get_version_info(version_pk)

        return OperationFeedback(
            operation_name="save_preprocessing_result",
            operation_id=operation_id,
            succeeded=True,
            details=version_info
        )


# Update-tools
    def update_register_map_field(
            self,
            version_pk: int,
            json_path: str,
            new_value: Any,
    ) -> OperationFeedback:

        json_path = json_path.strip()
        if not json_path:
            raise ValueError("json_path must not be empty")
        if json_path == "$":
            raise ValueError("the whole register_map_json cannot be replaced")

        new_value_json = json.dumps(
            new_value,
            ensure_ascii=False,
            separators=(",", ":"),
            allow_nan=False,
        )

        with self._write_operation("update_register_map_field", json_path=json_path, ) as operation_id:
            row = self.connection.execute(
                """
                SELECT
                    device_name,
                    version_major,
                    version_minor,
                    register_map_json,
                    json_type(register_map_json, ?) AS value_type,
                    json_extract(register_map_json, ?) AS old_value,
                    json_set(register_map_json, ?, json(?)) AS updated_json
                FROM preprocessing_versions
                WHERE version_pk = ?
                """,
                (json_path, json_path, json_path, new_value_json, version_pk,),
            ).fetchone()

            if row is None:
                raise LookupError(f"VersionInfo not found: version_pk={version_pk}")
            if row["value_type"] is None:
                raise LookupError(f"JSON path not found: {json_path}")

            RegisterMapOutput.model_validate_json(row["updated_json"])

            changed = row["register_map_json"] != row["updated_json"]
            if changed:
                self.connection.execute(
                    """
                    UPDATE preprocessing_versions
                    SET
                        register_map_json = ?,
                        register_map_modified_at = strftime(
                            '%Y-%m-%dT%H:%M:%fZ',
                            'now'
                        )
                    WHERE version_pk = ?
                    """,
                    (row["updated_json"], version_pk),
                )

        version_info = self.get_version_info(version_pk)

        return OperationFeedback(
            operation_name="update_register_map_field",
            operation_id=operation_id,
            details={
                "device_name": version_info.device_name,
                "version_pk": version_pk,
                "version_major": version_info.version_major,
                "version_minor": version_info.version_minor,
                "changed": changed,
                "modified_at":version_info.register_map_modified_at,
                "json_path": json_path,
                "old_value": row["old_value"],
                "new_value": new_value,
            }
        )

    def reassign_version_identity(
            self,
            version_pk: int,
            *,
            device_name: str | None = None,
            version_major: int | None = None,
            version_minor: int | None = None,
    ) -> OperationFeedback:

        if not isinstance(version_pk, int) or isinstance(version_pk, bool):
            raise TypeError("version_pk must be an integer")
        if version_pk < 1:
            raise ValueError("version_pk must be greater than or equal to 1")

        if device_name is not None:
            if not isinstance(device_name, str):
                raise TypeError("device_name must be a string")
            device_name = device_name.strip()
            if not device_name:
                raise ValueError("device_name must not be empty")

        if version_major is not None:
            if not isinstance(version_major, int) or isinstance(version_major, bool):
                raise TypeError("version_major must be an integer")
            if version_major < 1:
                raise ValueError("version_major must be greater than or equal to 1")

        if version_minor is not None:
            if not isinstance(version_minor, int) or isinstance(version_minor, bool):
                raise TypeError("version_minor must be an integer")
            if version_minor < 0:
                raise ValueError("version_minor must be greater than or equal to 0")

        with self._write_operation("reassign_version_identity") as operation_id:

            version_info = self.get_version_info(version_pk)

            new_device_name = (
                version_info.device_name if device_name is None else device_name
            )
            new_version_major = (
                version_info.version_major if version_major is None else version_major
            )
            new_version_minor = (
                version_info.version_minor if version_minor is None else version_minor
            )

            if not self._device_exists(new_device_name):
                raise LookupError(f"Device not found: {new_device_name}")

            changed = (
                    version_info.device_name != new_device_name
                    or version_info.version_major != new_version_major
                    or version_info.version_minor != new_version_minor
            )

            if changed:
                self.connection.execute(
                    """
                    UPDATE preprocessing_versions
                    SET
                        device_name = ?,
                        version_major = ?,
                        version_minor = ?
                    WHERE version_pk = ?
                    """,
                    (
                        new_device_name,
                        new_version_major,
                        new_version_minor,
                        version_pk,
                    ),
                )

        return OperationFeedback(
            operation_name="reassign_version_identity",
            operation_id=operation_id,
            details={
                "changed": changed,
                "old_device_name": version_info.device_name,
                "new_device_name": new_device_name,
                "old_version_major": version_info.version_major,
                "new_version_major": new_version_major,
                "old_version_minor": version_info.version_minor,
                "new_version_minor": new_version_minor,
            }
        )

# Delete-tools
    def delete_version(self, version_pk: int) -> OperationFeedback:
        with self._write_operation("delete_version") as operation_id:
            row = self.connection.execute(
                """
                SELECT device_name, version_major, version_minor
                FROM preprocessing_versions
                WHERE version_pk = ?
                """,
                (version_pk,),
            ).fetchone()

            if row is None:
                raise LookupError(f"VersionInfo not found: version_pk={version_pk}")

            newer_version = self.connection.execute(
                """
                SELECT version_minor
                FROM preprocessing_versions
                WHERE device_name = ?
                  AND version_major = ?
                  AND version_minor > ?
                ORDER BY version_minor DESC
                LIMIT 1
                """,
                (
                    row["device_name"],
                    row["version_major"],
                    row["version_minor"],
                ),
            ).fetchone()

            if newer_version is not None:
                raise ValueError(
                    f"Only the latest minor version in a major version can be deleted.\n"
                    f"Latest minor version in this major version: {newer_version["version_minor"]}"
                )

            versions_in_major = self.connection.execute(
                """
                SELECT COUNT(*) AS version_count
                FROM preprocessing_versions
                WHERE device_name = ? AND version_major = ?
                """,
                (row["device_name"], row["version_major"]),
            ).fetchone()["version_count"]

            if versions_in_major == 1:
                deletion = self._delete_major_version(
                    row["device_name"],
                    row["version_major"],
                )
                renumbered_major_versions = deletion.renumbered_major_versions
            else:
                self.connection.execute(
                    "DELETE FROM preprocessing_versions WHERE version_pk = ?",
                    (version_pk,),
                )
                renumbered_major_versions = []

        return OperationFeedback(
            operation_name="delete_version",
            operation_id=operation_id,
            succeeded=True,
            details={
                "device_name": row["device_name"],
                "version_pk": version_pk,
                "version_major": row["version_major"],
                "version_minor": row["version_minor"],
                "renumbered_major_versions": renumbered_major_versions,
            }
        )

    def delete_major_version(self, device_name: str, version_major: int) -> OperationFeedback:
        with self._write_operation("delete_major_version") as operation_id:
            deletion = self._delete_major_version(device_name, version_major)

        return OperationFeedback(
            operation_name="delete_major_version",
            operation_id=operation_id,
            details={
                "device_name": device_name,
                "deleted_version_major": version_major,
                "deleted_versions": deletion.deleted_versions,
                "renumbered_major_versions": deletion.renumbered_major_versions,
            }
        )

    def delete_device(self, device_name: str, ) -> OperationFeedback:
        with self._write_operation("delete_device") as operation_id:
            if not self._device_exists(device_name):
                raise LookupError(f"Device not found: {device_name}")

            counts = self.connection.execute(
                """
                SELECT
                    COUNT(DISTINCT preprocessing_versions.version_major) AS version_major_count
                FROM devices
                LEFT JOIN preprocessing_versions
                    ON preprocessing_versions.device_name = devices.device_name
                WHERE devices.device_name = ?
                """,
                (device_name,),
            ).fetchone()

            self.connection.execute(
                "DELETE FROM devices WHERE device_name = ?",
                (device_name,),
            )

        return OperationFeedback(
            operation_name="delete_device",
            operation_id=operation_id,

            details={
                "device_name": device_name,
                "deleted_major_versions": counts["version_major_count"]
            }
        )

# Private Methods
    def _get_next_version(
            self,
            device_name: str,
            pdf_sha256: str,
            task_models: list[tuple[str, str]],
    ) -> tuple[int, int]:

        try:
            latest_version = self.get_latest_version(device_name)
            version_major = latest_version.version_major
            version_minor = latest_version.version_minor
        except LookupError:
            return 1, 0

        new_task_model_map = {
            task_name: model_name
            for task_name, model_name in task_models
        }

        current_task_models = self.get_major_version_task_models(
            device_name,
            version_major,
        ).task_models.model_dump()

        pdf_repeated = self._pdf_exists_in_major(
            device_name,
            version_major,
            pdf_sha256,
        )

        models_changed = new_task_model_map != current_task_models

        if pdf_repeated or models_changed:
            return version_major + 1, 0

        return version_major, version_minor + 1

    def _delete_major_version(
            self,
            device_name: str,
            version_major: int,
    ) -> MajorVersionDeletionRecord:
        version_count = self.connection.execute(
            """
            SELECT COUNT(*) AS version_count
            FROM preprocessing_versions
            WHERE device_name = ? AND version_major = ?
            """,
            (device_name, version_major),
        ).fetchone()["version_count"]

        if version_count == 0:
            raise LookupError(
                f"Major version not found: {device_name} v{version_major}"
            )

        self.connection.execute(
            """
            DELETE FROM preprocessing_versions
            WHERE device_name = ? AND version_major = ?
            """,
            (device_name, version_major),
        )

        return MajorVersionDeletionRecord(
            deleted_versions=version_count,
            renumbered_major_versions=self._renumber_major_versions_after(device_name,version_major),
        )

    def _renumber_major_versions_after(self, device_name: str, deleted_version_major: int, ) -> list[RenumberedMajorVersion]:
        rows = self.connection.execute(
            """
            SELECT DISTINCT version_major
            FROM preprocessing_versions
            WHERE device_name = ? AND version_major > ?
            ORDER BY version_major
            """,
            (device_name, deleted_version_major),
        ).fetchall()

        renumbered = []
        for row in rows:
            old_version_major = row["version_major"]
            new_version_major = old_version_major - 1

            self.connection.execute(
                """
                UPDATE preprocessing_versions
                SET version_major = ?
                WHERE device_name = ? AND version_major = ?
                """,
                (new_version_major, device_name, old_version_major),
            )
            renumbered.append(
                RenumberedMajorVersion(
                    old_version_major=old_version_major,
                    new_version_major=new_version_major,
                )
            )

        return renumbered

    def _pdf_exists_in_major(self, device_name: str, version_major: int, pdf_sha256: str) -> bool:
        row = self.connection.execute(
            """
            SELECT 1
            FROM preprocessing_versions
            WHERE device_name = ?
              AND version_major = ?
              AND input_pdf_sha256 = ?
            LIMIT 1
            """,
            (device_name, version_major, pdf_sha256),
        ).fetchone()
        return row is not None

    @contextmanager
    def _write_operation(self, operation_name: str, *, json_path: str | None = None) -> Iterator[str]:
        operation_name = operation_name.strip()
        if not operation_name:
            raise ValueError("operation_name must not be empty")
        if self.connection.in_transaction:
            raise RuntimeError("A database transaction is already active")
        if json_path is not None:
            json_path = json_path.strip()

            if not json_path:
                raise ValueError("json_path must not be empty")

        operation_id = str(uuid4())
        self._current_operation_id = operation_id
        self._current_operation_name = operation_name
        self._current_json_path = json_path

        try:
            self.connection.execute("BEGIN IMMEDIATE")
            yield operation_id
        except BaseException:
            if self.connection.in_transaction:
                self.connection.rollback()
            raise
        else:
            self.connection.commit()
        finally:
            self._current_operation_id = None
            self._current_operation_name = None
            self._current_json_path = None

    @contextmanager
    def _read_transaction(self) -> Iterator[None]:
        owns_transaction = not self.connection.in_transaction
        if owns_transaction:
            self.connection.execute("BEGIN")
        try:
            yield
        except Exception:
            if owns_transaction and self.connection.in_transaction:
                self.connection.rollback()
            raise
        else:
            if owns_transaction:
                self.connection.commit()

    def _close(self) -> None:
        if self._connection is not None:
            self._connection.close()
            self._connection = None

    def _check_table_fields(self):
        for table, expected_field in EXPECTED_COLUMNS.items():
            rows = self.connection.execute(
                f'PRAGMA table_info("{table}")'
            ).fetchall()

            actual = tuple(row["name"] for row in rows)

            if actual and actual != expected_field:
                raise SchemaMismatchError(
                    f"{table}: expected {expected_field}, got {actual}"
                )

    def _check_triggers(self):
        rows = self.connection.execute(
            "SELECT name FROM sqlite_master WHERE type = 'trigger'"
        ).fetchall()

        actual = {row["name"] for row in rows}
        missing = set(EXPECTED_TRIGGERS) - actual

        if missing:
            raise SchemaMismatchError(
                f"Missing audit triggers: {sorted(missing)}"
            )

    def __enter__(self) -> DataManager:
        self.connect()
        try:
            self.initialize()
        except Exception:
            self._close()
            raise
        return self

    def __exit__(self, exc_type, exc_value, traceback) -> None:
        self._close()
