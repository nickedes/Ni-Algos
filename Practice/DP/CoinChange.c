#include <stdio.h>

int rec(int n, int num_coins, int coins[])
{
	if(n == 0)
		return 1;
	else if(n < 0)
		return 0;
	else if(num_coins <= 0)
		return 0;
	return rec(n, num_coins-1, coins) + rec(n-coins[num_coins-1], num_coins, coins);
}

int main()
{
	int N, coins[100], num_coins, i, j;

	printf("Enter N and num_coins \n");
	scanf("%d %d", &N, &num_coins);

	int sum[N+1];
	for(i = 0; i < num_coins; i++)
		scanf("%d", &coins[i]);

	printf("%d\n", rec(N, num_coins, coins));

	for(i = 0; i <= N; ++i)
		sum[i] = 0;
	
s	um[0] = 1;
	for(i = 0; i < num_coins; i++)
	{
		for(j = coins[i]; j <= N; j++)
			sum[j] += sum[j-coins[i]];
	}
	printf("%d\n", sum[N]);
	return 0;
}