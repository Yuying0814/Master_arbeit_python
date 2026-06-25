from __future__ import annotations

import json
import traceback
from contextlib import contextmanager
from datetime import datetime, timezone
from pathlib import Path
from typing import Any
from collections.abc import Iterator


class EventRecorder:

    def __init__(self, driver_name: str, output_dir: Path) -> None:
        self.record_step = 0
        self.driver_name = driver_name
        self.output_dir = Path(output_dir)
        self.events: list[dict[str, Any]] = []

    def emit(
            self,
            agent: str,
            action: str,
            status: str,
            *,
            attempt: int | None = None,
            payload: Any | None = None,
            error: BaseException | None = None,
    ) -> None:
        event = {
            "record_step":self.record_step,
            "driver_name": self.driver_name,
            "agent": agent,
            "action": action,
            "status": status,
            "attempt": attempt,
            "payload": self._to_jsonable(payload),
            "error": None,
        }

        if error is not None:
            event["error"] = {
                "type": type(error).__name__,
                "message": str(error),
                "traceback": traceback.format_exc(),
            }

        self.events.append(event)
        self.record_step += 1

    @contextmanager
    def step(
            self,
            agent: str,
            action: str,
            *,
            attempt: int | None = None,
            payload: Any | None = None,
    ) -> Iterator[None]:

        self.emit(
            agent=agent,
            action=action,
            status="started",
            attempt=attempt,
            payload=payload,
        )

        try:
            yield
        except Exception as exc:
            self.emit(
                agent=agent,
                action=action,
                status="error",
                attempt=attempt,
                error=exc,
            )
            raise

        self.emit(
            agent=agent,
            action=action,
            status="completed",
            attempt=attempt,
        )

    def write(self, status: str) -> Path:
        self.output_dir.mkdir(parents=True, exist_ok=True)

        output_path = self.output_dir / "events.json"
        output = {
            "driver_name": self.driver_name,
            "status": status,
            "event_count": len(self.events),
            "written_at": datetime.now(timezone.utc).isoformat(),
            "events": self.events,
        }

        output_path.write_text(
            json.dumps(output, ensure_ascii=False, indent=2),
            encoding="utf-8",
        )

        print(f"Event logs written to: {output_path}")
        return output_path

    def _to_jsonable(self, value: Any) -> Any:
        if value is None:
            return None

        if hasattr(value, "model_dump"):
            return value.model_dump(mode="json")

        if isinstance(value, Path):
            return str(value)

        if isinstance(value, dict):
            return {
                str(key): self._to_jsonable(item)
                for key, item in value.items()
            }

        if isinstance(value, list):
            return [
                self._to_jsonable(item)
                for item in value
            ]

        try:
            json.dumps(value)
            return value
        except TypeError:
            return repr(value)