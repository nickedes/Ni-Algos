/*
Problem : https://www.hackerrank.com/challenges/two-strings
*/

#include <iostream>
using namespace std;

int main()
{
	int test;
	cin >> test;
	for (int i = 0; i < test; ++i)
	{
		string a, b;
		int check = 0;
		cin >> a;
		cin >> b;
		char map[26] = {0};
		for (int j = 0; a[j] != '\0'; ++j)
			map[a[j]-97] = 1;
		for (int j = 0; b[j] != '\0'; ++j)
		{
			if(map[b[j]-97] == 1)
			{
				check = 1;
				cout << "YES";
				break;
			}
		}
		if(check == 0)
			cout << "NO";
		cout << endl;
	}
	return 0;
}