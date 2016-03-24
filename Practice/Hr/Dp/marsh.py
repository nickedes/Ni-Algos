m, n = map(int, input().strip().split())
L = []
for _ in range(m):
    L.append(input())
perimeter = 0

up = [[-1 if L[0][j] == 'x' else 0 for j in range(n)]]
for i in range(1, m):
    up.append([-1 if L[i][j] == 'x' else up[i-1][j]+1 for j in range(n)])

left = []
for i in range(m):
    row = [-1] if L[i][0] == 'x' else [0]
    for j in range(1, n):
        row.append(-1 if L[i][j] == 'x' else row[j-1]+1)
    left.append(row)

for r2 in range(m-1, 0, -1):
    for c2 in range(n-1, 0, -1):
        if L[r2][c2] == 'x':
            continue      # If second corner has marsh
        r1 = r2-1
        c1 = c2-1
        limr1 = r2-up[r2][c2]               # Limits for first corner such that
        # sides meeting at second corner are marsh-free
        limc1 = c2-left[r2][c2]
        while (r1 >= limr1 and c1 >= limc1):
            if L[r1][c1] == 'x':           # if first corner has marsh
                r1 -= 1                     # move to row above since
                # current row would always have marsh
                c1 = c2-1
                continue

            # if first-corner's sides
            if up[r2][c1] >= (r2-r1) and left[r1][c2] >= (c2-c1):
                # dont have marsh
                perimeter = max(perimeter, r2+c2-r1-c1)

            if c1 == limc1:
                c1 = c2-1
                r1 -= 1
            else:
                c1 -= 1

if perimeter:
    print(2*perimeter)
else:
    print("impossible")
