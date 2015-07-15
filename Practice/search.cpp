// Input - Sorted array, pivoted at some point.
#include <iostream>
using namespace std;

int main()
{
	int n,arr[100],i,val,pivot;
	cout << "Enter N:";
	cin >> n;

	cout << "Enter "<<n-1<<" no.s:";
	for(i = 0; i < n-1; i++)
	{
		cin >> arr[i];
	}
	cout << "Enter search value: ";
	cin >> val;

	// First finding the Pivot
	for(i = 0; i < n-2; i++)
	{
		if (arr[i] > arr[i+1])
		{
			pivot = i;
			break;
		}
	}
	cout << "Pivot:" << arr[i];
}