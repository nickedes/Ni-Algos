/*
Problem : https://www.hackerrank.com/challenges/reverse-shuffle-merge
*/

#include <iostream>
using namespace std;

int check_map(int map[])
{
	for (int i = 0; i < 26; ++i)
	{
		if(map[i]!=1)
			return 0;
	}
	return 1;
}

int main()
{
	string s;
	cin >> s;

	char A[5000];
	int startIndex = 0, windowStartIndex = s.length()/2 - 1, smallestCharacterIndex = s.length()-1, out=0;
	int freq[26] = {0};
	for (int i = 0; i < s.length(); ++i)
		freq[s[i]-'a']++;
	for (int i = 0; i < 26; ++i)
		freq[i] /= 2;
	while(out != s.length()/2)
	{	
		int map[26]={0};
		for (int i = 0; i < 26; ++i)
		{
			if(!freq[i])
				map[i]=1;
		}
		for (int i = smallestCharacterIndex-1; i >= 0; --i)
		{
			map[s[i]-'a']=1;
			if(check_map(map))
			{
				windowStartIndex = i;
				break;
			}
		}

		char c = 'z';
		for (int i = startIndex; i <= windowStartIndex; ++i)
		{
			if(s[i] < c)
			{
				c=s[i];
				smallestCharacterIndex = i;
			}
		}
		A[out++] = s[smallestCharacterIndex];
		freq[s[smallestCharacterIndex]-'a']--;
		startIndex = smallestCharacterIndex + 1;
		windowStartIndex = s.length()/2 - 1;
	}
	cout << A;
	return 0;
}