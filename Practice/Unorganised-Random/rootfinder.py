# https://www.codechef.com/problems/TREEROOT
t = int(input())
for i in range(t):
    n = int(input())
    root = 0
    for j in range(n):
        _id, _sum = [int(x) for x in input().split()]
        root += _id - _sum
    print(root)
