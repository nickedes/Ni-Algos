/*
Problem : https://www.hackerrank.com/challenges/quicksort4
 */

#include <iostream>
using namespace std;

int size, swaps = 0;

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition (int arr[], int low, int high)
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
            swaps++;
            i++;    // increment index of smaller element
        }
    }
    swap(&arr[i], &arr[high]);
    swaps++;
    return i;
}
 
void quickSort(int arr[], int low, int high)
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
 
int insertion(int arr[], int n)
{
    int shift = 0;
    for (int i = 1; i < n; i++)
    {
       int key = arr[i],j = i-1;

       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
           shift++;
       }
       arr[j+1] = key;
    }
    return shift;
}

int main()
{
    cin >> size;
    int arr[size], b[size];
    for(int i = 0; i < size; i++)
        cin >> arr[i];
    for(int i = 0; i < size; i++)
        b[i] = arr[i];
    quickSort(arr, 0, size-1);
    int shift = insertion(b, size);
    cout << shift - swaps;
    return 0;
}