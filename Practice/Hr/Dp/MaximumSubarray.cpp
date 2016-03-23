/*
Problem : https://www.hackerrank.com/challenges/maxsubarray
*/

#include <iostream>
using namespace std;

int check_allNegs(int arr[], int N)
{
	int all_neg = 0;
	for (int i = 0; i < N; ++i)
	{
		if(arr[i] >= 0)
			return 0;
	}
	return 1;
}

int check_allPos(int arr[], int N)
{
	int all_neg = 0;
	for (int i = 0; i < N; ++i)
	{
		if(arr[i] <= 0)
			return 0;
	}
	return 1;
}

int max(int arr[], int N)
{
	int maxi = arr[0];
	for (int i = 1; i < N; ++i)
	{
		if(maxi < arr[i])
			maxi = arr[i];
	}
	return maxi;
}

int main()
{
	int tests;
	cin >> tests;
	while(tests--)
	{
		int N;
		cin >> N;
		int arr[N], sum = 0, sum_pos = 0;
		// sum_pos -> sum of all positives.
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i];
			sum += arr[i];
			if(arr[i] > 0)
				sum_pos += arr[i];
		}
		if(check_allNegs(arr, N))
		{
			int maximum = max(arr, N);
			cout << maximum << " " << maximum;
		}
		else if(check_allPos(arr, N))
		{
			cout << sum << " " << sum;
		}
		else
		{
			int max_so_far = 0, max_ending_here = 0;
			for (int i = 0; i < N; ++i)
			{
				max_ending_here += arr[i];
				if(max_ending_here < 0)
					max_ending_here = 0;
				else if(max_so_far < max_ending_here)
					max_so_far = max_ending_here;
			}
			cout << max_so_far << " " << sum_pos;
		}
		cout << endl;
	}
	return 0;
}