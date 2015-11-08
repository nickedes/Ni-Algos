/*
Problem : https://www.hackerrank.com/challenges/coin-change
 */

#include <iostream>
using namespace std;

#define SIZE 50

int main()
{
	int N, M, coin[SIZE], map[SIZE];
	cin>>N>>M;
	for (int i = 0; i < M; ++i)
	{
		cin>>coin[i];
	}

	int table[N+1];

	//base case
	table[0] = 1;
	for(int i=1; i <= N; i++)
		table[i] = 0;

	for(int i=1; i<=M;i++)
	{
		for(int j=1; j<=N;j++)
		{
			if(j >= coin[i-1])
				table[j] += table[j-coin[i-1]];
		}
	}

	cout << table[N];
	return 0;
}