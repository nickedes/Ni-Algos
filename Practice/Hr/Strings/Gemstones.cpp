/*
Problem : https://www.hackerrank.com/challenges/gem-stones
*/

#include <iostream>
using namespace std;

int main()
{
	int tests, freq[26] = {0}, firsttime = 1;
	cin >> tests;
	while(tests--)
	{
		string s;
		cin >> s;
		if(firsttime)
		{
			for (int j = 0; j < s.length(); ++j)
				freq[s[j]-'a'] = 1;
			firsttime = 0;
		}
		else
		{
			int new_freq[26] = {0};
			for (int j = 0; j < s.length(); ++j)
				new_freq[s[j]-'a'] = 1;
			for (int j = 0; j < 26; ++j)
			{
				if(freq[j] == 1 && new_freq[j] == 0)
					freq[j] = 0;
			}
		}
	}
	int count = 0;
	for (int j = 0; j < 26; ++j)
		if(freq[j])
			count++;
	cout << count;
}