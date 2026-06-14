from __future__ import annotations

import sys
from pathlib import Path
from typing import Literal

PROJECT_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(PROJECT_ROOT))

from tests.test_without_preprocessing import test_without_preprocessing
from tests.test_preprocessor import test_preprocessor_pipeline


if __name__ == "__main__":
    mode: Literal["single_test","multiple_test"] = "single_test"
    match mode:
        case "single_test":
            pdf_file = PROJECT_ROOT / "tests" / "lis3dh.pdf"
            pdf_name = pdf_file.name

            print(f"\n==============================")
            print(f"Running tests for: {pdf_name}")
            print(f"==============================\n")

            test_without_preprocessing(pdf_name)
            test_preprocessor_pipeline(pdf_name)

        case "multiple_test":
            input_pdf_dir = PROJECT_ROOT / "data" / "input_pdf"

            pdf_files = sorted(input_pdf_dir.glob("*.pdf"))

            for pdf_path in pdf_files:
                pdf_name = pdf_path.name

                print(f"\n==============================")
                print(f"Running tests for: {pdf_name}")
                print(f"==============================\n")

                test_without_preprocessing(pdf_name)
                test_preprocessor_pipeline(pdf_name)


