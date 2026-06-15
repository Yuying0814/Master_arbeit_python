## External Dependencies

This project requires Python 3.10 or later.

Install the required external Python libraries with:

```bash
pip install openai mistralai pydantic python-dotenv langchain-core langchain-openai langchain-ollama
```

The main external dependencies are:

| Library | Purpose |
|---|---|
| `openai` | Runs OpenAI normal LLM calls and OpenAI Batch API calls. |
| `mistralai` | Runs Mistral OCR for PDF datasheets. |
| `pydantic` | Defines structured output models and validates extracted data. |
| `python-dotenv` | Loads API keys from the `.env` file. |
| `langchain-core` | Provides common LangChain interfaces, callbacks, runnables, and message objects. |
| `langchain-openai` | Provides the LangChain `ChatOpenAI` model wrapper. |
| `langchain-ollama` | Provides the LangChain `ChatOllama` model wrapper. |

If `provider="ollama"` is used in the model configuration, Ollama must also be installed and the selected local model must be available on the machine.

The `.env` file must contain the following keys when OpenAI and Mistral OCR are used:

```text
OPENAI_API_KEY=your_openai_api_key
MISTRALAI_API_KEY=your_mistral_api_key
```

## Running the Preprocessor

The preprocessing pipeline can be started from `src/main.py`.

Before running the code, configure the user settings at the top of `src/main.py`.

### 1. Select the running mode

Use `single_test` to process one PDF file:

```python
MODE = "single_test"
```

Use `multiple_test` to process all PDF files in one folder:

```python
MODE = "multiple_test"
```

### 2. Set the input PDF path

For `single_test`, set `PDF_FILE`:

```python
PDF_FILE = "D:/xxx/xxx/xxx/xxx/xxx.pdf"
```
or
```python
PDF_FILE = Path("D:/xxx/xxx/xxx/xxx/xxx.pdf")
```

For `multiple_test`, set `PDF_DIR = your pdf folder`:

```python
PDF_DIR = "D:/xxx/xxx/xxx/xxx"
```
or
```python
PDF_FILE = Path("D:/xxx/xxx/xxx/xxx")
```


### 3. Set the environment file path

The `.env` file must contain the API keys:

```text
OPENAI_API_KEY=your_openai_api_key
MISTRALAI_API_KEY=your_mistral_api_key
```

Set `ENV_FILE`:
```python
ENV_FILE = "D:/xxx/xxx.env"
```
or
```python
ENV_FILE = Path("D:/xxx/xxx.env")
```

### 4. Configure the model settings

The model settings are defined in `configure_preprocessing_models()` in `src/main.py`.

The page-level tasks are usually executed with OpenAI Batch:

```python
"is_batch": True
```

The extraction tasks are usually executed as normal LLM calls:

```python
"is_batch": False
```

If the extraction step fails with `max_output_tokens`, increase `max_tokens` for the corresponding task:

```python
"extract_reg_index": {
    "max_tokens": 8000,
}

"extract_reg_map": {
    "max_tokens": 16000,
}
```

### 5. Run the code

Run `src/main.py` from PyCharm.

After the preprocessing pipeline finishes successfully, the output files are saved automatically under:

```text
data/output/<pdf_name>/
```

The generated files include:

```text
<pdf_name>_preprocessor_snapshot.json
<pdf_name>_register_map.json
<pdf_name>_pages.json
```
