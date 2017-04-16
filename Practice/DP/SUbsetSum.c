#include <stdio.h>

int recurSubsetSum(int arr[], int n, int sum)
{
	if(sum == 0)
		return 1;
	if(n <= 0 && sum > 0)
		return 0;
	if(sum <  arr[n-1])
		return recurSubsetSum(arr, n-1, sum);
	return recurSubsetSum(arr, n-1, sum - arr[n-1]) || recurSubsetSum(arr, n-1, sum);
}

int DPSubsetSum(int arr[], int n, int sum)
{
	int i, j, table[sum+1][n+1];

	for (i = 0; i < n + 1; ++i)
		table[0][i] = 1;

	for (i = 0; i < sum + 1; ++i)
	{
		for (j = 1; j < n + 1; ++j)
		{
			if(i < arr[j-1])
			{
				table[i][j] = table[i][j-1];
			}
			else
			{
				table[i][j] = table[i - arr[j-1]][j-1] || table[i][j-1];
			}
		}
	}

	return table[sum][n];
}

int main()
{
	int n, i, sum = 0;
	printf("enter no. of elements : ");
	scanf("%d", &n);
	int arr[n];
	printf("enter elements : ");
	for (i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	printf("enter sum : ");
	scanf("%d", &sum);

	if(recurSubsetSum(arr, n, sum))
		printf("Yes\n");
	else
		printf("No\n");

	if(DPSubsetSum(arr, n, sum))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}