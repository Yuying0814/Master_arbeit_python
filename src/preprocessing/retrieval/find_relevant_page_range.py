from __future__ import annotations
import math
import re
from typing import Any

from src.preprocessing.utils.text_utils import extract_text_from_pages


def find_relevant_page_range(pages: list[dict[str, Any]],option: str = "register",) -> list[dict[str, Any]]:
    if not pages:
        raise ValueError("No pages input.")

    texts = extract_text_from_pages(pages)
    texts = [_normalize_page_text(text) for text in texts]

    word_counts = [
        len(re.findall(r"\S+", text))
        for text in texts
    ]

    keywords = select_keywords(option)

    title_freq_matrix = count_query_hits_by_page(keywords["title"],texts)
    title_counts = [sum(row)for row in title_freq_matrix]

    summary_page_indices = {index for index, count in enumerate(title_counts) if count > 0}

    feature_freq_matrix = count_query_hits_by_page(keywords["feature"],texts)

    page_scores = compute_bm25_score(feature_freq_matrix,word_counts)

    temp_ranges = select_ranges(page_scores)

    page_indices: set[int] = set()

    if temp_ranges:
        for page_range in temp_ranges:
            last_page_index = page_range[-1]

            if last_page_index + 1 < len(page_scores):
                if page_scores[last_page_index + 1] > 0:
                    page_range.append(last_page_index + 1)

        page_indices = {
            page_index
            for page_range in temp_ranges
            for page_index in page_range
        }

    for page_index, page in enumerate(pages):
        page["result_retrieval"] = {
            "BM25score": page_scores[page_index],
            "counts_reg_sum_keyword": title_counts[page_index],
            "is_reg_map_relevant": page_index in page_indices,
            "is_reg_sum_relevant": page_index in summary_page_indices,
        }

    return pages


def _normalize_page_text(text: str) -> str:
    text = text.casefold()
    text = re.sub(r"(?m)^\s*(#+|-)\s*", "", text)
    return text


def count_query_hits_by_page(query_patterns: list[str],all_texts: list[str]) -> list[list[int]]:
    return [
        count_query_hits(query_patterns, text)
        for text in all_texts
    ]


def count_query_hits(query_patterns: list[str],one_text: str,) -> list[int]:
    return [
        len(re.findall(pattern, one_text, flags=re.IGNORECASE))
        for pattern in query_patterns
    ]


def compute_inverse_document_frequency(freq_matrix: list[list[int]]) -> list[float]:

    if not freq_matrix:
        return []

    n_pages = len(freq_matrix)
    n_terms = len(freq_matrix[0])

    idf_values: list[float] = []

    for term_index in range(n_terms):
        doc_freq = sum(
            1
            for page_freqs in freq_matrix
            if page_freqs[term_index] > 0
        )

        idf = math.log(
            1 + (n_pages - doc_freq + 0.5) / (doc_freq + 0.5)
        )
        idf_values.append(idf)

    return idf_values


def compute_bm25_score(freq_matrix: list[list[int]],word_counts: list[int],) -> list[float]:
    if not freq_matrix:
        return []

    idf_values = compute_inverse_document_frequency(freq_matrix)

    avg_doc_length = sum(word_counts) / len(word_counts)

    if avg_doc_length == 0:
        avg_doc_length = 1

    k1 = 1.5
    b = 0.75

    page_scores: list[float] = []

    for page_index, page_freqs in enumerate(freq_matrix):
        doc_length = word_counts[page_index]
        length_norm = 1 - b + b * doc_length / avg_doc_length

        page_score = 0.0

        for term_index, frequency in enumerate(page_freqs):
            if frequency == 0:
                continue

            numerator = (k1 + 1) * idf_values[term_index] * frequency
            denominator = frequency + k1 * length_norm

            page_score += numerator / denominator

        page_scores.append(page_score)

    return page_scores


def select_keywords(option: str) -> dict[str, list[str]]:
    option = option.casefold().strip()
    match option:
        case "register":
            return {
                "title": [
                    r"reg\.?(?:isters?)\s+"
                    r"(?:maps?|mappings?|descriptions?|tables?|lists?|"
                    r"definitions?|overviews?|summar(?:y|ies)|references?)",

                    r"address(?:es)?\s+"
                    r"(?:maps?|mappings?|descriptions?|tables?|lists?|"
                    r"definitions?|overviews?|summar(?:y|ies)|references?)",

                    r"memory\s+map",
                ],
                "feature": [
                    r"\baddr\.?\b",
                    r"\baddress\b",
                    r"\bbank\b",
                    r"(?<!-)\bbits?(?:\s+|-\s*)(?:fields?|descriptions?)\b",
                    r"\bbits?\s*\d+(?:\s*-\s*\d+|\s*:\s*\d+)?",
                    r"\bbits?\b(?!\s*[-]?\s*(?:fields?|descriptions?))(?!\s*\d)",
                    r"(?<!\bbit )(?<!\bbits )(?<!\bbit-)(?<!\bbits-)"
                    r"(?<!\bbit- )(?<!\bbits- )\bfields?\b",
                    r"\breg\.?",
                    r"\bregisters?\b",
                    r"\bregisters?\s*names?\b",
                    r"\bregisters?\s*pointers?\b",
                    r"\bregisters?\s*addr(?:\.|ess(?:es)?)\b",
                    r"\bhex\b",
                    r"\bdecimal\b",
                    r"\bdec\.?\b",
                    r"initial value",
                    r"default value",
                    r"reset value",
                    r"\b(?:r\s*/\s*w|w\s*/\s*r|r\s*/\s*o|w\s*/\s*o|"
                    r"r\s*w|w\s*r|r\s*o|w\s*o|r|w)\b",
                    r"read\s*/\s*write",
                    r"write\s*/\s*read",
                    r"read only",
                    r"write only",
                    r"readable",
                    r"writable",
                    r"(?<!all rights )\breserved\b",
                    r"0x[0-9a-f]{2}",
                    r"\b[0-9a-f]{2}h\b",
                    r"\b(?:[01]{4}\s?)+\b",
                ],
            }
        case _:
            raise ValueError(f"Unsupported retrieval option: {option}")


def select_ranges(page_scores: list[float]) -> list[list[int]]:
    if not page_scores:
        return []

    max_score = max(page_scores)

    if max_score <= 0:
        return []

    max_low_score_gap = 2
    min_range_length = 2

    low_score_mask = [
        score < 0.2 * max_score
        for score in page_scores
    ]

    low_score_segments = _find_true_segments(low_score_mask)

    invalid_segments = [
        segment
        for segment in low_score_segments
        if segment[1] - segment[0] + 1 > max_low_score_gap
    ]

    page_ranges: list[list[int]] = []
    start_index = 0

    for invalid_start, invalid_end in invalid_segments:
        end_index = invalid_start - 1

        if start_index <= end_index:
            if end_index - start_index + 1 > min_range_length:
                page_ranges.append(
                    list(range(start_index, end_index + 1))
                )

        start_index = invalid_end + 1

    if len(page_scores) - start_index > min_range_length:
        page_ranges.append(
            list(range(start_index, len(page_scores)))
        )

    return page_ranges


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