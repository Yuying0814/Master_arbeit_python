import os
import json
import time

from pydantic import BaseModel,Field
from pathlib import Path
from dotenv import load_dotenv
from langchain_ollama import ChatOllama

PROJECT_ROOT = Path(__file__).resolve().parents[1]

###############################################
USER = "Hi, what model are you?"
BASE_URL ="http://129.187.200.113:11434"
###############################################
ENV = (PROJECT_ROOT / ".env").resolve()
load_dotenv(ENV)

class SayHi(BaseModel):
    user_input:str = Field(description="copy the user input")
    text: str = Field(description="your output text")


def test():
    llm = ChatOllama(
        model="mistral-medium-3.5:128b-ctx256k",
        num_predict=50000,
        base_url=BASE_URL if BASE_URL.strip() else None,
    )

    this_input =[
        ("system", f"You are a helpful assistant."
                   f"Return exactly one JSON object with these two string fields"
                   f":- user_input: copy the user input exactly"
                   f"- text: your answer"
         ),
        ("human", USER),
    ]

    response_text = llm.invoke(this_input)
    print(f"\ntext: {response_text.text}")
    print(f"\nusage: {response_text.usage_metadata}")

    structured_model = llm.with_structured_output(
        schema=SayHi,
        method="json_mode",
        include_raw=True,
    )

    response_structured = structured_model.invoke(this_input)
    print(f"\nstructured: {response_structured['parsed'].model_dump_json(indent=4)}")
    print(f"\nusage: {response_structured['raw'].usage_metadata}")

if __name__ == "__main__":
    test()