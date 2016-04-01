import math
import scipy.stats


def average(x):
    assert len(x) > 0
    return float(sum(x)) / len(x)


def pearson_def(x, y):
    assert len(x) == len(y)
    n = len(x)
    assert n > 0
    avg_x = average(x)
    avg_y = average(y)
    diffprod = 0
    xdiff2 = 0
    ydiff2 = 0
    for idx in range(n):
        xdiff = x[idx] - avg_x
        ydiff = y[idx] - avg_y
        diffprod += xdiff * ydiff
        xdiff2 += xdiff * xdiff
        ydiff2 += ydiff * ydiff

    return diffprod / math.sqrt(xdiff2 * ydiff2)

x = [10, 9.8, 8, 7.8, 7.7, 7, 6, 5, 4, 2]
y = [200, 44, 32, 24, 22, 17, 15, 12, 8, 4]

print(pearson_def(x, y))
print(scipy.stats.spearmanr(x, y)[0])
