from math import sqrt

size = 9735
arr = [False]*(size+1)

for p in range(2, int(sqrt(size))+1):
    if not arr[p]:
        for k in range(2*p, size+1, p):
            arr[k] = True

primes = []
for p in range(2, size+1):
    if not arr[p]:
        primes.append(p)

print(primes)

n, q = list(map(int, input().split()))
plates = list(map(int, input().split()))
a = [plates]
b = []
for i in range(q):
    b.append([])

for i in range(1, q+1):
    prime = primes[i-1]
    length = len(a[i-1])
    while length > 0:
        item = a[i-1].pop()
        length -= 1
        if item % prime == 0:
            b[i].append(item)
        else:
            if i >= len(a):
                a.append([])
            a[i].append(item)
