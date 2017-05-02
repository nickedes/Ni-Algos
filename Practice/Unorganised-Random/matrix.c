#include <stdio.h>

int main()
{
	int n, i, j;
	scanf("%d", &n);

	int arr[n][n];

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	int rsum[n], csum[n];

	for (i = 0; i < n; ++i)
	{
		rsum[i] = 0;
		for (j = 0; j < n; ++j)
		{
			rsum[i] += arr[i][j];
		}
	}

	for (i = 0; i < n; ++i)
	{
		csum[i] = 0;
		for (j = 0; j < n; ++j)
		{
			csum[i] += arr[j][i];
		}
	}

	for (i = 0; i < n; ++i)
	{
		printf("%dth row sum : %d\n", i+1, rsum[i]);
		printf("%dth col sum : %d\n", i+1, csum[i]);
	}

	printf("lil\n");

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			if(rsum[i] == csum[j])
			{
				printf("%d %d\n", i, j);
			}
		}
	}

	return 0;
}