from __future__ import annotations

import math
import re
from typing import Any

from src.preprocessing.toc.toc_detection import detect_toc_entry, detect_toc_title
from src.preprocessing.utils.text_utils import text_to_lines,extract_text_from_page


def find_toc_pages(pages: list[Any], threshold: float = 0.2) -> list[Any]:
    if not pages:
        raise ValueError("No pages input.")

    n_pages = len(pages)
    title_page_index: int | None = None
    has_title = False

    fixed_buffer: list[str | None] = [None] * n_pages
    scores: list[float] = [0.0] * n_pages

    search_range = _build_toc_search_range(n_pages)

    for page_index in search_range:
        page_text = extract_text_from_page(pages[page_index])
        lines = text_to_lines(page_text)

        is_title_page = False
        toc_title_line_index: int | None = None

        if not has_title:
            title_matches = [detect_toc_title(line) for line in lines]

            if any(title_matches):
                has_title = True
                is_title_page = True
                toc_title_line_index = title_matches.index(True)
                title_page_index = page_index

        used_lines = lines
        toc_like_count = count_toc_like_lines(used_lines)

        prefixed_lines = prefix_toc_lines(used_lines, toc_title_line_index)
        prefixed_count = count_toc_like_lines(prefixed_lines)

        if toc_like_count < prefixed_count:
            used_lines = prefixed_lines
            toc_like_count = prefixed_count
            fixed_buffer[page_index] = "\n".join(prefixed_lines) + "\n"

        score = 0.0

        if is_title_page:
            score += 1.0

        if used_lines:
            score += toc_like_count / len(used_lines)

        scores[page_index] = score

    toc_indices = find_best_segment(scores, threshold)

    if toc_indices:
        if title_page_index is not None:
            toc_indices = [
                index for index in toc_indices
                if index >= title_page_index
            ]

        if toc_indices:
            next_page_index = toc_indices[-1] + 1

            if next_page_index < n_pages and scores[next_page_index] > 0:
                toc_indices.append(next_page_index)

    for page_index in toc_indices:
        fixed_markdown = fixed_buffer[page_index]

        if fixed_markdown is not None:
            pages[page_index]["markdown"] = fixed_markdown

    toc_index_set = set(toc_indices)

    for page_index, page in enumerate(pages):
        _set_page_toc_result(
            page=page,
            is_toc=page_index in toc_index_set,
            score=scores[page_index],
        )

    return pages


def _build_toc_search_range(n_pages: int) -> list[int]:
    first_end = math.ceil(0.2 * n_pages)
    last_start = max(math.ceil(0.8 * n_pages) - 1, 0)

    candidate_indices = [
        *range(0, first_end),
        *range(last_start, n_pages),
    ]

    return list(dict.fromkeys(candidate_indices))


def find_best_segment(scores: list[float], threshold: float) -> list[int]:
    if not scores:
        return []

    adjusted_scores = [score - threshold for score in scores]

    current_start = 0
    best_start = 0
    best_end = 0

    current_sum = adjusted_scores[0]
    best_sum = adjusted_scores[0]

    for index in range(1, len(adjusted_scores)):
        if current_sum < 0:
            current_sum = adjusted_scores[index]
            current_start = index
        else:
            current_sum += adjusted_scores[index]

        if current_sum > best_sum:
            best_sum = current_sum
            best_start = current_start
            best_end = index

    if best_sum >= 0:
        return list(range(best_start, best_end + 1))

    return []


def count_toc_like_lines(lines: list[str]) -> int:
    page_numbers: list[int] = []

    for line in lines:
        if not detect_toc_entry(line):
            continue

        match = re.search(r"(\d+)\s*$", line)

        if match is None:
            continue

        page_numbers.append(int(match.group(1)))

    if len(page_numbers) <= 1:
        return len(page_numbers)

    monotonic_count = 0

    for previous_page, current_page in zip(page_numbers, page_numbers[1:]):
        if current_page >= previous_page:
            monotonic_count += 1

    monotonic_ratio = monotonic_count / (len(page_numbers) - 1)

    return math.floor(len(page_numbers) * monotonic_ratio + 0.5)


def prefix_toc_lines(lines: list[str],matched_line_index: int | None,) -> list[str]:
    fixed_lines = lines.copy()

    start_index = 0

    if matched_line_index is not None:
        start_index = matched_line_index + 1

    for index in range(start_index, len(fixed_lines) - 1):
        this_line = fixed_lines[index]

        if not this_line:
            continue

        next_line = fixed_lines[index + 1]

        if (
            not detect_toc_entry(this_line)
            and not detect_toc_entry(next_line)
        ):
            merged_line = f"{this_line} ... {next_line}"

            if detect_toc_entry(merged_line):
                fixed_lines[index] = merged_line
                fixed_lines[index + 1] = ""

    return [line for line in fixed_lines if line]

def _set_page_toc_result(page: Any, is_toc: bool, score: float) -> None:
    result = {
        "is_toc": is_toc,
        "score": score,
    }

    page["result_toc"] = result
    return