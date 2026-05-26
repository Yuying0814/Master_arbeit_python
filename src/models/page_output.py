from models.structuredOutputModel import StructuredOutputModel

class PageClassification(StructuredOutputModel):
    is_register_summary_relevant: bool
    is_register_map_relevant: bool
    is_digital_interface_relevant: bool
    is_data_conversion_relevant: bool
    is_initialization_and_reset_relevant: bool
    is_timing_relevant: bool
    is_interrupt_alert_relevant: bool
    is_fifo_relevant: bool

    @classmethod
    def get_default_value(cls)->dict[str,bool]:
        return {field_name:False for field_name in cls.model_fields}

class PageDescription(StructuredOutputModel):
    toc:str
    register_summary:str
    register_map:str
    digital_interface:str
    data_conversion:str
    initialization_and_reset:str
    timing:str
    interrupt_alert:str
    fifo:str
    coding_example:str

    @classmethod
    def get_default_value(cls)->dict[str,str]:
        return {field_name:"" for field_name in cls.model_fields}