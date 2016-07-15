#include <stdio.h>

int main()
{
	int i, arr[100], num, j;
	printf("Enter num\n");
	scanf("%d", &num);

	int lis[num];
	for(i = 0; i < num; i++)
		scanf("%d", &arr[i]);

	for(i = 0; i < num; ++i)
		lis[i] = 1;

	for(i = 0; i < num; ++i)
	{
		for (j = 0; j < i; ++j)
		{
			if(arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
		}
	}

	int max = lis[0];
	for (i = 1; i < num; ++i)
	{
		if(max < lis[i])
			max = lis[i];
	}
	printf("%d\n", max);
	return 0;
}