/*
Problem : https://www.hackerrank.com/challenges/countingsort1
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
		cout << arr[i] << " ";
}