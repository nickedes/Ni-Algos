x = 1734486

y = []
for i in range(10):
    int_x = x
    x = x + 28000
    print(str(int_x) + " + 28000" + " = " + str(x))
    y.append(x)

for i in range(2):
    int_x = x
    x = x + 29000
    print(str(int_x) + " + 29000" + " = " + str(x))
    y.append(x)

print(sum(y))
print(sum(y)/12*8.7)
