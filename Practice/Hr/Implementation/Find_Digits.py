# Problem : https://www.hackerrank.com/challenges/find-digits
Tests = int(input())
for t in range(Tests):
    N = int(input())
    count = 0
    digits = list(str(N))
    for x in digits:
        if int(x) != 0 and N % int(x) == 0:
            count += 1
    print(count)
