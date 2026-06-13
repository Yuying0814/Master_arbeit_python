import json
import math
import re
from typing import Any
from src.preprocessing.utils.text_utils import extract_text_from_page
from src.models.batch import UserRequest

def build_page_requests(
        request_name:str,
        all_pages:list[dict[str,Any]],
        candidate_pages:list[dict[str,Any]] = None)->list[UserRequest]:
    keep_keys = ("index","markdown","tables","classification")

    new_all_pages = [{key:page[key]for key in keep_keys if key in page} for page in all_pages]

    if candidate_pages is not None:
        new_candidate_pages = [{key:page[key]for key in keep_keys if key in page} for page in candidate_pages]
    else:
        new_candidate_pages = new_all_pages

    user_requests = []

    index_page_map = _build_index_page_map(new_all_pages)

    for index,page in enumerate(new_candidate_pages):
        if page["index"] == 0:
            previous_content = _get_page_tail(page)
        else:
            previous_content = _get_page_tail(index_page_map[page["index"]-1])

        custom_id = f"{request_name}_{index}"
        context = {
            "current_page":page,
            "previous_content":previous_content,
        }
        user_input = json.dumps(context)

        user_requests.append(
            UserRequest(
                custom_id = custom_id,
                user_input = user_input,
            )
        )
    return user_requests

def _get_page_tail(page:dict[str,Any]) -> str:
    text = extract_text_from_page(page)
    word_starts = [match.start() for match in re.finditer(r"\S+", text)]

    if not word_starts:
        return ""

    word_counts = len(word_starts)
    start_word_index = max(0,math.ceil(word_counts/2)-1)
    start_char_index = word_starts[start_word_index]
    return text[start_char_index:]

def _build_index_page_map(all_pages:list[dict[str,Any]]) -> dict[int,dict[str,Any]]:
    return {
        page["index"]:page
        for page in all_pages
    }





