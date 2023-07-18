def swap(a, b):
    c = a
    a = b
    b = c
    return a, b


def subtract_from_bigger_number(a, b):
    if (a < b):
        a, b = swap(a, b)
    
    c = a - b
    print(c)


subtract_from_bigger_number(5, 2)
