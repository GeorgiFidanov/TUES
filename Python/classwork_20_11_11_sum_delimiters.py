def deliteli(n):
    sum_of_deliteli = 1
    i = 1
    while i < n:
       if n % i != 0:
           return
       else:
           sum_of_deliteli = sum_of_deliteli + i
    i = i + 1
    if i == n:
        return sum_of_deliteli
    return sum_of_deliteli


if __name__ == '__main__':
   deliteli(8)
