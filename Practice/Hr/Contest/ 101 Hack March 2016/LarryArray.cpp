/*
Problem : https://www.hackerrank.com/contests/101hack35/challenges/larrys-array
 */

#include <iostream>
using namespace std;

int main()
{
	int tests;
	cin >> tests;
	while(tests--)
	{
		int N;
		cin >> N;
		int arr[N];
		for (int i = 0; i < N; ++i)
			cin >> arr[i];
		bool inv = true;
		for (int i = 0; i < N; ++i)
			for (int j = i+1; j < N; ++j)
				inv ^= (arr[i] > arr[j]);
		cout << (inv ? "YES" : "NO") << endl;
	}
}