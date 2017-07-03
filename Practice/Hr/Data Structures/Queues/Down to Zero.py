# max limit
maxL = 100001
num = [-1]*maxL

num[0], num[1], num[2], num[3] = 0, 1, 2, 3

for i in range(maxL):
    if num[i] == -1 or (num[i] > num[i-1] + 1):
        num[i] = num[i-1] + 1
    for j in range(1, i+1):
        if j*i < maxL and (num[j*i] == -1 or num[i] + 1 < num[j*i]):
            num[j*i] = num[i] + 1

q = int(input())
for i in range(q):
    n = int(input())
    print(num[n])
