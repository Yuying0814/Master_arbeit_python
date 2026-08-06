from __future__ import annotations

from src.chat.chat_agent import ChatAgent
from src.chat.config import ChatConfig
from src.chat.tools import QuitChatRequested, read_user_input


def start_chat(config: ChatConfig | None = None) -> None:
    config = config or ChatConfig.load_config()

    try:
        agent = ChatAgent(config)
    except Exception as error:
        print(f"Failed to start chat: {error}")
        return



    try:
        begin = True
        count = 0
        while True:
            count += 1
            if begin:
                response = agent.run("Hi")
                print("\n   Chat started  ✔ ")
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
                print("(Type 'quit chat' to exit.)\n")
            except Exception as error:
                print(f"Assistant error: {error}")
    except (QuitChatRequested, EOFError, KeyboardInterrupt):
        print("\nChat closed.")


def main() -> None:
    start_chat()

if __name__ == "__main__":
    main()
