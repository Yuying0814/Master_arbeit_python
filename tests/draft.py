from preprocessing.retrieval.find_relevant_page_range import find_relevant_page_range
from src.preprocessing.mistral.mistral_client import MistralClient
from dotenv import load_dotenv
from pathlib import Path
from preprocessing.toc.find_toc_pages import find_toc_pages
from preprocessing.toc.toc_entry import extract_toc_entries
from preprocessing.utils.text_utils import remove_header_footer
from preprocessing.toc.resolve_toc_entries import resolve_toc_entries
import os

env_path = Path.cwd().parent / '.env'
load_dotenv(dotenv_path=env_path)
api_key = os.getenv("MISTRAL_API_KEY")
pdf = Path.cwd().parent / "data" / "input_pdf" / "opt3001.pdf"

client = MistralClient(api_key=api_key)
ocr_result = client.run_ocr(pdf)
pages = ocr_result["pages"]

outpages = find_toc_pages(pages)

# for page_index, page in enumerate(outpages):
#     print(page_index, page["result_toc"])
#
toc_pages = [page for index, page in enumerate(outpages) if page["result_toc"]["is_toc"]]
toc_pages = remove_header_footer(toc_pages)
toc_entries = extract_toc_entries(toc_pages)
page_idx,sum_idx = resolve_toc_entries(toc_entries)
pages = find_relevant_page_range(pages)
for index,page in enumerate(pages):
    print(index,page["result_retrieval"])
reg_index = [index+1 for index,page in enumerate(pages) if page["result_retrieval"]["is_reg_map_relevant"]]
reg_sum_index = [index+1 for index,page in enumerate(pages) if page["result_retrieval"]["is_reg_sum_relevant"]]
print(reg_index)
print(reg_sum_index)



