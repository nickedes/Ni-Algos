def scoring(a, b, n, m, x):
    i, j, sumNum = 0, 0, 0
    while i < n and (sumNum+a[i]) <= x:
        sumNum += a[i]
        i += 1
    ans = i
    while j < m and i >= 0:
        sumNum += b[j]
        j += 1
        while sumNum > x and i > 0:
            i -= 1
            sumNum -= a[i]
        if sumNum <= x and i+j > ans:
            ans = i+j
    return ans


g = int(input())

for i in range(g):
    n, m, x = list(map(int, input().split()))
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    print(scoring(a, b, n, m, x))
