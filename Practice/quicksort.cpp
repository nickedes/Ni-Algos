#include <iostream>
using namespace std;

// swapping two elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

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
	i++;
	swap(&arr[i], &arr[high]);
	return i;
}

void quicksort(int arr[], int low, int high)
{
	if(low < high)
	{
		int pivot = partition(arr, low, high);
		quicksort(arr, low, pivot-1);
		quicksort(arr, pivot+1, high);
	}
}

int main()
{
	int num, arr[20];

	cout << "Enter no. of elements :";
	cin >> num;

	cout << "Enter array :";
	for(int i=0; i<num;i++)
		cin >> arr[i];

	quicksort(arr, 0, num-1);

	for(int i=0; i<num;i++)
		cout << arr[i];

	return 0;
}