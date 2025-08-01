@staticmethod
def convert_to_string(value):
    """
    Converts a value to its string representation.
    
    Args:
        value: The value to convert.
        
    Returns:
        str: The string representation of the value.
    """
    if isinstance(value, (str, int, float)):
        return str(value)
    elif isinstance(value, list):
        return ', '.join(map(str, value))
    else:
        raise TypeError(f"Unsupported type for conversion: {type(value)}")

class StringUtils:
    def __init__(self):
    pass
