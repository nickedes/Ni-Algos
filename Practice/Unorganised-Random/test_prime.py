import math


def is_prime(n):
    if n == 2:
        return True
    if n % 2 == 0 or n <= 1:
        return False

    sqr = int(math.sqrt(n)) + 1

    for divisor in range(3, sqr, 2):
        if n % divisor == 0:
            return False
    return True


c = 0
for i in range(1, 1000):
    # print(i)
    if 2**(i-1) % i == 1:
        if not is_prime(i):
            print(i)
        c = c + 1

# print(c)
