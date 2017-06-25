n, q = [int(x) for x in input().split()]
ref = '1'*n
coin = '0'*n
for i in range(q):
    num, a, b = [int(x) for x in input().split()]
    if num == 1:
        print(coin.count('1'))
    else:
        res = str(int(ref[a: b+1]) - int(coin[a: b+1]))
        comp_Str = '0'*(len(coin[a: b+1]) - len(res))+res
        coin = coin[:a] + comp_Str + coin[b+1:]
