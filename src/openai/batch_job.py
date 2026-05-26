from dataclasses import dataclass,field
from pathlib import Path
from typing import Any


@dataclass
class BatchJob:
    name:str
    input_path:Path
    custom_ids:list[str]
    batch_id:str = ""
    input_file_id:str = ""
    output_file_id:str = ""
    error_file_id:str = ""
    status:str = "created"
    batch_info:dict = field(default_factory=dict)

    def update(self, **opts: Any) -> None:

        if "batch_id" in opts:
            if not isinstance(opts["batch_id"], str):
                raise TypeError("batch_id must be a string.")
            self.batch_id = opts["batch_id"]

        if "input_file_id" in opts:
            if not isinstance(opts["input_file_id"], str):
                raise TypeError("input_file_id must be a string.")
            self.input_file_id = opts["input_file_id"]

        if "output_file_id" in opts:
            if not isinstance(opts["output_file_id"], str):
                raise TypeError("output_file_id must be a string.")
            self.output_file_id = opts["output_file_id"]

        if "error_file_id" in opts:
            if not isinstance(opts["error_file_id"], str):
                raise TypeError("error_file_id must be a string.")
            self.error_file_id = opts["error_file_id"]

        if "status" in opts:
            if not isinstance(opts["status"], str):
                raise TypeError("status must be a string.")
            self.status = opts["status"]

        if "batch_info" in opts:
            if not isinstance(opts["batch_info"], dict):
                raise TypeError("batch_info must be a dictionary.")
            self.update_batch_info(opts["batch_info"])

    def update_batch_info(self,batch_info:dict) -> None:
        self.batch_info = batch_info

        if "status" in batch_info and batch_info["status"]:
            self.update(status=str(batch_info["status"]))

        if "output_file_id" in batch_info and batch_info["output_file_id"]:
            self.update(output_file_id=str(batch_info["output_file_id"]))

        if "error_file_id" in batch_info and batch_info["error_file_id"]:
            self.update(error_file_id=str(batch_info["error_file_id"]))

    def is_terminal(self) -> bool:
        return self.status in {"completed", "failed", "cancelled", "expired"}

    def is_completed(self) -> bool:
        return self.status == "completed"

    def is_failed(self) -> bool:
        return self.status in {"failed", "cancelled", "expired"}

    def is_running(self) -> bool:
        return not self.is_terminal() and self.status != "created"

    def has_output(self) -> bool:
        return len(self.output_file_id) > 0

    def has_error_file(self) -> bool:
        return len(self.error_file_id) > 0