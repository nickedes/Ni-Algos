/*
Problem : https://www.hackerrank.com/challenges/stockmax
*/

#include <iostream>
using namespace std;

int main()
{
	int test;

	cin >> test;
	for (int i = 0; i < test; ++i)
	{
		int n;
		cin >> n;

		long int price[n];
		for (int j = 0; j < n; ++j)
			cin >> price[j];
		long int max = price[n-1], profit = 0;
		for (int j = n-2; j >= 0; --j)
		{
			if(price[j] > max)
			{
				max = price[j];
			}
			else if(max - price[j] > 0)
			{
				profit += max - price[j];
			}
		}
		cout << profit << endl;
	}
	return 0;
}