"""
It is well known from elementary number
theory that there are infinitely many integral solutions of
the equation ax — by = 1.
"""
import math


def infinite():
    a, b = 13, 51
    for x in range(1000):
        for y in range(1000):
            if a*x - b*y == 1:
                print(x, y)


def factorial(n):
    """
    """
    return math.factorial(n)


def transcendental():
    """
    Just an example
    """
    c = 2
    m = 50
    number = 0
    for power in range(m):
        number += c**(-factorial(power))
        print(number)
    # print(number)


transcendental()
