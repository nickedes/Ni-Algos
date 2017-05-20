#include <stdio.h>
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
	return 0;
}

int mergesort(int arr[], int low, int high)
{
	if(low < high)
	{
		int mid = low + (high - low)/2;

		mergesort(arr, low, mid);
		mergesort(arr, mid + 1, high);
		merge(arr, low, mid+1, high);
	}
	return 0;
}
int meil(int a, int b)
{
	if(a > b)
	{
		if(a % b == 0)
		{
			return a/b;
		}
		else
		{
			return a/b + 1;
		}
	}
	else
		return 1;
}

int main()
{
	int n, hit, t, i, j, done = 0;
	scanf("%d", &n);
	scanf("%d", &hit);
	scanf("%d", &t);
	int h[n];

	for (i = 0; i < n; ++i)
	{
		scanf("%d", &h[i]);
	}
	mergesort(h, 0, n-1);	
	for (i = 0; i < n && t > 0; ++i)
	{
		if(h[i] <= hit)
		{
			h[i] = 0;
			--t;
			done++;
		}
		else if( (t - meil(h[i], hit) ) >= 0 )
		{
			t = t - meil(h[i], hit);
			h[i] = 0;
			done++;
		}
	}

	printf("%d", done);

	return 0;
}