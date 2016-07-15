#include <stdio.h>

int min(x, y, z)
{
	return x > y ? (y > z ? z : y):(x > z? z : x);
}

int main()
{
	int l1, l2, i, j;
	char str1[100], str2[100];

	printf("Enter both strings:\n");
	scanf("%s", str1);
	scanf("%s", str2);

	for(i=0; str1[i]!='\0'; ++i);
	l1 = i;
	for(i=0; str2[i]!='\0'; ++i);
	l2 = i;
	
	int dp[l1+1][l2+1];

	for (i = 0; i <= l1; ++i)
	{
		for (j = 0; j <= l2; ++j)
		{
			if(i == 0)
				dp[i][j] = j;

			else if(j == 0)
				dp[i][j] = i;

			else if(str1[i] == str2[j])
				dp[i][j] = dp[i-1][j-1];
			else
			{
				dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
			}
		}
	}
	printf("%d\n", dp[l1][l2]);
	return 0;
}