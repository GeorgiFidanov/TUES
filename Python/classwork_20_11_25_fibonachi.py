# the number represents which fibonachi number we search
def fibo(n):
    if n < 0:
       print("Incorrect input")
    elif n == 1:
        return 0
    elif n == 2:
        return 1
    else:
        return fibo(n-1) + fibo(n-2)


print(fibo(10))  # currently we search the tenth
