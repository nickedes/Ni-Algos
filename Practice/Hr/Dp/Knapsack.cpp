/*
Problem : https://www.hackerrank.com/challenges/unbounded-knapsack
 */

#include <iostream>
using namespace std;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int n)
{
	// static int sum = 0;
	// Base Case
	if (n == 0 || W == 0)
	   return 0;

	// If weight of the nth item is more than Knapsack capacity W, then
	// this item cannot be included in the optimal solution
	if (wt[n-1] > W)
	   return knapSack(W, wt, n-1);

	// Return the maximum of two cases: 
	// (1) nth item included 
	// (2) not included
	else return max(wt[n-1] + knapSack(W-wt[n-1], wt, n), knapSack(W, wt, n-1));
}

int main()
{
	int tests;
	cin >> tests;
	while(tests--)
	{
		int n, k;
		cin >> n >> k;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		cout << knapSack(k, arr, n) << endl;
	}
	return 0;
}