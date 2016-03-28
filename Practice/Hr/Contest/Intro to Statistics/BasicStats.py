# Problem :
# https://www.hackerrank.com/contests/intro-to-statistics/challenges/basic-statistics-warmup-2

import numpy


def median(lst):
    return numpy.median(numpy.array(lst))


def mode(arr):
    m = max([arr.count(a) for a in arr])
    y = [x for x in arr if arr.count(x) == m]
    return min(y)

N = int(input())
numbers = input().split()
numbers = [int(x) for x in numbers]
mean = sum(numbers)/len(numbers)
sd = 0.0
for x in numbers:
    sd += x**2
sd = sd/len(numbers) - mean**2
med = median(numbers)
print("%0.1f" % (mean))
print("%0.1f" % (med))
print(mode(numbers))
print("%0.1f" % (sd**0.5))
