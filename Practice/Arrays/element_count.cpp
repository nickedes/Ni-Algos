/* Find the element that appears once in a sorted array
Given a sorted array in which all elements appear twice (one after one)
and one element appears only once.

Requirement : O(log n) time complexity
Present : O(log n)
*/

#include <iostream>
using namespace std;

#define size 100

int binSearch(int array[], int low, int high)
{
	if(low == high)
		return array[low];
	
	else if(low > high)
		return 0;
	
	int mid = (low + high)/2;

	if(mid % 2)
	{
		if (array[mid] == array[mid - 1])
			return binSearch(array, mid-2, high);
		else
			return binSearch(array, low, mid);
	}
	else
	{
		if (array[mid] == array[mid + 1])
			return binSearch(array, mid+2, high);
		else
			return binSearch(array, low, mid);
	}
}

int main()
{
	int array[size], num, xor_;

	cout <<"enter num of elements: ";
	cin >> num;

	for(int i = 0; i < num; i++)
		cin >> array[i];

	cout << endl << "element is : " << binSearch(array, 0, num-1);

	return 0;
}