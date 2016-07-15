#include <stdio.h>

int main()
{
	int i=0,j=0;
	do
	{
		// printf(":1");
		if (i>=5)
		{
			// printf(":2");
			i+=2;
			printf ("%d \n" ,i);
			break;
		}
		else
		{
			// printf(":3");
			printf("%d \n",++i);
			continue;
		}
		// printf(":4");
	}
	while(i<7);
}