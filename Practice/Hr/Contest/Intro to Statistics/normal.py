# https://www.hackerrank.com/contests/intro-to-statistics/challenges/normal-distribution-1
from math import *


def normal(x, mean, Sd):
    """
    See https://en.wikipedia.org/wiki/Normal_distribution
    """
    z = (x-mean)/Sd
    value = (1/(Sd*sqrt(2*3.1416))) * (2.7183)**(-z*z/2)
    return value

print("%0.3f" % normal(40, 30, 4))
print("%0.3f" % (1 - normal(21, 30, 4)))
print("%0.3f" % (normal(35, 30, 4) - normal(30, 30, 4)))

print("%0.3f" % (normal(0, 0, 1)))
