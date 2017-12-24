#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	double f, total = 0;
	for (int i = 0; i < 12; ++i)
	{
		cin >> f;
		total += f;
	}
	cout <<"$"<< total/12;
}