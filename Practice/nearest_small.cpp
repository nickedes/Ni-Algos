/*
Given an array of integers, find the nearest smaller number for every element 
such that the smaller element is on left side.
Input:  arr[] = {1, 6, 4, 10, 2, 5}
Output:         {_, 1, 1,  4, 1, 2}
*/

#include <iostream>
using namespace std;

int main()
{
	int arr[50], i, near=0;
	cout << "Enter no. of elements";
	cin >> n;
	for(i = 0;i < n;i++)
		cin >> arr[i];

	cout << "_";
	for(i = 1;i < n;i++)
	{
		if(a[i-1] < a[i])
		{
			near = i-1;
			cout << a[near];
		}

		else if(a[i] < a[near])
		{
			cout << "_";
			near = i;
		}
		else
		{
			cout << "handle this";
		}
	}
	return 0;
}