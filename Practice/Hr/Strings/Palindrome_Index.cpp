/*
Problem : https://www.hackerrank.com/challenges/palindrome-index
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		string s;
		cin >> s;

		int index1 = -1;
		for (int i = 0, j = s.length() - 1; i < j; ++i, --j)
		{
			if (s[i] != s[j])
			{
				if(s[i+1] == s[j])
				{
					index1 = i;
					j++;
				}
				else if(s[i] == s[j-1])
				{
					index1 = j;
					i--;
				}
			}
		}
		int index2 = -1;
		for (int i = 0, j = s.length() - 1; i < j; ++i, --j)
		{
			if (s[i] != s[j])
			{
				if(s[i] == s[j-1])
				{
					index2 = j;
					i--;
				}
				else if(s[i+1] == s[j])
				{
					index2 = i;
					j++;
				}
			}
		}
		if (index1 == index2)
			cout << index1 << endl;
		else
		{
			int index = -1;
			// checking wid index1
			for (int i = 0, j = s.length() - 1; i < j; ++i, --j)
			{
				if(i == index1)
					j++;
				else if(j == index1)
					i--;
				if(s[i]!=s[j])
				{
					index = 1; // wrong index1
					break;
				}
			}
			// check with index2
			for (int i = 0, j = s.length() - 1; i < j; ++i, --j)
			{
				if(i == index2)
					j++;
				else if(j == index2)
					i--;
				if(s[i]!=s[j])
				{
					index = 2; // wrong index2
					break;
				}
			}
			if(index == 1)
				cout << index2 << endl;
			else if(index == 2)
				cout << index1 << endl;
		}
	}
	return 0;
}