def print_hi(name):
    print(f'Hi, {name}')

my_dictionary = {'kucheto skacha mnogo burzo'}

def sum_of_digits(n):
    p = 0
    while n:
        p += n % 10
        n //= 10
    return p


print_hi("Ela")
print(sum_of_digits(1234))
