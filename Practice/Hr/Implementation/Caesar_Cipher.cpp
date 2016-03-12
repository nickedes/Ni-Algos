/*
Problem : https://www.hackerrank.com/challenges/chocolate-feast
 */
#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
	int len;
	cin >> len;
	string s;
	cin >> s;
	int key;
	cin >> key;
	key = key % 26;
	for (int i = 0; i < len; ++i)
	{
		if(isalpha(s[i]))
		{
			char a;
			a = isupper(s[i])?'A':'a';
            s[i]= a + (s[i] - a + key)%26;
		}
		cout << s[i];
	}

}