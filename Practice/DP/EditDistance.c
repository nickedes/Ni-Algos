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
}