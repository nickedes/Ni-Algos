/*
Problem : https://www.hackerrank.com/challenges/funny-string
*/

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
	int tests;
	cin >> tests;
	while(tests--)
	{
		string s, org_s;
		int check = 0;
		cin >> s;
		org_s = s; // save original string
		reverse(s.begin(), s.end());
		for (int i = 1; i < s.length(); ++i)
		{
			if (abs(org_s[i] - org_s[i-1]) != abs(s[i] - s[i-1])){
				check = 1;
				break;
			}
		}
		if (check == 1)
			cout << "Not Funny";
		else
			cout << "Funny";
		cout << endl;
	}
	return 0;
}