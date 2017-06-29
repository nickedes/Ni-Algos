# https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/mancunian-and-liverbird-go-bar-hopping-2/
def getLR(val, n):
    left = [1]*n
    for i in range(len(val)):
        if val[i] == 0:
            left[i+1] = left[i] + 1

    right = [1]*n
    length = len(val)
    for i in range(len(val)):
        index = length - i - 1
        if val[index] == 1:
            right[index] = right[index+1] + 1
    # print(left, right)
    return left, right


n = int(input())
val = list(map(int, input().split()))
toggledVal = list(map(lambda x: 1-x, val))

d = dict()

d[0] = getLR(val, n)
d[1] = getLR(toggledVal, n)

q = int(input())
state = 0
for i in range(q):
    string = input()
    if string == 'U':
        state = 1 - state
    else:
        node = int(string.split()[1])
        left, right = d[state]
        reachableNodes = left[node-1] + right[node-1] - 1
        print( reachableNodes )
