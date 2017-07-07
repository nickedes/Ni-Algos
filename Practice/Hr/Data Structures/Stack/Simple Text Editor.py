s = ''
q = int(input())
history = []
for i in range(q):
    string = input()
    if string == '4':
        s = history.pop()
    else:
        string = string.split()
        if string[0] == '1':
            history.append(s)
            s += string[1]
        elif string[0] == '2':
            history.append(s)
            k = int(string[1])
            s = s[:-k]
        elif string[0] == '3':
            k = int(string[1])
            print(s[k-1])
