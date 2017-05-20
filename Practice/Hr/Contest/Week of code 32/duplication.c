#include <stdio.h>

int main()
{
	int q, i, j;
	scanf("%d", &q);

	int l, query[1000], max = -1;
	for (i = 0; i < q; ++i)
	{
		scanf("%d", &query[i]);
		if(max < query[i])
		{
			max = query[i];
		}
	}
	int arr[max+1];
	arr[0] = 0;
	for (i = 1; i < max+1; i=i*2)
	{
		for (j = i; j < 2*i && j < max+1; ++j)
		{
			arr[j] = 1 - arr[j-i];
		}
	}

	for (l = 0; l < q; l++)
	{
		printf("%d\n",arr[query[l]]);
	}
	return 0;
}