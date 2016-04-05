/*
Problem : https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence
 */

#include <iostream>
using namespace std;

int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}

int main()
{
	int n, m;
	cin >> n >> m;
	int a[n], b[m];
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
				table[i][j] = max(table[i-1][j], table[i][j-1]);
		}
	}

	int index = table[n][m];	
	int lcs[index];	
	int i = n, j = m;
	while (i > 0 && j > 0)
	{ 
	  if (a[i-1] == b[j-1])
	  {
	      lcs[index-1] = a[i-1];
	      i--; j--; index--;
	  }
	  else if (table[i-1][j] > table[i][j-1])
	     i--;
	  else
	     j--;
	}
	for (int i = 0; i < table[n][m]; ++i)
		cout << lcs[i] << " ";
	return 0;
}