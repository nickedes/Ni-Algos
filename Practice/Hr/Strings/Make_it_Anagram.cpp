/*
Problem : https://www.hackerrank.com/challenges/game-of-thrones
*/

#include <iostream>
using namespace std;

int main()
{
	string a,b;
	int freq_a[26] = {0}, freq_b[26] = {0}, count = 0;
	cin >> a >> b;
	for (int i = 0; i < a.length(); ++i)
		freq_a[a[i]-'a']++;
	for (int i = 0; i < b.length(); ++i)
		freq_b[b[i]-'a']++;
	for (int i = 0; i < 26; ++i)
	{

	}
	return 0;
}