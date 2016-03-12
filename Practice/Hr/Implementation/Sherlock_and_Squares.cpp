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
		int A, B;
		cin >> A >> B;
		cout << (int)(floor(sqrt(B))-ceil(sqrt(A))+1) << endl;
	}
}