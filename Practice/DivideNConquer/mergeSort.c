#include <stdio.h>

int mergesort(int arr[], int low, int high)
{
	if(low < high)
	{
		int mid = low + (high - low)/2;

		mergesort(arr, low, mid);
		mergesort(arr, mid + 1, high);
		merge(arr, low, mid+1, high);
	}
}

int merge(int arr[], int low, int mid, int high)
{
	// mid represents the start of second half array.
	int i, j, k, n;
	n = high - low + 1;

	int temp[n];
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
}

int main()
{
	int n, i;
	scanf("%d", &n);

	int arr[n];
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	mergesort(arr, 0, n-1);

	for (i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}