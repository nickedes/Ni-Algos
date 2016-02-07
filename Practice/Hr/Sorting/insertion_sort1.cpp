/*
Problem : https://www.hackerrank.com/challenges/insertionsort1
 */

#include <iostream>
using namespace std;

#define SIZE 1000

void printarr(int arr[SIZE], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	int n, arr[SIZE], e, flag = 0;
	// e is the unsorted element
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	e = arr[n-1];
	for (int i = n-2; i >= 0; --i)
	{
		if(arr[i] > e)
			arr[i+1] = arr[i];
		else
		{
			arr[i+1] = e;
			flag = 1;
			break;
		}
		printarr(arr, n);
	}
	if(flag == 0)
		arr[0] = e;
	printarr(arr, n);
	return 0;
}