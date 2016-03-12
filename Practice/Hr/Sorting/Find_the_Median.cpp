/*
Problem : https://www.hackerrank.com/challenges/find-median
 */

#include <iostream>
using namespace std;

int main()
{
	int size;
	cin >> size;
	int freq[10000]={0};
	for (int i = 0; i < size; ++i){
		int num;
		cin >> num;
		freq[num]++;
	}
	int median = (size+1)/2, start = 0; // this value is the median
	for (int i = 0; i < 10000; ++i)
	{
		start += freq[i];
		if(start >= median)
		{
			cout << i;
			break;
		}
	}
	return 0;
}