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

	int left[m][n], up[m][n];
	for (int i = 0; i < n; ++i)
		if(land[0][i]!='x')
			up[0][i] = 0;
		else
			up[0][i] = -1;

	for (int i = 0; i < m; ++i)
		if(land[i][0]!='x')
			left[i][0] = 0;
		else
			left[i][0] = -1;

	for (int i = 1; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(land[i][j] == 'x')
			{
				up[i][j] = -1;
			}
			else
			{
				up[i][j] = up[i-1][j] + 1;
			}
		}
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if(land[i][j] == 'x')
			{
				left[i][j] = -1;
			}
			else
			{
				left[i][j] = left[i][j-1] + 1;
			}
		}
	}

	// for (int i = 0; i < m; ++i)
	// {
	// 	for (int j = 0; j < n; ++j)
	// 	{
	// 		cout << left[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }


	// for (int i = 0; i < m; ++i)
	// {
	// 	for (int j = 0; j < n; ++j)
	// 	{
	// 		cout << up[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	int max_Perimeter = 2*(left[m-1][n-1] + up[m-1][n-1]);
	if(left[m-1][n-1] != 0 && up[m-1][n-1] != 0)
		cout << max_Perimeter;
	else
		cout << "impossible";
	return 0;
}