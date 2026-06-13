import json
import time
import warnings
import asyncio

from collections.abc import Callable

from langchain_core.messages import AIMessage
from pydantic import BaseModel
from typing import Any,TypeVar,TYPE_CHECKING
from src.llm.common.types import ValidOutputFormat

if TYPE_CHECKING:
    from src.models.task_config import TaskConfig

T = TypeVar("T")

class HasOutputFormat:
    output_format: ValidOutputFormat

class HasLangChainResultParser(HasOutputFormat):
    @staticmethod
    def _is_structured_format(text_format: Any) -> bool:
        if isinstance(text_format, dict):
            return True

        return isinstance(text_format, type) and issubclass(text_format, BaseModel)

    def parse_result(self,result:AIMessage) -> Any:
        if self._is_structured_format(self.output_format):

            if isinstance(result, BaseModel):
                return result.model_dump()

            return result

        if self.output_format == "json":
            return self._parse_json(result.content)

        if self.output_format == "text":
            return result.content

        raise ValueError(f"Unsupported text_format: {self.output_format}")

    @staticmethod
    def _parse_json(content: str) -> Any:
        try:
            return json.loads(content)
        except json.JSONDecodeError as error:
            raise ValueError("Model output is not valid JSON.") from error


class HasApiKey:
    api_key: str

class HasRunWithRetry:

    @staticmethod
    def run_with_retry(function: Callable[..., T], *args, max_retries: int = 3, base_delay: int = 2) -> T:
        for attempt in range(1, max_retries + 2):
            try:
                return function(*args)

            except (ValueError, TypeError):
                raise

            except Exception as error:
                if attempt > max_retries:
                    raise RuntimeError(f"Stage {function.__name__} failed") from error

                delay = base_delay * 2 ** (attempt - 1)

                warnings.warn(f"Stage {function.__name__} failed at attempt {attempt}/{max_retries + 1}",
                              RuntimeWarning, stacklevel=2)
                time.sleep(delay)

        raise RuntimeError(f"{function.__name__} failed")

    @staticmethod
    async def run_with_retry_async(function: Callable[..., T], *args, max_retries: int = 3, base_delay: int = 2) -> T:
        for attempt in range(1, max_retries + 2):
            try:
                return await function(*args)

            except (ValueError, TypeError):
                raise

            except Exception as error:
                if attempt > max_retries:
                    raise RuntimeError(f"Stage {function.__name__} failed") from error

                delay = base_delay * 2 ** (attempt - 1)

                warnings.warn(f"Stage {function.__name__} failed at attempt {attempt}/{max_retries + 1}",
                              RuntimeWarning, stacklevel=2)
                await asyncio.sleep(delay)

        raise RuntimeError(f"{function.__name__} failed")

class HasTaskConfig:
    @classmethod
    def load_from_task_config(cls,task_config:"TaskConfig"):
        ...