import time
import warnings
import asyncio

from collections.abc import Callable

from langchain_core.messages import AIMessage

from pydantic import BaseModel
from typing import Any,TypeVar,TYPE_CHECKING

from src.models.structuredOutputModel import StructuredOutputModel
from src.llm.common.types import ValidOutputFormat

if TYPE_CHECKING:
    from src.models.task_config import TaskConfig

T = TypeVar("T")

class HasOutputFormat:
    output_format: ValidOutputFormat = None

    @staticmethod
    def _is_structured_format(text_format: Any) -> bool:
        return isinstance(text_format, type) and issubclass(text_format, BaseModel)

    @staticmethod
    def validate_output_format(value) -> ValidOutputFormat:
        if value is None:
            return None

        if isinstance(value, str):
            if value.lower().strip() == "text":
                return "text"

        if isinstance(value, type) and issubclass(value, StructuredOutputModel):
            return value

        raise TypeError(
            f"Unsupported output format:{type(value).__name__}"
            "output_format must be subclass of StructuredOutputModel,None or 'text'，"
        )

    def parse_result(self, result: Any) -> Any:
        if self._is_structured_format(self.output_format):
            if not isinstance(result, BaseModel):
                raise TypeError(
                    "Structured output must be a BaseModel instance."
                )

            return result.model_dump()

        if not isinstance(result, AIMessage):
            raise TypeError("Text output must be an AIMessage.")

        return result.content

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