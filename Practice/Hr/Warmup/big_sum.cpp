/*
Problem : https://www.hackerrank.com/challenges/a-very-big-sum
 */

#include <iostream>
using namespace std;

int main()
{
	long long int n, sum = 0;
	cin >> n;
	for (long long int i = 0; i < n; ++i)
	{
		long long int x ;
		cin >> x;
		sum += x;
	}
	cout << sum;
	return 0;
}