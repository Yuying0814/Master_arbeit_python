
from __future__ import annotations

from dataclasses import dataclass, field
from typing import Any


@dataclass
class page:
    index:int
    markdown:str
    tables:list[dict[str, Any]] = field(default_factory=list)

    @classmethod
    def from_dict(cls,data: dict) -> page:
        return cls(
            index = int(data["index"]),
            markdown = data.get("markdown", ""),
            tables = data.get("tables", []),
        )
    def to_dict(self) -> dict:
        return{
            'index' : self.index,
            'markdown' : self.markdown,
            'tables' : self.tables
        }

def pages_from_ocr(ocr_data: dict) -> list[page]:
    raw_pages = ocr_data["pages"]
    return [page.from_dict(page_dict) for page_dict in raw_pages]