# https://www.hackerrank.com/challenges/two-two


def conv_int(string):
    val = 0
    for x in string:
        val = val*10 + int(x)
    return val


def is_power2(num):
    """states if a number is a power of two"""
    return num != 0 and ((num & (num - 1)) == 0)

if __name__ == '__main__':
    tests = int(input())
    for t in range(tests):
        s = input()
        count = 0
        for j in range(1, len(s)+1):
            for i in range(len(s)-j+1):
                if is_power2(conv_int(s[i:i+j])) and s[i] != '0':
                    count += 1
        print(count)
