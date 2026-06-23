from __future__ import annotations
from pathlib import Path
from src.models.coding_common import CodeFile

class FileWriter:

    @staticmethod
    def write_to_file(code_file: CodeFile,output_dir:Path | str) -> None:
        output_dir = Path(output_dir)
        output_dir.mkdir(parents=True, exist_ok=True)

        filepath = output_dir / f"{code_file.name}{code_file.file_type}"
        content = (
            f"/*\n"
            f"{code_file.description}\n"
            f"*/\n\n"
            f"{code_file.content}\n"
        )

        with (open(filepath, "w", encoding="utf-8") as file):
            file.write(content)

        print(f"Successfully wrote to {filepath}")

    @staticmethod
    def write_to_files(code_files:list[CodeFile],output_dir:Path | str) -> None:
        output_dir = Path(output_dir)
        for index,code_file in enumerate(code_files):
            print(f"start writing file {index/len(code_files)}")
            FileWriter.write_to_file(
                code_file = code_file,
                output_dir = output_dir)

    @staticmethod
    def write_log(self):
        pass

