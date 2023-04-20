def simple(n):
    i = 2
    if n < 1:
        print("Wrong number is:", n)
        return -1

    if n == 1:
        print("One is:", n)
        return 1

    if n == i:
        print("It's simple:", n)
        return n

    if n % i == 0:
        print("It's not simple:", n)
        return 1

    while n % i != 0:
        i = i + 1

        if n % i == 0:
            if n == i:
                print("It's simple:", n)
                return n

            print("It's not simple:", n)
            return 1


if __name__ == '__main__':
    loop = 0
    while loop <= 100:
        loop = loop + 1
        simple(loop)
