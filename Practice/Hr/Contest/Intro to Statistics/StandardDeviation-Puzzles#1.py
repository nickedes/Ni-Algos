"""
Problem : https://www.hackerrank.com/contests/intro-to-statistics/challenges/standard-deviation-puzzles-1
"""

numbers = [1, 2, 3]
mean = sum(numbers)/len(numbers)
sd = 0.0
for x in numbers:
    sd += x**2
sd = (sd/len(numbers) - mean**2)**0.5
