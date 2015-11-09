/*
Problem : https://www.hackerrank.com/challenges/coin-change
 */

#include <iostream>
using namespace std;

#define SIZE 100000

int main()
{
	int n;
	cin >> n;

	int rating[SIZE], distri[SIZE];
	for (int i = 0; i < n; ++i)
	{
		cin >> rating[i];
		distri[i] = 1;
	}
	
	for(int i = 1; i < n; i++)
	{
		if(rating[i-1] < rating[i])
			distri[i] = distri[i-1]+1;
	}

	for(int i=n-2; i>=0; i--)
	{
		if(rating[i] > rating[i+1] && distri[i] <= distri[i+1])
			distri[i] = distri[i+1] + 1;
	}
	int candies = 0;
	for (int i = 0; i < n; ++i)
		candies += distri[i];

	// for (int i = 0; i < n; ++i)
	// 	cout << distri[i] << " ";

	cout << candies;
	return 0;
}