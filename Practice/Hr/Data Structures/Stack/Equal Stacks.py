n1, n2, n3 = input().strip().split(' ')
n1, n2, n3 = [int(n1), int(n2), int(n3)]
h1 = [int(h1_temp) for h1_temp in input().strip().split(' ')][::-1]
h2 = [int(h2_temp) for h2_temp in input().strip().split(' ')][::-1]
h3 = [int(h3_temp) for h3_temp in input().strip().split(' ')][::-1]
h = [h1, h2, h3]
ls = [sum(h1), sum(h2), sum(h3)]
while ls[0] != ls[1] or ls[0] != ls[2]:
    maxVal = max(ls)
    if ls.count(maxVal) == 1:
        index = ls.index(maxVal)
        item = h[index].pop()
        ls[index] -= item
    else:
        indices = []
        for i in range(len(ls)):
            if ls[i] == maxVal:
                indices.append(i)
        id1, id2 = indices
        if h[id1][-1] > h[id2][-1]:
            item = h[id1].pop()
            ls[id1] -= item
        else:
            item = h[id2].pop()
            ls[id2] -= item

# print(h)
print(ls[0])
