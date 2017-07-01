from queue import Queue

key, lock = [int(x) for x in input().split()]
n = int(input())
val = list(map(int, input().split()))
result = [-1]*100001

q = Queue()
q.put(key)
result[key] = 0

while not q.empty():
    item = q.get()
    if item == lock:
        break
    for i in range(n):
        x = val[i]
        x = x*item
        x %= 100000
        if result[x] == -1:
            result[x] = result[item] + 1
            q.put(x)

print(result[lock])
