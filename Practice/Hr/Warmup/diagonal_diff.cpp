/*
Problem : https://www.hackerrank.com/challenges/diagonal-difference
 */

#include <iostream>
using namespace std;

int main()
{
	int n, j = 0, sum_prim, sum_sec;
	cin >> n;
	sum_prim = 0; // sum of primary diagonal
	sum_sec = 0; // sum of secondary diagonal
	for (int i=0; i < n*n; i++)
	{
		int x;
		cin >> x;
		if (i == 0 || i % j == 0)
		{
			sum_prim += x;
			j += n+1;
		}
	}
	cout << sum_prim;
	return 0;
}