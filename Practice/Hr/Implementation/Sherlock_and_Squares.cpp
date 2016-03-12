/*
Problem : https://www.hackerrank.com/challenges/sherlock-and-squares
 */
#include <iostream>
#include <math.h>
using namespace std;

int check_sq(int num)
{
	float x = ceil(sqrt(num));
	if(x*x == num)
		return 1;
	return 0;
}

int main()
{
	int tests;
	cin >> tests;
	while(tests--)
	{
		int A, B, count = 0;
		cin >> A >> B;
		for (int i = A; i <= B; ++i)
		{
			if(check_sq(i))
				count++;
		}
		cout << count << endl;
	}
}