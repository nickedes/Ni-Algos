#include <iostream>
using namespace std;

/*
Partition - last element as pivot, left to pivot small and right to pivot
larger ones.
 */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;

	for(int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
}

// swapping two elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{

	return 0;
}