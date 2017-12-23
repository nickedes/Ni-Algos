# http://codeforces.com/contest/899/problem/A
n = int(input())

people = [int(x) for x in input().split()]

count_2, count_3 = 0, 0

for x in people:
    if x == 2:
        count_2 += 1
    else:
        count_3 += 1

if count_2 < count_3:
    print(count_2 + int((count_3 - count_2)/3))
else:
    print(count_3)
