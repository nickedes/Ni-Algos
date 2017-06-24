# https://www.codechef.com/problems/PALIN
def isPalindrome(num):
    return str(num) == str(num)[::-1]


def nextPal(num):
    num += 1
    while not isPalindrome(num):
        num += 1
    return num


t = int(input())

for i in range(t):
    num = int(input())
    print(nextPal(num))
