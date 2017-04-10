#include <stdio.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int LengthOfPal(char string[], int low, int high)
{
	if(low == high)
		return 1;

	if(string[low] == string[high] && low + 1 == high)
		return 2;

	if(string[low] == string[high])
		return 2 + LengthOfPal(string, low + 1, high - 1);
	else
		return max(LengthOfPal(string, low + 1, high), LengthOfPal(string, low, high - 1));
}

int LongestPal(char string[], int length)
{
	int L[length][length], i, j, c;

	for (i = 0; i < length; ++i)
	{
		L[i][i] = 1;
	}

	for (c = 2; c <= length; ++c)
	{
		for (i = 0; i < length - c + 1; ++i)
		{
			j = i + c - 1;
			if(string[i] == string[j] && i + 1 == j)
			{
				L[i][j] = 2;
			}
			else if(string[i] == string[j])
			{
				L[i][j] = 2 + L[i+1][j-1];
			}
			else
			{
				L[i][j] = max(L[i][j-1], L[i+1][j]);
			}
		}
	}

	return L[0][length-1];
}

int main(int argc, char const *argv[])
{
	int i, n;
	char string[100];
	printf("enter string\n");
	scanf("%s", string);

	for (i = 0; string[i] != '\0'; ++i);
	// printf("%d\n", i);
	// printf("%s\n", string);

	printf("%d\n", LengthOfPal(string, 0, i-1));
	printf("%d\n", LongestPal(string, i));
	return 0;
}