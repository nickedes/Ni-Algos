n = int(input())
strs = []
for i in range(n):
    strs.append(input())

q = int(input())
for i in range(q):
    check = input()
    if check in strs:
        print(strs.count(check))
    else:
        print(0)
