// Input - Sorted array, pivoted at some point.
#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int num)
{
   if (high < low)
       return -1;
   int mid = (low + high)/2;
   if (num == arr[mid])
     return mid;
   if (num > arr[mid])
     return binarySearch(arr, (mid + 1), high, num);
   else
     return binarySearch(arr, low, (mid -1), num);
}

int main()
{
	int n, arr[100], i, val, pivot, flag = 0;
	cout << "Enter N:";
	cin >> n;

	cout << "Enter "<<n<<" no.s:";
	for(i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << "Enter search value: ";
	cin >> val;

	// First finding the Pivot
	for(i = 0; i < n-1; i++)
	{
		if (arr[i] > arr[i+1])
		{
			pivot = i;
			flag = 1;
			break;
		}
	}
	if(!flag)
		pivot = -1;

	// If we didn't find a pivot, then array is not rotated at all
	if (pivot == -1)
		return binarySearch(arr, 0, n-1, val);
	
	cout << "Index of the element: "; 
	// If we found a pivot, then first compare with pivot and then
    // search in two subarrays around pivot
	if (arr[pivot] == val)
		cout << pivot;
	if (arr[0] <= val)
		cout << binarySearch(arr, 0, pivot-1, val);
	else
		cout << binarySearch(arr, pivot+1, n-1, val);

	return 0;
}