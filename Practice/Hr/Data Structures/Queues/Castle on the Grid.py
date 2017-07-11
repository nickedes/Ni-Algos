from queue import Queue


def bfs(s, n, r, graph):
    # s - source
    # r - reaching point
    S = Queue()
    S.put(s)
    visited = set()
    a, b = s[0:2]
    S.put((a, b + 1, 1, 1))
    S.put((a + 1, b, 0, 1))
    S.put((a, b - 1, 1, 1))
    S.put((a - 1, b, 0, 1))
    visited.add((a, b))
    while not S.empty():
        node = S.get()
        a, b, direct, cost = node
        if (a, b) not in visited and a >= 0 and a < n and b >= 0 and b < n:
            if not graph[a][b]:
                continue
            if (a, b) == r:
                print(cost)
                break
            # print(node)
            S.put((a, b + 1, 1, cost + 1 if direct == 0 else cost))
            S.put((a + 1, b, 0, cost + 1 if direct == 1 else cost))
            S.put((a, b - 1, 1, cost + 1 if direct == 0 else cost))
            S.put((a - 1, b, 0, cost + 1 if direct == 1 else cost))
            visited.add((a, b))


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

bfs((a, b, 0, 0), n, (c, d), graph)
