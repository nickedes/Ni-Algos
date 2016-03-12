/*
Problem : https://www.hackerrank.com/challenges/countingsort2
 */

#include <iostream>
using namespace std;

int main()
{
	int size, arr[100]={0};
	cin >> size;
	for (int i = 0; i < size; ++i)
	{
		int num;
		cin >> num;
		arr[num]++;
	}
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < arr[i]; ++j)
			cout << i <<" ";
	}
}