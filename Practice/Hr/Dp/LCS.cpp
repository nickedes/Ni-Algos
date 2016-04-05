/*
Problem : https://www.hackerrank.com/challenges/candies
 */

#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int a[n] = {0}, b[m] = {0};
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i)
		cin >> b[i];
	int table[n+1][m+1];
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			if(i == 0 || j == 0)
				table[i][j] = 0;
			else if(a[i-1] == b[j-1])
				table[i][j] = table[i-1][j-1] + 1;
			else
				table[i][j] 
		}
	}
	return 0;
}