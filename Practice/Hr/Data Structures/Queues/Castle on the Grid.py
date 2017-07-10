from queue import Queue


def bfs(s, n, r):
    # s - source
    # r - reaching point
    S = Queue()
    S.put(s)
    while not S.empty():
        node = S.get()
        print(node)
        pass


n = int(input())
graph = []
for i in range(n):
    string = input()
    newrow = []
    for x in list(string):
        if x == '.':
            newrow.append(1)
        else:
            newrow.append(0)
    graph.append(newrow)

a, b, c, d = list(map(int, input().split()))

bfs((a, b, 0), n, (c, d))
