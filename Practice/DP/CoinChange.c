#include <stdio.h>

int change(int N, int coin[], int m)
{
	if(N == 0)
		return 1;

	if(N < 0)
		return 0;

	if(m < 1 && N > 0)
		return 0;

	return change(N, coin, m-1) + change(N-coin[m-1], coin, m);
}

int value(int N, int coin[], int m)
{
	int i, j, table[N+1][m], x, y;

	for (i = 0; i < m; ++i)
		table[0][i] = 1;

	for (i = 1; i < N+1; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			x = (j > 0) ? table[i][j-1] : 0;
			y = (i >= coin[j]) ? table[i-coin[j]][j] : 0;
			table[i][j] = x+y;
		}
	}

	return table[N][m-1];
}

int main()
{
	int N, m, i;
	printf("Enter N:");
	scanf("%d", &N);

	printf("Enter no. of coins:");
	scanf("%d", &m);

	int coin[m];

	printf("Enter valued coins:");
	for (i = 0; i < m; ++i)
		scanf("%d", &coin[i]);

	printf("%d\n", change(N, coin, m));	
	printf("%d\n", value(N, coin, m));	
	return 0;
}