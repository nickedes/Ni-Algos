#include <stdio.h>

int main()
{
	int a,b, x, y;
	scanf("%d %d", &a, &b);

	x = a-b;
	y =x +1;

	if(x/10 != y/10)
	{
		y=x-1;
	}
	printf("%d", y);
	return 0;
}