from __future__ import annotations

from src.coding.config import CodingConfig
from src.preprocessing.config import PreprocessingConfig
from src.chat.chat_agent import ChatAgent
from src.chat.config import ChatConfig
from src.chat.tools import QuitChatRequested, read_user_input


def start_chat(
        chat_config: ChatConfig,
        preprocessing_config: PreprocessingConfig,
        coding_config: CodingConfig,
) -> None:

    try:
        agent = ChatAgent(
            chat_config=chat_config,
            preprocessing_config=preprocessing_config,
            coding_config=coding_config
        )
    except Exception as error:
        print(f"Failed to start chat: {error}")
        return

    try:
        begin = True
        count = 0
        while True:
            count += 1
            if begin:
                print("\n   Chat started  ✔ ")
                try:
                    response = agent.run("Hi")
                except Exception as error:
                    print(f"Failed to get initial response: {error}")
                    return
                print(f"======================== chat round{count} =========================")
                print(f"Assistant: {response}")
                print("(Type 'quit' to exit.)\n")
                begin = False
                continue

            user_input = read_user_input("User: ").strip()
            if not user_input:
                continue

            try:
                response = agent.run(user_input)
                print(f"========================chat round{count}=========================")
                print(f"Assistant: {response}")
                print("(Type 'quit' to exit.)\n")
            except Exception as error:
                print(f"Assistant error: {error}")
    except (QuitChatRequested, EOFError, KeyboardInterrupt):
        print("\nChat closed.")
