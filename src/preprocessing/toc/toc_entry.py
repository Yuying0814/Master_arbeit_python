from __future__ import annotations

import re
from typing import Any

from src.preprocessing.toc.toc_detection import detect_toc_entry
from src.preprocessing.utils.text_utils import extract_text_from_pages
from src.preprocessing.utils.text_utils import text_to_lines


def extract_toc_entries(toc_pages: list[dict[str, Any]]) -> list[dict[str, Any]]:
    if not toc_pages:
        return []

    toc_entries: list[dict[str, Any]] = []
    all_lines: list[str] = []
    source_indices: list[int] = []

    previous_section_number = 0
    section_started = False
    continuation_lines = ""

    page_texts = extract_text_from_pages(toc_pages)

    for page, page_text in zip(toc_pages, page_texts):
        page_index = page["index"]
        lines = text_to_lines(page_text)

        all_lines.extend(lines)
        source_indices.extend([page_index] * len(lines))

    toc_mask = [detect_toc_entry(line) for line in all_lines]

    for line_index, line in enumerate(all_lines):
        if toc_mask[line_index]:
            page_match = re.search(r"(\d+)\s*$", line)
            content_match = re.search(r"(.*?)\s*\.*\s*\d+\s*$", line)

            if page_match is None or content_match is None:
                continue

            section_number, section_level = section_ident(line)

            if section_number == "1" and not section_started:
                section_started = True

            if section_started and section_level == 1:
                if is_valid_section_number(section_number,previous_section_number,):
                    if section_number:
                        previous_section_number = int(section_number)
                else:
                    section_number = ""
                    section_level = 0

            page_number = int(page_match.group(1))

            content = content_match.group(1)
            content = re.sub(r"^\s*(?:#+|-*)\s*", "", content)

            if section_number:
                section_pattern = rf"^\s*{re.escape(section_number)}\.?\s*"
                content = re.sub(section_pattern, "", content, count=1)

            content = content.strip()

            if continuation_lines and toc_entries:
                toc_entries[-1]["continuation_lines"] = continuation_lines
                continuation_lines = ""

            toc_entries.append(
                {
                    "section_level": section_level,
                    "section": section_number,
                    "content": content,
                    "page_number": page_number,
                    "continuation_lines": "",
                    "source_index": source_indices[line_index],
                }
            )

        elif toc_entries:
            continuation_lines += f"{line}\n"

    if continuation_lines and toc_entries:
        toc_entries[-1]["continuation_lines"] = continuation_lines

    return toc_entries


def section_ident(line: str) -> tuple[str, int]:
    section_number = ""

    stripped_line = line.strip()
    clean_line = re.sub(r"^\s*#+\s*", "", stripped_line)
    clean_line = re.sub(r"^\s*[-*]\s*", "", clean_line)

    section_match = re.search(r"^(\d+(?:\.\d+)*)\.?\s+", clean_line)

    if section_match is None:
        if re.search(r"^#", stripped_line) is not None:
            return "", 1

        return "", 0

    section_number = section_match.group(1)
    section_level = section_number.count(".") + 1

    first_number_match = re.search(r"^\d+", section_number)

    if first_number_match is None:
        return "", 0

    first_number = int(first_number_match.group(0))

    if first_number > 30:
        return "", 0

    return section_number, section_level


def is_valid_section_number(section_number: str,previous_section_number: int,) -> bool:
    if not section_number:
        return True

    first_number = int(section_number)

    return first_number == previous_section_number + 1