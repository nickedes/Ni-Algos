from queue import Queue

q = Queue()
n = int(input())
for i in range(n):
    string = input()
    if string == '2':
        if not q.empty():
            q.get()
    elif string == '3':
        print(q.queue[0])
    else:
        _, x = [int(x) for x in string.split()]
        q.put(x)
