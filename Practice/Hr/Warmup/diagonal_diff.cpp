/*
Problem : https://www.hackerrank.com/challenges/diagonal-difference
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int n, j = 0, k, sum_prim, sum_sec;
	cin >> n;
	sum_prim = 0; // sum of primary diagonal
	sum_sec = 0; // sum of secondary diagonal
	k = n-1;
	for (int i=0; i < n*n; i++)
	{
		int x;
		cin >> x;
		if (i == 0 || i % j == 0)
		{
			sum_prim += x;
			j += n+1;
		}
		if(i!=0 && i % k == 0 && i!= n*n-1)
		{
			sum_sec += x;
			k += n-1;
		}
	}
	cout << abs(sum_prim-sum_sec);
	return 0;
}