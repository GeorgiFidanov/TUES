def print_hi(name):
    print(f'Hi, {name}')


def sum_of_digits(n):
    p = 0
    while n:
        p += n % 10
        n //= 10
    return p


# def find_dictionary


if __name__ == '__main__':

    my_dictionary = {'kucheto skacha mnogo burzo'}
    n = 1234

    print_hi('PyCharm')
    print(sum_of_digits(n))
