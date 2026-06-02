from openai import OpenAI

class OpenAIAgent:
    openai_client:OpenAI
    system_instruction:str
    task_instruction:str

    def __init__(self,api_key:str):
        self.openai_client = OpenAI(api_key=api_key)