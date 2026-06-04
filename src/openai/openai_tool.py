import inspect
from typing import Any,TypeVar
from pydantic import BaseModel, create_model
from collections.abc import Callable
from openai import pydantic_function_tool

ReturnType = TypeVar("ReturnType")


class OpenAITool:
    fun_name: str
    fun_args: type[BaseModel]
    function: Callable[..., Any]

    def __init__(self, fun_name: str, fun_args: type[BaseModel], function: Callable[..., ReturnType]):
        self.fun_name = fun_name
        self.fun_args = fun_args
        self.function = function

    @classmethod
    def from_function(cls,function: Callable[..., ReturnType],**opts: Any,) -> "OpenAITool":
        name = function.__name__
        args = _get_args(function)
        tool = cls(name, args,function)

        function_description = opts.get("function_description")

        if function_description is None:
            function_description = inspect.getdoc(function)

        if function_description:
            tool.change_function_description(function_description)

        if "param_description" in opts:
            tool.change_param_description(opts["param_description"])

        return tool

    @classmethod
    def from_function_BaseModel(cls,function:Callable[...,ReturnType],tool_args: type[BaseModel],) -> "OpenAITool":
        return cls(function.__name__, tool_args,function)

    def change_function_description(self, description: str) -> None:
        self.fun_args.__doc__ = description
        self.fun_args.model_rebuild(force=True)

    def change_param_description(self, param_description: dict[str, str]) -> None:
        for name, description in param_description.items():
            if name in self.fun_args.model_fields:
                self.fun_args.model_fields[name].description = description

        self.fun_args.model_rebuild(force=True)

    def get_openai_tool(self):
        return pydantic_function_tool(self.fun_args, name=self.fun_name)

    def call(self,*args) -> ReturnType:
        return self.function(*args)

    def call_with_model(self,args_model:BaseModel) -> ReturnType:
        return self.function(**args_model.model_dump())

    def call_with_json(self,arguments: str) -> ReturnType:
        args_model = self.fun_args.model_validate_json(arguments)
        return self.call_with_model(args_model)


def _get_args(function: Callable[..., Any]) -> type[BaseModel]:
    signature = inspect.signature(function)

    fields = {}

    for parameter in signature.parameters.values():
        if parameter.name in {"self", "cls"}:
            continue

        if parameter.kind in {
            inspect.Parameter.VAR_POSITIONAL,
            inspect.Parameter.VAR_KEYWORD,
        }:
            continue

        if parameter.annotation is inspect.Parameter.empty:
            annotation = Any
        else:
            annotation = parameter.annotation

        if parameter.default is inspect.Parameter.empty:
            default = ...
        else:
            default = parameter.default

        fields[parameter.name] = (annotation, default)

    Args = create_model(f"{function.__name__}Args", **fields)

    return Args