#include <stdio.h>

int main()
{
	int n, arr[100], i, j;
	printf("Enter N : \n");
	scanf("%d", &n);

	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int lis[n];
	for (i = 0; i < n; ++i)
		lis[i] = arr[i];

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < i; ++j)
		{
			if(arr[j] < arr[i] && lis[j] + arr[i] > lis[i])
				lis[i] = arr[i] + lis[j];
		}
	}
	int max = lis[0];
	for(i = 0; i < n; i++)
	{
		// printf("%d ", lis[i]);
		if(max < lis[i])
			max = lis[i];
	}

	printf("%d\n", max);
	return 0;
}