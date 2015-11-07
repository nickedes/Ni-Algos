# Problem : https://www.hackerrank.com/challenges/fibonacci-modified
a = raw_input()
a, b, n = a.split()
a, b, n = int(a), int(b), int(n)
for i in range(2, n):
    t = b*b + a
    a, b = b, t

print t
