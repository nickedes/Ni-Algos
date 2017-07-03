def push(stack, top, element):
    stack.insert(top, element)
    return top + 1


def pop(stack, top):
    return top - 1


def maximum(stack, top):
    return max(stack[:top])


stack = []
top = 0
n = int(input())
for i in range(n):
    query = input()
    if query == '2':
        top = pop(stack, top)
    elif query == '3':
        print(maximum(stack, top))
    else:
        item = query.split()[1]
        top = push(stack, top, item)
