import shutil
import subprocess
import copy
import json
from typing import Any
from pathlib import Path

from src.coding.controller.event_recorder import EventRecorder
from src.coding.config import CodingConfig
from src.coding.planner.planner import Planner
from src.coding.retriever.retriever import PageRetriever
from src.coding.coder.coder import Coder
from src.coding.filewriter.filewriter import FileWriter
from src.coding.verifier.verifier import Verifier

from src.models.coding_common import ProgrammingPlan,VerificationPlan,CodeFile
from src.models.register_output import RegisterMapOutput
from src.models.planner import PlannerInput
from src.models.retriever import RetrievalResult
from src.models.coder import CoderInput,CoderOutput
from src.models.verifier import VerifierInput,VerifierOutput
from src.models.controller import ControllerLog, Snapshot, SubLogs, TokenConsumption


class Controller:
    candidate_files: list[CodeFile]
    accepted_files: list[CodeFile]
    max_tries: int = 10
    logs: list[ControllerLog]
    config:CodingConfig

    def __init__(self,driver_name:str,config:CodingConfig,pages:list[dict[str,Any]],register_map:dict[str,Any]) -> None:
        print(
            f"\n =============== initializing coding controller ===============\n"
            f"=================="
        )
        self.logs = []
        self.candidate_files = []
        self.accepted_files = []
        self.config = config
        self.not_accepted_files = []
        self.attempted_log = False

        self.driver_name = driver_name
        self.pages = pages
        self.register_map = RegisterMapOutput.model_validate(register_map)

        self._check_valid_client()
        self._check_valid_fqbn()

        self._load_agents()
        print("==================\n")

    @classmethod
    def load_controller(
            cls,
            driver_name:str,
            config:CodingConfig,
            pages:list[dict[str,Any]],
            register_map:dict[str,Any]
    ) -> "Controller":
        return Controller(driver_name,config,pages,register_map)

    async def run(self, user_request: str = None):
        verifier_feedback = None
        run_status = "failed"
        attempt = 0

        self.event_recorder.emit(
            agent="controller",
            action="run",
            status="started",
            payload={
                "user_request": user_request,
                "max_tries": self.max_tries,
            },
        )

        print(
            f"=============== run coding ===============\n"
        )

        try:
            for attempt in range(1, self.max_tries + 1):
                self.attempted_log = False
                print(
                    f"=== attempt {attempt}/{self.max_tries} ===\n"
                )

                self.event_recorder.emit(
                    agent="controller",
                    action="attempt",
                    status="started",
                    attempt=attempt,
                )

                with self.event_recorder.step("planner", "create_plan", attempt=attempt):
                    planner_input = self._build_planner_input(user_request, verifier_feedback)
                    planner_output = self.planner.create_plan(planner_input)

                programming_plan = planner_output.programming_plan
                topics = planner_output.retrieval_topics
                verification_plan = planner_output.verification_plan

                with self.event_recorder.step("retriever", "run", attempt=attempt):
                    retrieval_response = await self.retriever.run(topics)
                    retrieval_results = retrieval_response.results

                with self.event_recorder.step("coder", "create_code_file", attempt=attempt):
                    coder_input = self._build_coder_input(programming_plan, retrieval_results)
                    coder_output = self.coder.create_code_file(coder_input)

                self._update_candidate_files(coder_output)
                with self.event_recorder.step("verifier", "run", attempt=attempt):
                    verifier_input = self._build_verifier_input(verification_plan, retrieval_results)
                    verifier_output = self.verifier.run(verifier_input)

                if verifier_output.passed:
                    self.accepted_files = list(self.candidate_files)
                    self._update_logs(attempt)
                    break

                self._update_logs(attempt)
                verifier_feedback = verifier_output

            if len(self.accepted_files) > 0:
                self.clear_dir()

                print(
                    f" -> start writing accepted files\n"
                    f"writing accepted {len(self.accepted_files)} files to:\n"
                    f"{self.config.project_path.code_dir / self.driver_name}\n"
                )

                FileWriter.write_to_files(self.accepted_files, self.config.project_path.code_dir / self.driver_name)
                run_status = "passed"

            print(
                f"=============== coding ended after {attempt} attempt{"s" if attempt != 1 else ""} ==============="
            )

            return len(self.accepted_files) > 0
        except Exception as exc:
            self._update_logs(attempt)
            run_status = "error"
            self.event_recorder.emit(
                agent="controller",
                action="run",
                status="error",
                payload={
                    "candidate_file_count": len(self.candidate_files),
                    "accepted_file_count": len(self.accepted_files),
                },
                error=exc,
            )

            print(
                f"=============== coding ended after {attempt} attempt{"s" if attempt != 1 else ""} ==============="
            )

            raise

        finally:
            self.event_recorder.emit(
                agent="controller",
                action="run",
                status="finished",
                payload={
                    "run_status": run_status,
                },
            )
            self._save_logs()
            self.event_recorder.write(run_status)

    def _load_agents(self):
        task_configs = self.config.task_configs
        self.planner = Planner.load_from_task_config(
            task_config=task_configs.planning,
            api_key=self.config.get_apikey(task_configs.planning.model.provider),
            tools=None,
        )

        self.retriever = PageRetriever.load_from_task_config(
            pages=self.pages,
            task_config=task_configs.retrieval,
            api_key=self.config.get_apikey(task_configs.retrieval.model.provider),
            input_path=self.config.project_path.input_path / "retrieval.jsonl"
        )

        self.coder = Coder.load_from_task_config(
            task_config=task_configs.coding,
            api_key=self.config.get_apikey(task_configs.coding.model.provider),
            tools=None,
        )

        self.verifier = Verifier.load_from_task_config(
            driver_name=self.driver_name,
            semantic_config=task_configs.verification_semantic,
            execution_config=task_configs.verification_test_coder,
            enable_test_coder=self.config.enable_test_coder,
            cli_path=self.config.project_path.cli_path,
            fqbn=self._build_fqbn(),
            api_key_semantic=self.config.get_apikey(task_configs.verification_semantic.model.provider),
            api_key_test_coder=self.config.get_apikey(task_configs.verification_test_coder.model.provider),
            semantic_tools=None,
            execution_tools=None,
        )

        self.event_recorder = EventRecorder(
            driver_name=self.driver_name,
            output_dir=self.config.project_path.root_path / "data" / self.driver_name,
        )

    def _build_planner_input(self,user_request:str|None,verifier_feedback:VerifierOutput|None) -> PlannerInput:
        if user_request is None:
            user_request = (
                "Generate an Arduino Wire.h-based sensor driver library. "
                "Create the required .h and .cpp driver files and an .ino sketch file for compilation verification."
            )

        return PlannerInput(
            driver_name=self.driver_name,
            enable_test_coder=self.config.enable_test_coder,
            user_request=user_request,
            register_map=self.register_map,
            candidate_files=self.candidate_files,
            accepted_files=self.accepted_files,
            verifier_feedback=verifier_feedback,
        )

    def _build_coder_input(self,programming_plan:ProgrammingPlan,retrieval_results:list[RetrievalResult]) -> CoderInput:
        return CoderInput(
            programming_plan=programming_plan,
            register_map=self.register_map,
            retrieval_results=retrieval_results,
            candidate_files=self.candidate_files,
            accepted_files=self.accepted_files,
        )

    def _build_verifier_input(self,verification_plan:VerificationPlan,retrieval_results:list[RetrievalResult]) -> VerifierInput:
        return VerifierInput(
            verification_plan=verification_plan,
            register_map=self.register_map,
            retrieval_results=retrieval_results,
            candidate_files=self.candidate_files,
            accepted_files=self.accepted_files,
        )

    def _update_candidate_files(self, coder_output: CoderOutput) -> None:
        candidate_files_by_id = {
            candidate_file.file_id: candidate_file
            for candidate_file in self.candidate_files
        }

        for file_id in coder_output.deleted_file_ids:
            candidate_files_by_id.pop(file_id, None)

        for code_file in coder_output.candidate_files:
            candidate_files_by_id[code_file.file_id] = code_file

        self.candidate_files = list(candidate_files_by_id.values())

    def clear_dir(self):
        path = Path(self.config.project_path.code_dir/self.driver_name)
        path.mkdir(parents=True, exist_ok=True)

        for item in path.iterdir():
            if item.is_file() or item.is_symlink():
                item.unlink()
            elif item.is_dir():
                shutil.rmtree(item)

    def _update_logs(self, attempt: int) -> None:
        if attempt <= 0:
            return
        if self.attempted_log:
            return
        try:
            planner_log = _get_log(self.planner, attempt)
            coder_log = _get_log(self.coder, attempt)
            retriever_log = _get_log(self.retriever, attempt)
            verifier_log = _get_log(self.verifier, attempt)

            self.logs.append(
                ControllerLog(
                    driver_name=self.driver_name,
                    attempt=attempt,
                    snapshot=Snapshot(
                        programming_plan=copy.deepcopy(planner_log.planner_output.programming_plan) if planner_log is not None else None,
                        verification_plan=copy.deepcopy(planner_log.planner_output.verification_plan) if planner_log is not None else None,
                        retrieval_topics=copy.deepcopy(planner_log.planner_output.retrieval_topics) if planner_log is not None else None,
                        candidate_files=[
                            file.model_copy(deep=True) for file in self.candidate_files
                        ],
                        accepted_files=[
                            file.model_copy(deep=True) for file in self.accepted_files
                        ],
                        verifier_feedback=verifier_log.verifier_output.model_copy(deep=True) if verifier_log is not None else None,
                        passed=verifier_log.verifier_output.passed if verifier_log is not None else False,
                    ),
                    details=SubLogs(
                        planner_log=planner_log,
                        coder_log=coder_log,
                        retriever_log=retriever_log,
                        verifier_log=verifier_log,
                    ),
                    token_consumption=TokenConsumption(
                        planner=copy.deepcopy(getattr(planner_log,"token_consumption",{})),
                        retriever=copy.deepcopy(getattr(retriever_log,"token_consumption",{})),
                        coder=copy.deepcopy(getattr(coder_log,"token_consumption",{})),
                        verifier=copy.deepcopy(getattr(verifier_log,"token_consumption",{})),
                    ),
                )
            )
            self.attempted_log = True
        except Exception as exc:
            self.event_recorder.emit(
                agent="controller",
                action="update_logs",
                status="error",
                attempt=attempt,
                error=exc,
            )

    def _save_logs(self) -> None:
        log_dir = self.config.project_path.root_path / "data" / self.driver_name
        log_dir.mkdir(parents=True, exist_ok=True)

        log_path = log_dir / "logs.json"

        output = {
            "driver_name": self.driver_name,
            "logs": [self.event_recorder._to_jsonable(log) for log in self.logs],
        }

        log_path.write_text(
            json.dumps(output, ensure_ascii=False, indent=2),
            encoding="utf-8",
        )

        print(f"Logs saved to: {log_path}")


    def _check_valid_client(self) -> None:

        cli_path = Path(self.config.project_path.cli_path).expanduser()

        if not cli_path.is_file():
            raise FileNotFoundError(f"Arduino CLI executable not found: {cli_path}")

        try:
            result = _run_command([str(cli_path), "version"])
        except subprocess.TimeoutExpired as exc:
            raise TimeoutError(f"Arduino CLI version check timed out: {cli_path}") from exc
        except OSError as exc:
            raise RuntimeError(f"Failed to execute Arduino CLI: {cli_path}") from exc

        if result.returncode != 0:
            raise RuntimeError(
                "Arduino CLI is not available or returned an error.\n"
                f"Command: {cli_path} version\n"
                f"STDOUT:\n{result.stdout}\n"
                f"STDERR:\n{result.stderr}"
            )

    def _build_fqbn(self) -> str:

        core = self.config.core.strip()
        board = self.config.board.strip()

        if not core:
            raise ValueError("Arduino core must not be empty.")

        if not board:
            raise ValueError("Arduino board must not be empty.")

        return f"arduino:{core}:{board}"

    def _check_valid_fqbn(self) -> None:

        cli_path = Path(self.config.project_path.cli_path).expanduser()
        fqbn = self._build_fqbn()

        try:
            result = _run_command([str(cli_path), "board", "details", "--fqbn", fqbn])
        except subprocess.TimeoutExpired as exc:
            raise TimeoutError(f"Arduino FQBN validation timed out: {fqbn}") from exc
        except OSError as exc:
            raise RuntimeError(f"Failed to execute Arduino CLI for FQBN validation: {cli_path}") from exc

        if result.returncode != 0:
            raise ValueError(
                "Invalid or unavailable Arduino FQBN.\n"
                f"FQBN: {fqbn}\n"
                "Please check whether the required Arduino core is installed.\n"
                f"STDOUT:\n{result.stdout}\n"
                f"STDERR:\n{result.stderr}"
            )

def _run_command(command: list[str]) -> subprocess.CompletedProcess[str]:
    return subprocess.run(
        command,
        capture_output=True,
        text=True,
        encoding="utf-8",
        errors="replace",
        timeout=60,
    )

def _get_log(agent,attempt: int) -> Any:
    index = attempt - 1
    try:
        return agent.logs[index].model_copy(deep=True)
    except IndexError:
        return None