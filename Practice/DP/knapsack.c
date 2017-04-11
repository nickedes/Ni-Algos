#include <stdio.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int knapsackRecursive(int weight[], int profit[], int n, int knapSackWeight)
{
	if(n == 0 || knapSackWeight == 0)
		return 0;

	if(weight[n-1] > knapSackWeight)
		return knapsackRecursive(weight, profit, n-1, knapSackWeight);

	return max( profit[n-1] + knapsackRecursive(weight, profit, n-1, knapSackWeight - weight[n-1]), knapsackRecursive(weight, profit, n-1, knapSackWeight));
}

int knapsackDP(int weight[], int profit[], int n, int knapSackWeight)
{
	int table[n+1][knapSackWeight+1], i, j;

	for (i = 0; i < n+1; ++i)
	{
		table[i][0] = 0;
	}

	for (j = 0; j < knapSackWeight+1; ++j)
	{
		table[0][j] = 0;
	}

	for (i = 1; i < n+1; ++i)
	{
		for (j = 0; j < knapSackWeight+1; ++j)
		{
			if(weight[i-1] > j)
				table[i][j] = table[i-1][j];
			else
				table[i][j] = max( profit[i-1] + table[i-1][j - weight[i-1]], table[i-1][j]);
		}
	}

	return table[n][knapSackWeight];
}

int main()
{
	int i, knapSackWeight, items, MaxProfit = 0;
	printf("Enter no. of items : \n");
	scanf("%d", &items);

	printf("Enter capacity of knapsack:\n");
	scanf("%d", &knapSackWeight);

	int weight[items], profit[items];

	printf("Enter weights : \n");
	for (i = 0; i < items; ++i)
		scanf("%d", &weight[i]);
	
	printf("Enter profits : \n");
	for (i = 0; i < items; ++i)
		scanf("%d", &profit[i]);

	MaxProfit = knapsackRecursive(weight, profit, items, knapSackWeight);
	printf("Max profit : %d\n", MaxProfit);

	MaxProfit = knapsackDP(weight, profit, items, knapSackWeight);
	printf("Max profit : %d\n", MaxProfit);
}