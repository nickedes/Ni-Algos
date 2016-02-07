/*
Problem : https://www.hackerrank.com/challenges/plus-minus
 */

#include <iostream>
using namespace std;

int main()
{
	int n;
	float pos = 0, neg = 0, zero = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		if (x > 0)
			pos++;
		else if (x < 0)
			neg++;
		else
			zero++;
	}
	cout << pos/n << endl << neg/n << endl << zero/n;
	return 0;
}