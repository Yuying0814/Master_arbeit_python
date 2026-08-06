from __future__ import annotations

import uuid
from typing import Any

from src.chat.config import ChatConfig
from src.chat.tools import build_tools
from src.llm.llm_agent import LLMAgent


class ChatAgent:
    def __init__(
        self,
        config: ChatConfig,
        *,
        thread_id: str | None = None,
    ) -> None:
        self.agent = LLMAgent.load_from_task_config(
            task_config=config.task_config,
            tools=build_tools(config),
            thread_id=thread_id or uuid.uuid4().hex,
        )

    def run(self, user_input: str) -> Any:
        return self.agent.run(user_input)
