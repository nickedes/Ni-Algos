/*
Problem : https://www.hackerrank.com/challenges/coin-change
 */

#include <iostream>
using namespace std;

#define SIZE 50

int main()
{
	long long int N, M, coin[SIZE], map[SIZE];
	cin >> N >> M;

	for(long long int i = 0; i < M; ++i)
		cin>>coin[i];

	long long int table[N+1] = {0};

	//base case
	table[0] = 1;

	for(long long int i = 0; i < M; i++)
		for(long long int j=coin[i]; j <= N;j++)
			table[j] += table[j-coin[i]];

	cout << table[N];
	return 0;
}