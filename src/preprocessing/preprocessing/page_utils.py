
from src.preprocessing.models.pages import page
from bs4 import BeautifulSoup

def parse_html_table(html: str) -> str:
    """Convert an HTML table into text rows"""
    soup = BeautifulSoup(html, "html.parser")

    rows = []

    for row in soup.find_all("tr"):
        cells = row.find_all(["th", "td"])
        cell_texts = [cell.get_text(separator=" ", strip=True) for cell in cells]

        if cell_texts:
            rows.append(" | ".join(cell_texts))
    return "\n".join(rows)

def resolve_page_text(one_page:page) -> str:

    page_text = one_page.markdown
    for table in one_page.tables:
        table_id = table["id"]
        table_html = table["content"]

        table_reference = f"[{table_id}]({table_id})"
        table_text = parse_html_table(table_html)

        page_text = page_text.replace(table_reference, table_text)
    return page_text

def resolve_page_texts(pages:list[page])->list[str]:

    return [resolve_page_text(one_page) for one_page in pages]




