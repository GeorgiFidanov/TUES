def sum_digits(integer):
    a = 0
    while integer:
        a += integer % 10
        integer //= 10
    return a


def to_digits(n):
    print("The original number is " + str(n))
    result_list = [int(x) for x in str(n)]
    print("The list from number is " + str(result_list))


def to_number(digits):
    for i in digits:
        print(i, end="")


def is_decreasing(seq):
    old = None
    for i in seq:
       if old is None:
           old = i
       else:
           if not (i < old):
               return False
    return True


def Fibonacci(number):
    current = 0
    n1 = 0
    n2 = 1
    while current < number:
        new = n1 + n2
        print(n1)
        n1 = n2
        n2 = new
        current += 1


if __name__ == '__main__':
    integer = 123456789
#    print(sum_digits(integer))
    n = 13435
#    to_digits(n)
    digits = [12, 16, 89]
#    to_number(digits)
    seq = [11, 10, 7, 3]
#    a = is_decreasing(seq)
#    print("-The sequence is decreasing? ")
#    if(a==1):
#        print("-True")
#    else:
#        print("-False")
    number = 13
#    Fibonacci(number)
