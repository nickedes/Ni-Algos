n, d = [int(x) for x in input().split()]
val = input().split()
print(' '.join(val[d:] + val[:d]))