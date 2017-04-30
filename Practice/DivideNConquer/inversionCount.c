#include <stdio.h>

int mergesort(int arr[], int low, int high)
{
	int invCount = 0;
	if(low < high)
	{
		int mid = low + (high - low)/2;

		invCount = mergesort(arr, low, mid);
		invCount += mergesort(arr, mid + 1, high);
		invCount += merge(arr, low, mid+1, high);
	}
	return invCount;
}

int merge(int arr[], int low, int mid, int high)
{
	// mid represents the start of second half array.
	int i, j, k, num, invCount = 0;
	num = high - low + 1;

	int temp[num];
	i = low;
	j = mid;
	k = 0;

	while(i < mid && j <= high)
	{
		if(arr[i] < arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
			invCount += mid - i;
		}
	}

	while(i < mid)
	{
		temp[k++] = arr[i++];
	}

	while(j <= high)
	{
		temp[k++] = arr[j++];
	}

	for (i = low; i <= high; ++i)
	{
		arr[i] = temp[i-low];
	}

	return invCount;
}

int main()
{
	int n, i, invCount;
	scanf("%d", &n);

	int arr[n];
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	invCount = mergesort(arr, 0, n-1);

	for (i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}

	printf("\nInversion count : %d", invCount);
	return 0;
}