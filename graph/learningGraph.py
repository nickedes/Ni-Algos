# https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/monk-learning-graph-3/description/
n, m, k = [int(x) for x in input().split()]

val = [int(x) for x in input().split()]

graph = dict()
for i in range(1, n+1):
    graph[i] = list()

for i in range(m):
    x, y = [int(z) for z in input().split()]
    graph[x].append(y)
    graph[y].append(x)

for i in range(1, n+1):
    if len(graph[i]) >= k:
        print(sorted(graph[i], key=lambda s: (
            val[s-1], s-1), reverse=True)[k-1])
    else:
        print(-1)
