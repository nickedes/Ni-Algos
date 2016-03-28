/*
Problem : https://www.hackerrank.com/contests/intro-to-statistics/challenges/basic-statistics-warmup-2
 */

#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	float mean = 0.0, median = 0.0, Sd = 0.0;
	for (int i = 0; i < N; ++i)
	{
		mean += arr[i];
		Sd += arr[i]*arr[i];
	}
	mean /= N;
	Sd /= N;
	Sd -= mean*mean;
	cout << mean;
}