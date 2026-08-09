from src.models.structuredOutputModel import StructuredOutputModel

class DeviceIdentificationResult(StructuredOutputModel):
    detected_device_name: str
    existing_device_name: str | None
    is_consistent: bool