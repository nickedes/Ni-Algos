/*
Problem : https://www.hackerrank.com/challenges/sherlock-and-valid-string
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	string s;
	int freq[26] = {0};
	cin >> s;

	for (int i = 0; i < s.length(); ++i)
		freq[s[i]-'a']++;
	int value, num = 0;
	for (int i = 0; i < 26; ++i)
	{
		if(freq[i]){
			value=freq[i];
			break;
		}
	}
	for (int i = 0; i < 26; ++i)
	{
		if(freq[i] && freq[i]!=value)
			num++;
	}
	if(num == 0)
		cout << "YES";
	else if(num > 1)
		cout << "NO";
	else
	{
		for (int i = 0; i < 26; ++i)
		{
			if(freq[i] && freq[i]!=value)
			{
				if(freq[i] == 1 || freq[i] == value+1)
					cout << "YES";
				else
					cout << "NO";
				break;
			}
		}
	}
	return 0;
}