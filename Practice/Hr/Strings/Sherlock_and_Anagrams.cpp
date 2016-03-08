/*
Problem : https://www.hackerrank.com/challenges/sherlock-and-anagrams
*/

#include <iostream>
#include <string>
using namespace std;

int check_anagram(string s, int i, int j, int len)
{
   int first[26] = {0}, second[26] = {0}, c = i;

   while (c < i + len) {
      first[s[c]-'a']++;
      c++;
   }
   c = j;
   while (c < j + len) {
      second[s[c]-'a']++;
      c++;
   }

   for (c = 0; c < 26; c++) {
      if (first[c] != second[c])
         return 0;
   }

   return 1;
}

int main()
{
	int test;
	cin >> test;

	while (test--)
	{
		string s;
		cin >> s;
		int count = 0;

		for (int len = 1; len < s.length(); ++len)
		{
			for (int i = 0; i < s.length() - len; i++)
			{
				for (int j = i+1; j < s.length() - len + 1; ++j)
				{
					if (check_anagram(s, i, j, len) == 1)
						count++;
				}
			}
		}
		cout << count << endl;
	}

	return 0;
}