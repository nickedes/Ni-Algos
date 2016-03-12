/*
Problem : https://www.hackerrank.com/challenges/service-lane
 */
#include <iostream>
using namespace std;

int min_arr(int arr[], int i, int j)
{
	int min = arr[i];
	for (int k = i; k <= j; ++k)
	{
		if(min > arr[k])
			min = arr[k];
	}
	return min;
}

int main()
{
	int N, Tests;
	cin >> N >> Tests;
	int arr[N];
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	for (int k = 0; k < Tests; ++k)
	{
		int i, j;
		cin >> i >> j;
		cout << min_arr(arr, i, j) << endl;
	}
	return 0;
}