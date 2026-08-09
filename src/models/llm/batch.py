from pydantic import BaseModel

class UserRequest(BaseModel):
    custom_id:str
    user_input:str

class RequestReference(BaseModel):
    custom_id:str
    pdf_sha256:str
    page_index:int