#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main ()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,0}, i, j, n = 10, max;
	for( i=n-1; i >=0; i--)
	{
		max = i;
		for(j = i-1; j >=0; j--)
		{
			if(a[j] < a[max])
				max = j;
		}
		int temp = a[i];
		a[i] = a[max];
		a[max] = temp;
	}

	for (i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	return 0;
}