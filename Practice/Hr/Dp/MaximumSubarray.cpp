/*
Problem : 
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
		int max_so_far = 0, max_ending_here = 0;
		for (int i = 0; i < N; ++i)
		{
			max_ending_here += arr[i];
			if(max_ending_here < 0)
				max_ending_here = 0;
			if(max_so_far < max_ending_here)
				max_so_far = max_ending_here;
		}
		cout << max_so_far << endl;
	}
	return 0;
}