/*
Problem : https://www.hackerrank.com/challenges/mr-k-marsh
*/

#include <iostream>
using namespace std;

#define max 500

int main()
{
	int m, n;
	char land[max][max];
	cin >> m >> n;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> land[i][j];
		}
	}

	return 0;
}