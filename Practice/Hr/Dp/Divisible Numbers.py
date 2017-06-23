n = int(input())


def product(n):
    prod = 1
    for x in str(n):
        prod = prod*int(x)
    return prod


def sum_digits(n):
    r = 0
    while n:
        r, n = r + n % 10, n // 10
    return r


def test(m):
    if '0' in str(m):
        return False
    if sum_digits(m) < product(m):
        return False
    return True


def noDigits(m):
    return len(str(m))


def findM(n):
    m = n
    while m >= n:
        if not test(m):
            m = m + n
        else:
            # print(m)
            print(noDigits(m))
            break
    pass

findM(n)
