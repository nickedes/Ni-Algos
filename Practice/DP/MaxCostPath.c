#include <stdio.h>
#define R 100
#define C 100

int min(int a, int b, int c)
{
	return (a > b) ? (b > c ? c : b) : (a > c ? c : a);
}

int minCost(int cost[R][C], int m, int n)
{
	int path[m][n], i, j;

	path[0][0] = cost[0][0];
	for (i = 1; i < m; ++i)
	{
		path[i][0] = path[i-1][0] + cost[i][0];
	}

	for (i = 1; i < n; ++i)
	{
		path[0][i] = path[0][i-1] + cost[0][i];
	}

	for (i = 1; i < m; ++i)
	{
		for (j = 1; j < n; ++j)
		{
			path[i][j] = cost[i][j] + min(path[i-1][j], path[i][j-1], path[i-1][j-1]);
		}
	}

	return path[m-1][n-1];
}

int main()
{
	int m, n, i, j, cost[R][C];
	printf("Enter M & N: ");
	scanf("%d %d", &m, &n);

	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			scanf("%d", &cost[i][j]);
		}
	}

	printf("%d\n", minCost(cost, m, n));
	return 0;
}