/*
Problem : https://www.hackerrank.com/challenges/chocolate-feast
 */
#include <iostream>
using namespace std;



int main()
{
	int tests;
	cin >> tests;
	while(tests--)
	{
		int N, C, M, count = 0;;
		cin >> N >> C >> M;
		count = N/C;
		int wraps = count;
		while(wraps >= M)
		{
			count += wraps/M;
			wraps = wraps/M + wraps % M;
		}
		cout << count << endl;
	}
	return 0;
}