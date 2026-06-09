from pydantic import BaseModel

class UserRequest(BaseModel):
    custom_id:str
    user_input:str