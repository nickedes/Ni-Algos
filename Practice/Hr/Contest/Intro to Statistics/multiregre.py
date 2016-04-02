from sklearn import linear_model
import numpy as np

x = input().split()
f, n = int(x[0]), int(x[1])

y = []
x = []
for i in range(n):
    line = input().split()
    # print(line)
    y += [float(line[-1])]
    x += [[float(j) for j in line[:-1]]]
# print(x)
# print(y)
x = np.vstack(x)
y = np.array(y)
regr = linear_model.LinearRegression()
regr.fit(x, y)

# testing
t = int(input())
for i in range(t):
    line = input().split()
    x = [float(j) for j in line]
    print(regr.predict(x)[0])
