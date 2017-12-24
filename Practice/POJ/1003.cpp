#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int i;
	double c, total;
	while(1)
	{
		cin >> c;
		if (c == 0.0)
			break;
		total = 0;
		for (i = 2; total < c; ++i)
		{
			total += 1.0/i;
		}
		cout << i - 2 << " card(s)" << "\n";
	}
}