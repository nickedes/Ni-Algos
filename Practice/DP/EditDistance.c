#include <stdio.h>

#define MAX 100

int min(int a, int b, int c)
{
	return a > b ? (b > c ? c : b) : (a > c ? c : a) ;
}

int editDisRecur(char str1[], char str2[], int n, int m)
{
	if(n == 0 || m == 0)
		return (n > 0 ? n : m);

	if(str1[n-1] == str2[m-1])
		return editDisRecur(str1, str2, n-1, m-1);

	return 1 + min( editDisRecur(str1, str2, n, m-1),
					editDisRecur(str1, str2, n-1, m),
					editDisRecur(str1, str2, n-1, m-1) );
}

int editDistance(char str1[], char str2[], int n, int m)
{
	int i, j, table[n+1][m+1];

	for (i = 0; i < n+1; ++i)
	{
		for (j = 0; j < m+1; ++j)
		{
			if(i == 0)
				table[i][j] = j;
			else if(j == 0)
				table[i][j] = i;
			else if( str1[i] == str2[j])
			{
				table[i][j] = table[i-1][j-1];
			}
			else
			{
				table[i][j] = 1 + min(table[i][j-1], table[i-1][j], table[i-1][j-1]);
			}
		}
	}

	return table[n][m];
}

int main()
{
	int i, n = 0, m = 0;
	char str1[MAX], str2[MAX];
	printf("enter 2 strings\n");
	scanf("%s", str1);
	scanf("%s", str2);

	for (i = 0; str1[i] != '\0'; ++i)
		n++;

	for (i = 0; str2[i] != '\0'; ++i)
		m++;

	printf("%d\n", editDisRecur(str1, str2, n, m));

	printf("%d\n", editDistance(str1, str2, n, m));
}