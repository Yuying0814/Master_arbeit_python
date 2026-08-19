from src.llm.llm_task_runner import LLMTaskRunner
from src.models.task_config import TaskConfig
from src.models.coding.function_identifier import FunctionIdentifierInput,DeviceFunctionOutput,FunctionIdentifierLog

class FunctionIdentifier:
    identifier: LLMTaskRunner
    logs: list

    def __init__(self,identifier: LLMTaskRunner):
        self.identifier = identifier
        self.logs = []
        print("Function identifier created")

    @classmethod
    def load_from_task_config(
            cls,
            task_config:TaskConfig,
            *,
            api_key:str|None = None,
    ):
        identifier = LLMTaskRunner.load_from_task_config(
            task_config = task_config,
            api_key=api_key,
        )

        return cls(identifier=identifier)

    async def identify_functions_async(self, identifier_input:FunctionIdentifierInput) -> DeviceFunctionOutput:
        user_input = identifier_input.model_dump_json()
        if not user_input.strip():
            return DeviceFunctionOutput(
                device_functions=[]
            )

        print(" -> start device function identification")
        functions = await self.identifier.run(user_input)
        self._update_logs(identifier_input, functions)

        print(
            f" -> Device functions successfully identified\n"
        )
        return functions

    def get_elapsed_time(self) -> float:
        value = self.identifier.elapsed_time
        self.identifier.elapsed_time = 0.0
        return value

    def _update_logs(
            self,
            identifier_input: FunctionIdentifierInput,
            identifier_output: DeviceFunctionOutput
    ) -> None:

        self.logs.append(
            FunctionIdentifierLog(
                identifier_input=identifier_input.model_copy(deep=True),
                identifier_output=identifier_output.model_copy(deep=True),
                token_consumption=self.identifier.token_consumption.model_dump(
                    mode="json"
                ) or {
                    "total_usage": {},
                    "final_usage": {},
                },
            )
        )


