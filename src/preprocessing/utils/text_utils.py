from __future__ import annotations
import re
from typing import Any
from bs4 import BeautifulSoup

def match_pattern(line: str, pattern: str | re.Pattern[str]) -> bool:
    return re.search(pattern, line) is not None


def text_to_lines(text: str) -> list[str]:
    normalized_text = re.sub(r"\r\n?", "\n", text)
    all_lines = normalized_text.split("\n")

    return [line for line in all_lines if line.strip()]

def extract_text_from_pages(pages: dict|list[dict]) -> list[str]:
    if not pages:
        raise ValueError("No pages")

    if isinstance(pages, dict):
        pages = [pages]

    required_fields = ("markdown", "tables", "index")
    texts:list[str] = []

    for page in pages:
        missing_fields = [field_name for field_name in required_fields if field_name not in page]

        if missing_fields:
            raise ValueError(f"Missing fields: {', '.join(missing_fields)}")

        text = page["markdown"]

        for table in page["tables"]:
            content = extract_html_text(table["content"])
            pattern = f"[{table['id']}]({table['id']})"
            text = text.replace(pattern,content)

        texts.append(text)
    return texts

def extract_html_text(html: str) -> str:
    soup = BeautifulSoup(html, "html.parser")

    rows: list[str] = []

    for row in soup.find_all("tr"):
        cells = row.find_all(["th", "td"])
        cell_texts = [
            cell.get_text(separator=" ", strip=True)
            for cell in cells
        ]
        if cell_texts:
            rows.append(" | ".join(cell_texts))
    if rows:
        return "\n".join(rows)

    return soup.get_text(separator=" ", strip=True)



