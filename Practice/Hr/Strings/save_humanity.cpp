/*
Problem : https://www.hackerrank.com/challenges/two-strings
*/

#include <iostream>
using namespace std;

int check_matching(string p, string v, int index)
{
	int count = 1;
	for (int i = index; i < index + v.length(); ++i)
	{
		if(p[i] != v[i-index])
		{
			count--;
			if (count < 0)
				return 0;
		}
	}
	return 1;
}

int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		string p, v;
		cin >> p;
		cin >> v;
		int match = 0;
		for (int i = 0; i <= p.length()-v.length(); ++i)
		{
			if(check_matching(p, v, i))
			{
				cout << i << " ";
				match = 1;
			}	
		}
		if(!match)
			cout << "No Match!";
		cout << endl;
	}
	return 0;
}