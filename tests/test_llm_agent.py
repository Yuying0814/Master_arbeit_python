import sys
import os

from dotenv import load_dotenv
from pathlib import Path
from langchain.tools import tool
from src.llm.llm_agent import LLMAgent
from pydantic import BaseModel,Field

PROJECT_ROOT = Path(__file__).resolve().parents[1]
PROMPT_PATH = PROJECT_ROOT/"prompts"
sys.path.insert(0, str(PROJECT_ROOT))
load_dotenv(dotenv_path=PROJECT_ROOT / ".env")
openai_api_key = os.getenv("OPENAI_API_KEY", "").strip()

from src.llm.model_factory import build_chat_model
from src.models.structuredOutputModel import StructuredOutputModel

class WriteInput(BaseModel):
    content: str = Field(
        description="content to be written",
    )
    path:str = Field(
        description="path of the file to be written",
    )

@tool(args_schema=WriteInput)
def write_text(content:str, path:str) -> None:
    """ simple write text function """
    path = Path(path)
    with open(path, "w") as f:
        f.write(content)

class TestOutput(StructuredOutputModel):
    random_number: int
    randon_string: str

def test_run_agent():
    model = build_chat_model(
        provider = "openai",
        model_name="gpt-5-mini",
        api_key = openai_api_key,
    )

    agent = LLMAgent(
        model=model,
        task_name="test",
        output_format = None,
        tools = [write_text]
    )
    user_input = "say something randomly and write it to 'D:/python/master_arbeit/data/output/test.txt'"
    response = agent.run(user_input)

    print("\n")
    print("Response:", response)
    print("Response:type",type(response))
    print("Usage:", agent.total_tokens)

if __name__ == "__main__":
    test_run_agent()
