from __future__ import annotations
import re

_TOC_EXCLUSIONS = (
    r"(?!\d+(?:\.\d+)*$)"
    r"(?!.*\d+\s*[/|]\s*\d+$)"
    r"(?!.*\d+\s+of\s+\d+$)"
    r"(?!#*\s*.+\s+\d+\s*(?:[/|]\s*\d+|of\s+\d+)$)"
    r"(?!.*(?:19|20)\d{2}\s*$)"
    r"(?!.*(?:pages?|figures?|tables?)\s*\d+$)"
    r"(?!.*(?:pages?|figures?|tables?)\s*\d+\s+of\s+\d+\s*$)"
    r"(?!.*=\s*\d+\s*$)"
    r"(?!.*\d{3}\s+\d{3}\s+\d{3}\s*$)"
    r"(?!.*(?<!\w)(?:add(?:ed)?|change[ds]?|deleted?)(?!\w))"
    r"(?!.*(?<!\w)(?:figures?\s+\d+|tables?\s+\d+)(?!\w))"
    r"(?!#*\s*(?:table|figure)\s+\d+\b)"
    r"(?!\s*-\s*(?:table|figure)\s+\d+\b)"
    r"(?!.*,(?:\s*|\.{2,}\s*)\d+$)"
)

_NUMBERED_TOC_ENTRY_PATTERN = re.compile(
    r"^"
    + _TOC_EXCLUSIONS
    + r"#*\s*\d+(?:\.\d+)*\.?\s+.+?(?:\s|\.{2,}\s*)\d+$"
)

_UNNUMBERED_TOC_ENTRY_PATTERN = re.compile(
    r"^"
    + _TOC_EXCLUSIONS
    + r"(?!#*\s*(?:table|figure)\s+\d+\.?\s+.*(?:\s|\.{2,}\s*)\d+$)"
    + r"#*\s*(?!\d+(?:\.\d+)*\.?\s+)[^\s].*?(?:\s|\.{2,}\s*)\d+$"
)

_BULLET_TOC_ENTRY_PATTERN = re.compile(
    r"^"
    + _TOC_EXCLUSIONS
    + r"\s*-\s+[^\d].*?(?:\s+|\.{2,}\s*)\d+\s*$"
)

_TOC_TITLE_KEYWORDS = (
    "content",
    "contents",
    "list of contents",
    "table of contents",
    "index of contents",
    "toc",
    "contents overview",
    "inhalt",
    "inhalte",
    "verzeichnis",
    "inhaltsverzeichnis",
)

_TOC_TITLE_PATTERNS = tuple(
    re.compile(
        r"^(?!#*\s*(?:list of\s+)?(?:tables|figures|images?|illustrations)\s*$)"
        rf"#*\s*(?:\d+(?:\.\d+)*\.?\s*)?{re.escape(keyword)}\s*$"
    )
    for keyword in _TOC_TITLE_KEYWORDS
)


def detect_toc_entry(line: str) -> bool:
    line = line.strip().casefold()
    return (
        _NUMBERED_TOC_ENTRY_PATTERN.search(line) is not None
        or _UNNUMBERED_TOC_ENTRY_PATTERN.search(line) is not None
        or _BULLET_TOC_ENTRY_PATTERN.search(line) is not None
    )


def detect_toc_title(line: str) -> bool:
    line = line.strip().casefold()

    return any(
        pattern.search(line) is not None
        for pattern in _TOC_TITLE_PATTERNS
    )