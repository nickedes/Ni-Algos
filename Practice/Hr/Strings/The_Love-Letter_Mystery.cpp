/*
Problem : https://www.hackerrank.com/challenges/the-love-letter-mystery
*/

#include <iostream>
#include <stdlib.h>
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
		for (int i = 0, j = s.length() - 1; i < j; i++, j--)
			count += abs(s[i]-s[j]);
		cout << count << endl;
	}
	return 0;
}