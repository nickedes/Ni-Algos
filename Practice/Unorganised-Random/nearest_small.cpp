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
	int arr[50], i, near=0, min=0,n;
	cout << "Enter no. of elements";
	cin >> n;
	for(i = 0;i < n;i++)
		cin >> arr[i];

	cout << "_,";
	for(i = 1;i < n;i++)
	{
		if (arr[i] > arr[near])
			cout << arr[near];

		else if (arr[i] > arr[min])
			cout << arr[min];

		else
		{
			cout << "_,";
			min = i;
			near = i;
		}

		if (arr[i] < arr[i+1])
		{
			near = i;	
		}
	}
	return 0;
}