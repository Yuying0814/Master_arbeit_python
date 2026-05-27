from __future__ import annotations
import re
import copy
import math
from collections import Counter
from bs4 import BeautifulSoup
##########################################################################################
def match_pattern(line: str, pattern: str | re.Pattern[str]) -> bool:
    return re.search(pattern, line) is not None

##########################################################################################
def text_to_lines(text: str) -> list[str]:
    normalized_text = re.sub(r"\r\n?", "\n", text)
    all_lines = normalized_text.split("\n")

    return [line for line in all_lines if line.strip()]

##########################################################################################
def extract_text_from_pages(pages: dict|list[dict]) -> str|list[str]:
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
        if len(texts) == 1:
            return str(texts)
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

##########################################################################################
def remove_header_footer(pages: list[dict]) -> list[dict]:
    if not pages:
        raise ValueError("No pages input.")

    out_pages = copy.deepcopy(pages)
    repeated_lines = find_repeated_lines(out_pages)

    for page in out_pages:
        if "markdown" not in page:
            raise ValueError("Missing field: markdown")

        text = page["markdown"]
        lines = text_to_lines(text)

        cleaned_lines: list[str] = []

        for line in lines:
            trimmed_line = line.strip()

            if trimmed_line in repeated_lines:
                continue

            if is_footer(line):
                continue

            cleaned_lines.append(line)

        page["markdown"] = "\n".join(cleaned_lines)

        if cleaned_lines:
            page["markdown"] += "\n"

    return out_pages


def find_repeated_lines(pages: list[dict]) -> set[str]:
    search_end = math.ceil(0.5 * len(pages))
    search_range = range(search_end)

    all_lines: list[str] = []

    for page_index in search_range:
        page = pages[page_index]

        if "markdown" not in page:
            raise ValueError("Missing field: markdown")

        text = page["markdown"]
        lines = text_to_lines(text)
        trimmed_lines = [line.strip() for line in lines]

        unique_lines = set(trimmed_lines)

        all_lines.extend(unique_lines)

    line_counts = Counter(all_lines)
    threshold = math.ceil(0.3 * len(pages))

    return {
        line
        for line, count in line_counts.items()
        if count > threshold
    }


def is_footer(line: str) -> bool:
    normalized_line = line.strip().casefold()

    pattern = r"^(?:(?:pages?|pg\.?|p\.?)\s*:?\s*)?(\d+)\s*(?:/|\||of)\s*(\d+)$"
    match = re.search(pattern, normalized_line)

    if match is None:
        return False

    current_page = int(match.group(1))
    total_pages = int(match.group(2))

    return (
        current_page >= 1
        and total_pages >= 1
        and current_page <= total_pages
    )
