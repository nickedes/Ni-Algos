/*
Problem : https://www.hackerrank.com/challenges/manasa-and-stones
 */

#include <iostream>
using namespace std;

int main()
{
	int tests;
	cin >> tests;
	while(tests--)
	{
		int n, a, b, arr[n], j = 0;
		cin >> n >> a >> b;
		if(a==b)
		{
			cout << (n-1)*a;
		}
		else
		{
			if(a > b)
			{
				int temp = a;
				a = b;
				b = temp;
			}
			for (int i = n-1; i >= 0; i--)
			{
				int total = i*a + (n-i-1)*b;
				cout << total << " ";
			}
		}
		cout << endl;
	}
	return 0;
}