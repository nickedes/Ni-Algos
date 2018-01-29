#include <stdio.h>

int find(int s[], int a[], int low, int high)
{
	int n = high - low + 1;
	int mid = n/2;

	if(n == 1)
	{
		printf("%d\n", 1);
		return s[low+mid];
	}
	else if(s[low + mid] < a[low + mid])
	{
		printf("here 1:%d %d\n", low, high);
		return find(s, a, low, mid);
	}
	else
	{
		printf("here 2: %d %d\n", low, high);
		return find(s, a, mid, high);
	}
}


int main()
{
	int s[6] = {25, 26, 27, 28, 29, 30};
	int a[5] = {25,26,27,28,29};
	printf("%d\n", find(s, a, 0, 4));
	return 0;
}