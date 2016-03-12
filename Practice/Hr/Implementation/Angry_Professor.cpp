/*
Problem : https://www.hackerrank.com/challenges/angry-professor
 */

#include <iostream>
using namespace std;

int main()
{
	int tests;
	cin >> tests;
	while(tests--)
	{
		int N, K;
		cin >> N >> K;
		int arr[N], count = 0;
		for (int i = 0; i < N; ++i)
		{
			int x;
			cin >> x;
			if(x <= 0)
				count++;
		}
		if(count >= K)
			cout << "NO";
		else
			cout << "YES";
		cout << endl;
	}
	return 0;
}