/*
Problem : https://www.hackerrank.com/challenges/bigger-is-greater
 */

#include <iostream>
using namespace std;

int main()
{
	int test;
	cin >> test;
	for (int i = 0; i < test; ++i)
	{
		char word[100];
		cin >> word;
		for (int j = 0; word[j] != '\0'; ++j)
		{
			cout << word[j];
		}
		cout << endl;
	}
	return 0;
}