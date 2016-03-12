/*
Problem : https://www.hackerrank.com/challenges/countingsort3
 */

#include <iostream>
using namespace std;

int main()
{
	int size, arr[100]={0}, count_sum[100]={0};
	cin >> size;
	for (int i = 0; i < size; ++i)
	{
		int num;
		string s;
		cin >> num >> s;
		arr[num]++;
	}
	count_sum[0] = arr[0];
	for (int i = 1; i < 100; ++i)
		count_sum[i] += arr[i];
	for (int i = 1; i < 100; ++i)
		cout << count_sum[i] << " ";
}