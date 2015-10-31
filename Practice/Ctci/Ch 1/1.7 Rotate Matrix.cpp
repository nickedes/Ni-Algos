/*

 */
#include <iostream>
using namespace std;

#define SIZE 3

int swap(int *x, int *y)
{
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
	return 0;
}

int main()
{
	int arr[SIZE][SIZE];

	// input matrix
	for(int i = 0; i < SIZE; i++)
		for(int j = 0; j < SIZE; j++)
			cin >> arr[i][j];

	/*
	Method:

	1. Take transpose of matrix
	2. Reverse Rows
	Done!
	*/
	
	// Transpose
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = i; j < SIZE; ++j)
		{
			swap(arr[i][j], arr[j][i]);
		}
	}

	// reverse
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE/2; ++j)
		{
			swap(arr[i][j], arr[i][SIZE-j-1]);
		}
	}

	// display!
	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	return 0;
}