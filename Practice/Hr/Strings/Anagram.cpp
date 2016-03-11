/*
Problem : https://www.hackerrank.com/challenges/game-of-thrones
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
		int freq_s1[26] = {0}, freq_s2[26] = {0}, count = 0;
		cin >> s;
		if (s.length() % 2 == 1)
			cout << -1;
		else
		{
			for (int i = 0; i < s.length(); ++i)
			{
				if(i < s.length()/2) // S1
					freq_s1[s[i]-'a']++;
				else // S2
					freq_s2[s[i]-'a']++;
			}
			for (int i = 0; i < 26; ++i)
				count += abs(freq_s1[i] - freq_s2[i]);
			cout << count/2;
		}
		cout << endl;
	}
	return 0;
}