/*

 */
#include <iostream>
using namespace std;

#define SIZE 10

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
	return 0;
}