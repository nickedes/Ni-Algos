n, m = [int(x) for x in input().split()]
val = [0]*(n+1)
maxval = 0
for i in range(m):
    a, b, k = [int(j) for j in input().split()]
    val[a] += k
    if b+1 <= n:
        val[b+1] -= k
newmax = 0
for i in range(1, n+1):
    newmax += val[i]
    if maxval < newmax:
        maxval = newmax

print(maxval)
