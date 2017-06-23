string = input()
n, k = string.split()
n, k = int(n), int(k)
stats = [0]*(n+1)
for i in range(k):
	string = input()
	if string == 'CLOSEALL':
		stats = [0]*(n+1)
		print(0)
	else:
		_, clicked = string.split()
		stats[int(clicked)] = not stats[int(clicked)]
		print(sum(stats))
