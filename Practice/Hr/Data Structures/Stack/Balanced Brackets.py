
def push(stack, top, element):

    if top == 0:
        stack.insert(top, element)
    else:
        topEle = stack[top - 1]
        if (topEle == '[' and element == ']') or (topEle == '{' and element == '}') or (topEle == '(' and element == ')'):
            top = pop(stack, top)
        else:
            stack.insert(top, element)
    return top + 1


def pop(stack, top):
    stack.pop()
    return top - 2



n = int(input())
for i in range(n):
    stack = []
    top = 0
    string = input()
    for i in string:
        top = push(stack, top, i)
    # analyse stack`
    if top == 0 and stack == []:
        print('YES')
    else:
        print('NO')
