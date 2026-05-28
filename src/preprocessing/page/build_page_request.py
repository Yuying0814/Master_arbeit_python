import json
import math
import re
from typing import Any
from preprocessing.utils.text_utils import extract_text_from_page

def build_page_requests(pages:list[dict[str,Any]],request_name:str)->list[dict[str,str]]:
    keep_keys = ("index","markdown","tables","classification")
    new_pages = [{key:page[key]for key in keep_keys if key in page} for page in pages]

    previous_content = ""
    user_requests = []

    for index,page in enumerate(new_pages):
        custom_id = f"{request_name}_{index}"
        context = {
            "current_page":page,
            "previous_content":previous_content,
        }
        user_input = json.dumps(context)
        user_requests.append(
            {
            "custom_id":custom_id,
            "user_input":user_input
            }
        )
        previous_content = _get_page_tail(page)
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





