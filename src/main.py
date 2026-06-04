
from tests.test_without_preprocessing import test_without_preprocessing
from tests.test_preprocessor import test_preprocessor_pipeline

if __name__ == '__main__':
    name = "MCP9808.pdf"
    test_without_preprocessing(name)
    test_preprocessor_pipeline(name)



