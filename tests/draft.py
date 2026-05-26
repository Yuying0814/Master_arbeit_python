from openai import OpenAI
from dotenv import load_dotenv
from pathlib import Path
import os

env_path = Path.cwd().parent / '.env'
load_dotenv(dotenv_path=env_path)
api_key = os.getenv("OPENAI_API_KEY")

client = OpenAI(api_key=api_key)

response = client.responses.create(
    model="gpt-5.5",
    input="Hi."
)
print(response)
pass
