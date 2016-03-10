/*
Problem : https://www.hackerrank.com/challenges/reverse-shuffle-merge
*/

#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int freq[26] = {0}, added[26]={0}, seen[26]={0};
	char A[5000];
	for (int i = 0; i < s.length(); ++i)
		freq[s[i]-'a']++;
	for (int i = 0; i < 26; ++i)
		freq[i] = freq[i]/2;

	int j = 0, check = s.length()-1; // j to track last minimum added
	for (int k = 0; k < s.length()/2; ++k)
	{
		A[k] = (char)('z'+1);
		for (int i = check; i >= 0; --i)
		{
			int c = s[i]-'a';
			if(s[i] < A[k] && (freq[c]-added[c])>0)
			{
				A[k]=s[i];
				j = i;
			}
			seen[c]++;
			if((seen[c]-added[c]) > freq[c])
			{
				while(i<j)
				{
					seen[s[i]-'a']--;
					i++;
				}
				check = j-1;
				break;
			}
		}
		added[A[k]-'a']++;
	}
	for (int i = 0; i < s.length()/2; ++i)
		cout << A[i];
	cout << endl;
}