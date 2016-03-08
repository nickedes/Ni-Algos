/*
Problem : https://www.hackerrank.com/challenges/two-strings
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

		int index = -1;
		for (int i = 0, j = s.length() - 1; i < j; ++i, --j)
		{
			if (s[i] != s[j])
			{
				if(s[i+1] == s[j])
				{
					index = i;
					j++;
				}
				else if(s[i] == s[j-1])
				{
					index = j;
					i--;
				}
			}
		}
		cout << index << endl;
	}
	return 0;
}