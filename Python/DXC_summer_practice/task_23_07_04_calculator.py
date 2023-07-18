def check_user_input(input):
    try:
        # Convert it into float
        val = float(input)
        print("Input is a float  number. Number = ", val)
        return True
    except ValueError:
        print("No.. input is not a number. It's a string")
        return False
    
def fibo(n):
    if n < 0:
       print("Incorrect input")
    elif n == 1:
        return 0
    elif n == 2:
        return 1
    else:
        return fibo(n-1) + fibo(n-2)

def add(num1, num2):
    return num1 + num2

def subtract(num1, num2):
    return num1 - num2

def multiply(num1, num2):
    return num1 * num2

def divide(num1, num2):
    if num2 != 0:
        return num1 / num2
    else:
        return "Error: Division by zero!"

def factorial(n): 
    # single line to find factorial
    return 1 if (n==1 or n==0) else n * factorial(n - 1)

def set_result(newr):
    oldr = newr

def get_result():
    result = 0

def default():# Get the input number
    num1 = float(input("Enter a number: "))
    if not check_user_input(num1):
        print("Bad input")

    # Get the operation from the user
    operation = input("Enter an operation (+, -, *, /, !, fi): ")


    if operation == 'fi':
        fibonachi = int(num1)
        result = fibo(fibonachi)
        print(f"Number:{fibonachi} from fibonachi is {result}")
        check_index = input("Enter 'y' if you want to continue (or 'q' to quit): ")
        if not check_index.__eq__("y"):
            exit()
        set_result(result)
        default()

    if operation == '!':
        result = factorial(num1)
        print(f"The factorial of {num1} is {result}")
        check_index = input("Enter 'y' if you want to continue (or 'q' to quit): ")
        if not check_index.__eq__("y"):
            exit()
        set_result(result)
        default()
        
    else:
        # Get the second number if it's a binary operation
        num2 = float(input("Enter another number (optional, type 00, to use result): "))
    
        if not check_user_input(num2):
            print("Bad input")
        if(num2.__eq__(00)):
            num2 = get_result()

        # Perform the requested operation
        if operation == '+':
            result = add(num1, num2)
        elif operation == '-':
            result = subtract(num1, num2)
        elif operation == '*':
            result = multiply(num1, num2)
        elif operation == '/':
            result = divide(num1, num2)
        else:
            result = "Error: Invalid operation!"

        print(f"The result of {num1} {operation} {num2} is {result}")

        check_index = input("Enter 'y' if you want to continue (or 'q' to quit): ")
        if check_index.__eq__("y"):
            set_result(result)
            default()
        else:
            exit()

default()
