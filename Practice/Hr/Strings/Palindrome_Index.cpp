/*
Problem : https://www.hackerrank.com/challenges/palindrome-index
*/

#include <iostream>
#include <string>
using namespace std;

int palindrome_check(string s, int start, int end)
{
	for (int i = start, j = end; i < j; ++i, --j)
		if(s[i] != s[j])
			return 0; // not pal
	return 1; // pal
}

int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		string s;
		cin >> s;

		int index = -1;
		for (int i = 0, j = s.length() - 1; i < j; ++i, --j)
		{
			if (s[i] != s[j])
			{
				if(palindrome_check(s, i, j-1))
				{
					index = j;
					i--;
				}
				else
				{
					index = i;
					j++;
				}
			}
		}
		cout << index << endl;
	}
	return 0;
}