#include <stdio.h>

int findMedian(int arr1[], int arr2[], int n)
{
	if(n < 1)
	{
		printf("not found!\n");
		return -1;
	}

	if(n == 1)
	{
		return (arr1[0] + arr2[0])/2;
	}

	else if(n == 2)
	{
		return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1]))/2;
	}

	int m1, m2;
	m1 = getMedian(arr1, n);
	m2 = getMedian(arr2, n);
	if(m1 == m2)
	{
		return m1;
	}
	else if(m1 < m2)
	{
		if(n%2 == 0)
			return findMedian(arr1 + n/2 - 1, arr2, n - n/2 + 1);
		return findMedian(arr1 + n/2, arr2, n - n/2);
	}

	if(n%2 == 0)
		return findMedian(arr1, arr2 + n/2 - 1, n - n/2 + 1);
	return findMedian(arr1, arr2 + n/2, n - n/2);
}


int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a > b ? b : a;
}

int getMedian(int arr[], int n)
{
	if(n % 2 == 0)
		return (arr[n/2-1] + arr[n/2])/2;
	else
		return arr[n/2];
}

int main()
{
	int n;
	printf("enter n: ");
	scanf("%d", &n);

	int arr1[n], arr2[n], i;
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &arr1[i]);
	}

	for (i = 0; i < n; ++i)
	{
		scanf("%d", &arr2[i]);
	}

	printf("%d\n", findMedian(arr1, arr2, n));

	return 0;
}