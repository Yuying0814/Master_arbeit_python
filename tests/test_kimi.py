import os
import json
import asyncio

from dotenv import load_dotenv
from pathlib import Path
from src.models.task_config import TaskConfig,ModelConfig
from src.models.preprocessing.register_output import RegisterMapOutput
from src.models.llm.batch import UserRequest
from src.llm.kimi.batch.async_batch_task import AsyncKimiBatchTask


#######################################################
PROJECT_ROOT = Path(__file__).resolve().parents[1]
DATA_DIR = PROJECT_ROOT / "data"
ENV = (PROJECT_ROOT / ".env").resolve()
INPUT_DIR = DATA_DIR/ "input"
load_dotenv(ENV)
#######################################################

async def test():
    kimi_task = AsyncKimiBatchTask.load_from_task_config(
        api_key=os.getenv("KIMI_API_KEY"),
        input_path=INPUT_DIR/"kimi_input.jsonl",
        task_config=TaskConfig(
        model=ModelConfig(
            provider="kimi",
            model_name="kimi-k2.6",
            is_batch=True,
            thinking_effort=None,
            temperature=None,
            max_tokens=2000,
        ),
        system="You are a helpful assistant",
        output_format="text",
        )
    )
    user_requests = []
    user_request = UserRequest(
        custom_id="kimi_k2.6_text_01",
        user_input="Say hello to me."
    )

    user_requests.append(user_request)

    kimi_task.add_user_inputs(user_requests)
    result = await kimi_task.run()

    print(result)

if __name__ == "__main__":
    asyncio.run(test())