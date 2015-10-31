/*
Time complexity - O(NM)
Space complexity - O(1) ,No extra space used!
 */
#include <iostream>
using namespace std;

#define SIZE 3

int display(int arr[SIZE][SIZE])
{
	for(int i = 0; i < SIZE; i++)
	{
		cout << endl;
		for(int j = 0; j < SIZE; j++)
			cout << arr[i][j] << " ";
	}
	return 0;
}

int main()
{
	int arr[SIZE][SIZE];

	// input matrix
	for(int i = 0; i < SIZE; i++)
		for(int j = 0; j < SIZE; j++)
			cin >> arr[i][j];

	// check for 0 elements
	for(int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			if(arr[i][j] == 0)
			{
				arr[i][0] = 0;
				arr[0][j] = 0;
			}
		}
	}

	// set ROW 0
	for (int i = 0; i < SIZE; ++i)
	{
		if(arr[i][0] == 0)
		{
			for (int j = 0; j < SIZE; ++j)
			{
				arr[i][j] = 0;
			}
		}
	}

	// set COLUMN 0
	for (int j = 0; j < SIZE; ++j)
	{
		if(arr[0][j] == 0)
		{
			for (int i = 0; i < SIZE; ++i)
			{
				arr[i][j] = 0;
			}
		}
	}

	display(arr);
	return 0;
}