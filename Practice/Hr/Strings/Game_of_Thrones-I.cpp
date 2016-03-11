/*
Problem : https://www.hackerrank.com/challenges/game-of-thrones
*/

#include <iostream>
using namespace std;

int main()
{
	string input;
	int freq[26] = {0}, count = 0;
	cin >> input;
	for (int i = 0; i < input.length(); ++i)
		freq[input[i]-'a']++;
	for (int i = 0; i < 26; ++i)
	{
		if(freq[i] % 2 == 1)
			count++;
		if(count > 1)
			break;
	}
	if (count > 1)
		cout << "NO";
	else
		cout << "YES";
	return 0;
}