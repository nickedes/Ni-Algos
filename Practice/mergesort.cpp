#include <iostream>
using namespace std;

void merge(int arr[], int low, int high, int med)
{
	int n1,n2; // n1,n2- no. of elements in subarrays.
	n1 = med - low + 1;
	n2 = high - med;
	int left[n1], right[n2];

	for(int i=0; i < n1; i++)
		left[i] = arr[low + i];
	for (int i = 0; i < n2; i++)
		right[i] = arr[med + i];

	// now merge both arrays
	int i,j,k;
	i = j = k = 0;
	while(i < n1 && j < n2)
	{
		if(left[i] <= right[j])
		{
			arr[k] = left[i];
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	/* Copy the remaining elements of Left[]*/
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of Right[]*/
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int low, int high)
{
	if(low < high)
	{
		int m = low + (high - low)/2;
		mergesort(arr, low, m);
		mergesort(arr, m+1, high);
		merge(arr, low, high, m);
	}
}


int main()
{
	int array[20], num;

	cout << "enter num of elements:";
	cin >> num;

	for (int i = 0; i < num; ++i)
		cin >> array[i];

	mergesort(array, 0, num-1);

	for (int i = 0; i < num; ++i)
		cout << array[i];
	return 0;
}