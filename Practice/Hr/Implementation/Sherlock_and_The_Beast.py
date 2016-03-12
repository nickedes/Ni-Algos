# Problem : https://www.hackerrank.com/challenges/sherlock-and-the-beast
tests = int(input())
for t in range(tests):
    y = int(input())
    z = y
    while(z % 3 != 0):
        z -= 5
    if(z < 0):
        print('-1')
    else:
        print(z*'5'+(y-z)*'3')
