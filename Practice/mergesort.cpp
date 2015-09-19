#include <iostream>
using namespace std;

void merge()
{

}

void mergesort(int arr[], int low, int high)
{
	if(low < high)
	{
		int m = (low + high - 1)/2;
		mergesort(arr, low, m);
		mergesort(arr, m+1, high);
		merge(arr, low, high, m);
	}
}


int main()
{
	return 0;
}