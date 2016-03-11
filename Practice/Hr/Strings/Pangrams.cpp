/*
Problem : https://www.hackerrank.com/challenges/palindrome-index
*/

#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
	string s;
	int count=26, map[26]={0};

	// cin >> s;
	getline (cin,s);
	for (int i = 0; i < s.length(); ++i)
	{
		s[i] = (char)tolower(s[i]);
		int c = s[i]-'a';
		if(map[c] == 0)
		{
			map[c] = 1;
			count--;
		}
		if(count == 0)
			break;
	}

	if(count == 0)
		cout << "pangram";
	else
		cout << "not pangram";
	return 0;
}