/*
Problem : https://www.hackerrank.com/challenges/cavity-map
 */

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string s[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
	}
	int grid[n][n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			grid[i][j] = s[i][j] - '0';
		}
	}
	for (int i = 1; i < n-1; ++i)
		for (int j = 1; j < n-1; ++j)
			if(grid[i-1][j] < grid[i][j] && grid[i+1][j] < grid[i][j] && grid[i][j-1] < grid[i][j] && grid[i][j+1] < grid[i][j])
				grid[i][j] = 'X';

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(grid[i][j]!='X')
				cout << grid[i][j];
			else
				cout << "X";
		}
		cout << endl;
	}
	return 0;
}