#include <stdio.h>

int binomial(int n,int k)
{
	int arr[n+1][k+1], i, j;

	for (i = 0; i <= n; ++i)
	{
		for (j = 0; j <= (k>i?i:k); ++j)
		{
			if(j == 0 || j == i)
			{
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
			}
		}
	}
	return arr[n][k];
}

int main()
{
	int n,k;
	printf("Enter n and k :");
	scanf("%d %d", &n, &k);

	printf("%d", binomial(n,k));
	return 0;
}