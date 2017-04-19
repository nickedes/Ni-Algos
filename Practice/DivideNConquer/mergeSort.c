#include <stdio.h>

int mergeSort(int arr[], int left, int right)
{
	int inv_count = 0;
	if(left < right)
	{
		int mid = left + (right - left)/2;

		inv_count = mergeSort(arr, left, mid);
		inv_count += mergeSort(arr, mid + 1, right);

		inv_count += merge(arr, left, mid + 1, right);
	}

	return inv_count;
}

int merge(int arr[], int left, int mid, int right)
{
	int num = right - left + 1;
	int temp[num], i, j, k, inv_count = 0;

	i = left;
	j = mid;
	k = 0;

	while(i < mid && j <= right)
	{
		if(arr[i] < arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
			inv_count += mid - i;
		}
	}

	while(i < mid)
	{
		temp[k++] = arr[i++];
	}

	while(j <= right)
	{
		temp[k++] = arr[j++];
	}

	for (i = 0; i < num; ++i)
	{
		arr[i+left] = temp[i];
	}

	return inv_count;
}

int getInvCount(int arr[], int n)
{
  int inv_count = 0, i, j;
  for (i = 0; i < n - 1; i++)
    for (j = i+1; j < n; j++)
      if (arr[i] > arr[j])
        inv_count++;
 
  return inv_count;
}

int main()
{
	int i, arr[] = {10,9,8,0,90,11,3,110}, n = 8, inv_count;

	printf("%d\n", getInvCount(arr, n));
	inv_count = mergeSort(arr, 0, n-1);

	for (i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}

	printf("\n%d", inv_count);

}