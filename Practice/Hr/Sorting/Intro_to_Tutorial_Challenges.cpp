/*
Problem : https://www.hackerrank.com/challenges/tutorial-intro
 */

#include <iostream>
using namespace std;

int main()
{
	int search_val, size;
	cin >> search_val >> size;
	int num;

	for (int i = 0; i < size; ++i)
	{
		cin >> num;
		if(num == search_val)
			cout << i;
	}
	return 0;
}