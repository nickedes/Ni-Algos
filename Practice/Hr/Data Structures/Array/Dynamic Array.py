n, q = [int(x) for x in input().split()]
last = 0
s = []
result = [[] for _ in range(n)]
for i in range(q):
    query, x, y = [int(j) for j in input().split()]
    seq = (x ^ last) % n
    if query == 1:
        result[seq].append(y)
    elif query == 2:
        last = result[seq][y % len(result[seq])]
        print(last)
