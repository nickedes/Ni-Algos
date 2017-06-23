# https://www.codechef.com/problems/COINS
import sys

def get(res, n):
    if n < 50000:
        return res[n]
    return max( n, sum( (get(res, int(n/2)), get(res, int(n/3)), get(res, int(n/4))) ))

    
line = sys.stdin
res = [0, 1]
for x in range(2, 50000):
    res.append( max(x, sum( (res[int(x/2)], res[int(x/3)], res[int(x/4)]) ) ) )

while True:
    x = line.readline()
    if x is '':
        break
    n = int(x)
    if n < 50000:
        print(res[n])
    else:
        print(int(get(res, n)))