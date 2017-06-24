def value(n, k):
    num = 1
    den = 1
    limit = max(n-k, k)
    for i in range(limit+1, n+1):
        num *= i
    for i in range(2, min(n-k, k) + 1):
        den *= i
    return num/den


def main():
    test = int(input())
    for t in range(test):
        string = input()
        n, k = string.split()
        n, k = int(n), int(k)
        print(int(value(n-1, n-k)))
    return 0

main()
