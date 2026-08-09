import json
import math
import re
from typing import Any
from src.preprocessing.utils.text_utils import extract_text_from_page
from src.models.batch import UserRequest, RequestReference
from src.models.retriever import RetrievalTopic,RetrieverUserInput
from src.models.data_manager import DocumentRecord

def build_user_requests(
        request_id:int,
        topics:list[RetrievalTopic],
        documents:list[DocumentRecord])->RetrieverUserInput:

    user_requests = []
    request_references = []
    document_id = 0

    for document in documents:
        pdf_sha256 = document.pdf_sha256
        pages = document.pages

        keep_keys = ("index","markdown","tables","classification")
        new_pages = [{key:page[key]for key in keep_keys if key in page} for page in pages]
        index_page_map = _build_index_page_map(new_pages)

        for page in new_pages:
            if int(page["index"]) == 0:
                previous_content = ""
            else:
                previous_content = _get_page_tail(index_page_map[page["index"]-1])

            custom_id = f"{request_id}_{document_id}_{page['index']}"
            context = {
                "topics": [item.model_dump() for item in topics],
                "current_page":page,
                "previous_content":previous_content,
            }

            user_input = json.dumps(context, ensure_ascii=False)

            user_requests.append(
                UserRequest(
                    custom_id = custom_id,
                    user_input = user_input,
                )
            )
            request_references.append(
                RequestReference(
                    custom_id=custom_id,
                    pdf_sha256=pdf_sha256,
                    page_index=page["index"],
                )
            )
        document_id += 1

    return RetrieverUserInput(
        user_requests = user_requests,
        request_references=request_references,
    )

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





