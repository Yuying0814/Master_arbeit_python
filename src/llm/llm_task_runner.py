from typing import Protocol, Any
from pathlib import Path

import asyncio
import time

from src.models.llm.batch import UserRequest
from src.models.llm.common import NormalizedUsage,NormalizedTokenConsumption
from src.models.task_config import TaskConfig
from src.llm.llm_batch_task import LLMBatchTask
from src.llm.llm_single_task import LLMSingleTask
from src.llm.openai.batch.async_batch_task import AsyncOpenAIBatchTask
from src.llm.anthropic.batch.async_batch_task import AsyncClaudeBatchTask
from src.llm.google.batch.async_batch_task import AsyncGeminiBatchTask
from src.llm.kimi.batch.async_batch_task import AsyncKimiBatchTask
from src.llm.zai.batch.async_batch_task import AsyncGlmBatchTask
from src.llm.ollama.batch.ollama_batch_task import OllamaBatchTask


class LLMTask(Protocol):
    has_valid_output:bool
    final_usage: dict[str, NormalizedUsage]
    total_usage:dict[str, NormalizedUsage]

    async def run(self) -> Any:
        ...

    def add_user_inputs(self,user_inputs: str | list[UserRequest]):
        ...

class LLMTaskRunner:
    task: LLMTask
    results: Any
    has_valid_output: bool
    token_consumption: NormalizedTokenConsumption

    def __init__(self, task: LLMTask,timeout:float|None) -> None:
        self.task = task
        self.results = None
        self.has_valid_output = False
        self.token_consumption = NormalizedTokenConsumption()
        self.timeout = timeout
        self.elapsed_time = 0.0

    async def run(self,user_input: str | list[UserRequest]) -> Any:

        self.task.add_user_inputs(user_input)
        start_time = time.perf_counter()

        try:
            if self.timeout is None:
                results = await self.task.run()
            else:
                async with asyncio.timeout(self.timeout):
                    results = await self.task.run()
        finally:
            elapsed_time = time.perf_counter() - start_time
            self.elapsed_time = elapsed_time
            print(f"Task completed in {elapsed_time:.2f} seconds")

        self.results = results
        self.has_valid_output = self.task.has_valid_output
        self.get_token_usage()
        return results

    async def cleanup(self) -> None:
        if isinstance(self.task, LLMBatchTask):
            await self.task.cleanup()

    @classmethod
    def load_from_task_config(cls, task_config: TaskConfig, api_key:str = None, input_path:str|Path = None) -> "LLMTaskRunner":
        task = cls.build_task(
            task_config = task_config,
            api_key = api_key,
            input_path = Path(input_path) if input_path else None,
        )

        timeout = _get_timeout(task_config.model.timeout)
        return cls(task,timeout=timeout)

    @staticmethod
    def build_task(task_config:TaskConfig, api_key:str|None ,input_path:Path|None) -> LLMTask:
        if not task_config.model.is_batch:
            return LLMSingleTask.load_from_task_config(
                task_config = task_config,
                api_key = api_key,
            )

        match task_config.model.provider:
            case "openai":
                return AsyncOpenAIBatchTask.load_from_task_config(
                    api_key = api_key,
                    input_path = input_path,
                    task_config = task_config,
                )

            case "google":
                return AsyncGeminiBatchTask.load_from_task_config(
                    api_key = api_key,
                    input_path = input_path,
                    task_config = task_config,
                )

            case "anthropic":
                return AsyncClaudeBatchTask.load_from_task_config(
                    api_key = api_key,
                    task_config = task_config,
                )

            case "kimi":
                return AsyncKimiBatchTask.load_from_task_config(
                    api_key=api_key,
                    input_path = input_path,
                    task_config = task_config,
                )

            case "zai":
                return AsyncGlmBatchTask.load_from_task_config(
                    api_key=api_key,
                    input_path=input_path,
                    task_config=task_config,
                )

            case "ollama":
                return OllamaBatchTask.load_from_task_config(
                    task_config = task_config,
                )
            case _:
                raise ValueError(f"Unsupported provider {task_config.model.provider}")

    def get_token_usage(self) -> None:
        self.token_consumption = NormalizedTokenConsumption(
            final_usage=self.task.final_usage,
            total_usage=self.task.total_usage,
        )

def _get_timeout(timeout:int|None) -> float|None:
    if timeout is None:
        return timeout
    return float(timeout)