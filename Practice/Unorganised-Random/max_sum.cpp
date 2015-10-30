/*
find the maximum sum of a subsequence with the constraint that no 2 numbers
in the sequence should be adjacent in the array.
 */
#include <iostream>
using namespace std;

int max(int a, int b)
{
	return (a > b)?a:b;
}
int main()
{
	int arr[100], i, n, present,previous;
	cout << "Enter No. of elements:";
	cin >> n;
	cout << "Enter elements:";
	for(i=0;i<n;i++)
		cin >> arr[i];
	present = arr[0];
	previous = 0;
	for(i=1;i<n;i++)
	{
		int new_present;
		new_present = previous + arr[i];
		previous = max(present, previous);
		present = new_present; 
	}
	cout << "Maximum sum:" << max(previous, present);
	return 0;
}