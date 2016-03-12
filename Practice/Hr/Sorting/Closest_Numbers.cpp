/*
Problem : https://www.hackerrank.com/challenges/closest-numbers
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

void swap(long int* a, long int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition (long int arr[], long int low, long int high)
{
    int pivot = arr[high];    // pivot
    int i = low;  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;    // increment index of smaller element
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}
 
void quickSort(long int arr[], long int low, long int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // printArray(arr, size);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
	long int N;
	cin >> N;
	long int *arr= (long int*)malloc(sizeof(long int)*N);

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	long int size = N;
	// check if already sorted
	long int x = arr[0], check = 0;
	for (int i = 0; i < size-1; ++i)
	{
		if(arr[i] > arr[i+1])
		{
			check = 1; // means unsorted
			break;
		}
	}
	if(check)
	{
		// sort the Array
		quickSort(arr, 0, size-1);
	}

	long int min_diff = abs(arr[1] - arr[0]), index = 0, count = 0;
	for (int i = 1; i < N-1; ++i)
	{
		if(min_diff > abs(arr[i+1] - arr[i]))
		{
			min_diff = abs(arr[i+1] - arr[i]);
			index = i;
		}
	}

	// print min
	for (int i = 0; i < N-1; ++i)
	{
		if(abs(arr[i+1] - arr[i]) == min_diff)
			cout << arr[i] << " " << arr[i+1] << " ";
	}
	return 0;
}