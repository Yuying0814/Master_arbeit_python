from __future__ import annotations

import re
import warnings
from typing import Any


NORMAL_PATTERNS = [
    r"\bregisters?\s+maps?\b",
    r"\bregisters?\s+descriptions?\b",
    r"\bregisters?\s+definitions?\b",
    r"\bregisters?\s+summar(?:y|ies)\b",
    r"\bregisters?\s+lists?\b",
    r"\bregisters?\s+tables?\b",
    r"\bregisters?\s+addresses?\b",
    r"\baddress\s+maps?\b",
    r"\bmemory\s+maps?\b",
    r"\bbits?\s+fields?\b",
    r"\bfields?\s+descriptions?\b",
    r"\bregisters?\s+overview\b",
    r"\bregisters?\s+reference\b",
    r"\bregisters?\b",
    r"\breg\b",
    r"\breg\.",
]


SUMMARY_PATTERNS = [
    r"\bregisters?\s+maps?\b",
    r"\bregisters?\s+descriptions?\b",
    r"\bregisters?\s+definitions?\b",
    r"\bregisters?\s+summar(?:y|ies)\b",
    r"\bregisters?\s+lists?\b",
    r"\bregisters?\s+tables?\b",
    r"\bmemory\s+maps?\b",
]


def resolve_toc_entries(toc_entries: list[dict[str, Any]]) -> tuple[list[int], list[int]]:

    if not toc_entries:
        return [], []

    reg_page_indices = find_page_range(toc_entries, NORMAL_PATTERNS)
    reg_sum_indices = find_exact_pages(toc_entries, SUMMARY_PATTERNS)

    return reg_page_indices, reg_sum_indices


def find_page_range(toc_entries: list[dict[str, Any]],patterns: list[str]) -> list[int]:

    keep_lines = [False] * len(toc_entries)
    contents = _build_search_contents(toc_entries)

    current_index = 0

    while current_index < len(toc_entries):
        current_content = contents[current_index]
        current_level = int(toc_entries[current_index]["section_level"])

        matched = _matches_any_pattern(current_content, patterns)

        if matched:
            keep_lines[current_index] = True

            # Level-0 entries are kept only when directly matched.
            if current_level == 0:
                current_index += 1
                continue

            if current_index == len(toc_entries) - 1:
                break

            # Use the matched entry as an anchor and keep its subsections.
            anchor_level = current_level
            current_index += 1

            while current_index < len(toc_entries):
                next_level = int(toc_entries[current_index]["section_level"])

                # Level-0 entries inside an anchored range are retained.
                if next_level == 0:
                    keep_lines[current_index] = True
                    current_index += 1
                    continue

                # Stop at a same-level or higher-level section.
                if next_level <= anchor_level:
                    break

                keep_lines[current_index] = True
                current_index += 1

        else:
            current_index += 1

    return _resolve_marked_entries_to_pages(toc_entries, keep_lines)


def find_exact_pages(toc_entries: list[dict[str, Any]],patterns: list[str],) -> list[int]:
    keep_lines = [False] * len(toc_entries)
    contents = _build_search_contents(toc_entries)

    for index, content in enumerate(contents):
        if _matches_any_pattern(content, patterns):
            keep_lines[index] = True

    return _resolve_marked_entries_to_pages(toc_entries, keep_lines)


def _build_search_contents(toc_entries: list[dict[str, Any]]) -> list[str]:
    contents: list[str] = []

    for entry in toc_entries:
        content = str(entry.get("content", ""))
        continuation_lines = str(entry.get("continuation_lines", ""))
        contents.append(f"{content}\n{continuation_lines}".casefold())

    return contents


def _matches_any_pattern(text: str, patterns: list[str]) -> bool:
    return any(re.search(pattern, text) is not None for pattern in patterns)


def _resolve_marked_entries_to_pages(toc_entries: list[dict[str, Any]],keep_lines: list[bool],) -> list[int]:
    if not any(keep_lines):
        return []

    segments = _find_true_segments(keep_lines)

    start_pages: list[int] = []
    end_pages: list[int] = []

    for start_index, end_index in segments:
        start_page = _to_int_page_number(toc_entries[start_index]["page_number"])

        if end_index < len(toc_entries) - 1:
            end_page = _to_int_page_number(toc_entries[end_index + 1]["page_number"])
        else:
            end_page = _to_int_page_number(toc_entries[end_index]["page_number"])

        if end_page < start_page:
            warnings.warn("Some page ranges had end_page < start_page.",RuntimeWarning,)
            end_page = start_page

        start_pages.append(start_page)
        end_pages.append(end_page)

    page_numbers: list[int] = []

    for start_page, end_page in zip(start_pages, end_pages):
        page_numbers.extend(range(start_page, end_page + 1))

    return sorted(set(page_numbers))


def _find_true_segments(mask: list[bool]) -> list[tuple[int, int]]:
    segments: list[tuple[int, int]] = []
    start_index: int | None = None

    for index, value in enumerate(mask):
        if value and start_index is None:
            start_index = index

        if not value and start_index is not None:
            segments.append((start_index, index - 1))
            start_index = None

    if start_index is not None:
        segments.append((start_index, len(mask) - 1))

    return segments


def _to_int_page_number(value: Any) -> int:
    return int(str(value).strip())