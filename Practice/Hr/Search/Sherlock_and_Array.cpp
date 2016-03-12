/*
Problem : https://www.hackerrank.com/challenges/sherlock-and-array
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
		int check = 0;
		for (int i = 0; i < N; ++i)
		{
			int sum = 0, sum_i = 0;
			for (int j = i+1; j < N; ++j)
				sum += arr[j];
			for (int j = 0; j < i; ++j)
				sum_i += arr[j];
			if (sum == sum_i)
			{
				check = 1;
				break;
			}
		}
		if(check == 1)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
	return 0;
}