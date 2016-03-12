/*
Problem : https://www.hackerrank.com/challenges/cut-the-sticks
 */
#include <iostream>
using namespace std;

int check(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		if(arr[i] != 0)
			return 1;
	}
	return 0;
}

void printa(int a[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << a[i] << " ";
	}
}

int new_min(int arr[], int size)
{
	int min = arr[0];
	for (int i = 1; i < size; ++i)
	{
		if(arr[i]!=0 && min!=0 && min > arr[i])
			min = arr[i];
		else if(min == 0)
			min = arr[i];
	}
	return min;
}

int main()
{
	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	int min = arr[0];
	for (int i = 1; i < N; ++i)
	{
		if(arr[i] < min)
			min = arr[i];
	}
	while(check(arr, N))
	{
		int count = 0;
		for (int i = 0; i < N; ++i)
		{
			if(arr[i] >= min)
			{
				arr[i] -= min;
				count ++;
			}
		}
		//  find new min
		min = new_min(arr, N);
		cout << count << endl;
	}
	return 0;
}