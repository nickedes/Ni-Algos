/*
Problem : https://www.hackerrank.com/challenges/alternating-characters
*/

#include <iostream>
using namespace std;

int main()
{
	int tests;
	cin >> tests;
	while(tests--)
	{
		string s;
		int count = 0;
		cin >> s;
		for (int i = 1; i < s.length(); ++i)
		{
			if (s[i] == s[i-1])
				count++;
		}
		cout << count << endl;
	}
	return 0;
}