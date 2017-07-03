# https://www.hackerrank.com/challenges/maximum-element


def push(stack, maxStack, top, element):
    stack.insert(top, element)
    if top == 0:
        maxStack.insert(top, element)
    else:
        maximum = maxStack[top - 1]
        if maximum > element:
            maxStack.insert(top, maximum)
        else:
            maxStack.insert(top, element)
    return top + 1


def pop(stack, top):
    return top - 1


def maximum(maxStack, top):
    return maxStack[top - 1]


stack = []
maxStack = []
top = 0
n = int(input())
for i in range(n):
    query = input()
    if query == '2':
        top = pop(stack, top)
    elif query == '3':
        print(maximum(maxStack, top))
    else:
        item = int(query.split()[1])
        top = push(stack, maxStack, top, item)
