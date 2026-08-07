from __future__ import annotations

import uuid
from typing import Any

from src.coding.config import CodingConfig
from src.preprocessing.config import PreprocessingConfig
from src.chat.config import ChatConfig
from src.chat.tools import build_tools
from src.llm.llm_agent import LLMAgent


class ChatAgent:
    def __init__(
            self,
            chat_config: ChatConfig,
            preprocessing_config: PreprocessingConfig,
            coding_config: CodingConfig,
            *,
            thread_id: str | None = None
    ) -> None:

        self.agent = LLMAgent.load_from_task_config(
            task_config=chat_config.task_configs.chat,
            tools=build_tools(
                chat_config=chat_config,
                preprocessing_config=preprocessing_config,
                coding_config=coding_config,
            ),
            thread_id=thread_id or uuid.uuid4().hex,
        )

    def run(self, user_input: str) -> Any:
        return self.agent.run(user_input)
