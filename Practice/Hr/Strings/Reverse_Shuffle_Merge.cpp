/*
Problem : https://www.hackerrank.com/challenges/reverse-shuffle-merge
*/

#include <iostream>
using namespace std;

int get_min_char(int freq[])
{
	for (int i = 0; i < 26; ++i)
		if(freq[i] > 0)
			return i;
	return 0;
}

int main()
{
	string s;
	cin >> s;
	int freq[26] = {0}, A_freq[26] = {0}, min;
	char A[5000];
	for (int i = 0; i < s.length(); ++i)
		freq[s[i]-'a']++;
	for (int i = 0; i < 26; ++i)
	{	
		A_freq[i] = freq[i]/2;
	}
	int j = 0, track = 26;
	min = get_min_char(A_freq);
	for (int i = s.length()-1; i >= 0; --i)
	{
		char c = s[i];
		freq[c-'a']--;
		if(min == c-'a')
		{
			A[j++] = c;
			A_freq[c-'a']--;
		}
		else
		{		
			if(freq[c-'a'] >= A_freq[c-'a'])
				continue;
			else
			{
				A[j++] = c;
				A_freq[c-'a']--;
			}
		}
		min = get_min_char(A_freq);
	}
	for (int i = 0; i < s.length()/2; ++i)
		cout << A[i];
	cout << endl;
}