import math

def convert_temperature(temperature):
    try:
        value = float(temperature[:-1]) # get the numerical value
        unit = temperature[-1].upper()  # get the metric value

        if unit == 'C':
            celsius = value
            fahrenheit = (9/5) * celsius + 32
            kelvin = celsius + 273.15
            return f"{math.ceil(celsius)}C = {math.ceil(fahrenheit)}F = {math.ceil(kelvin)}K"

        elif unit == 'F':
            fahrenheit = value
            celsius = (5/9) * (fahrenheit - 32)
            kelvin = celsius + 273.15
            return f"{math.ceil(celsius)}C = {math.ceil(fahrenheit)}F = {math.ceil(kelvin)}K"

        elif unit == 'K':
            kelvin = value
            celsius = kelvin - 273.15
            fahrenheit = (9/5) * celsius + 32
            return f"{math.ceil(celsius)}C = {math.ceil(fahrenheit)}F = {math.ceil(kelvin)}K"

        else:
            return "Invalid unit. Please use 'C' for Celsius, 'F' for Fahrenheit, or 'K' for Kelvin."

    except ValueError:
        return "Invalid input. Please provide a numeric value followed by 'C', 'F', or 'K'."

# Example usage
temperature = input("Enter temperature to convert (e.g., 30C, 78F, 300K): ")
result = convert_temperature(temperature)
print(result)
