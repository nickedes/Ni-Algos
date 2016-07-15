#include <stdio.h>

int max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	int i, len, c, j;
	char arr[100];
	printf("Enter string\n");
	scanf("%s", arr);

	for(i = 0; arr[i] != '\0'; ++i);
	len = i;
	
	int dp[len][len];

	for (i = 0; i < len; ++i)
		dp[i][i] = 1;

	for(c = 2; c <= len; c++)
	{
		for(i = 0; i < len-c+1; ++i)
		{	
			j = c+i-1;
			if(arr[i] == arr[j] && c == 2)
				dp[i][j] = 2;
			else if(arr[i] == arr[j])
				dp[i][j] = dp[i+1][j-1] + 2;
			else
				dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
		}
	}
	printf("%d\n", dp[0][len-1]);
	return 0;
}