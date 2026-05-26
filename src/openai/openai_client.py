from openai import OpenAI

class OpenAITask:
    openAIChat:OpenAI
    model_name:str
    instruction:str
    user:str

    def __init__(self,api_key:str,user:str,task_config:dict,generate_time_out:int):
        self.openAI_client=OpenAI(api_key=api_key)
