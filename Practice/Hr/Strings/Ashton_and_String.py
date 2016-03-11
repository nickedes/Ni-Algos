# problem : https://www.hackerrank.com/challenges/ashton-and-string

test = int(input())
for t in range(test):
    string = input()
    k = int(input())
    substr = list()
    for i in range(len(string)):
        for j in range(i+1, len(string)+1):
            substr.append(string[i:j])
    substr.sort()
    print(substr)
    s = ''.join(x for x in substr)
    # print(s)
    print(s[k-1])
