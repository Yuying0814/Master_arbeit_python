from __future__ import annotations
from pathlib import Path
from src.models.coding.coding_common import CodeFile

class FileWriter:

    @staticmethod
    def write_to_file(code_file: CodeFile,project_dir:Path | str) -> None:
        project_dir = Path(project_dir)
        project_dir.mkdir(parents=True, exist_ok=True)

        filename = code_file.name
        if not filename.endswith(code_file.file_type):
            filename = f"{filename}{code_file.file_type}"

        filepath = project_dir / filename

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
        project_dir = Path()

        for code_file in code_files:
            if code_file.file_type.strip() == ".ino":
                project_dir = output_dir/code_file.name
                break

            raise ValueError("Code files must contain at least one .ino file")

        for index,code_file in enumerate(code_files):
            print(
                f"==================\n"
                f"start writing file {index+1}/{len(code_files)}"
            )
            FileWriter.write_to_file(code_file=code_file, project_dir=project_dir)
            print(
                f"==================\n"
            )

    @staticmethod
    def write_log(self):
        pass

