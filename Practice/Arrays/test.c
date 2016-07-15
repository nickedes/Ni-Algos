# include <stdio.h>

int mystery (int *ptra, int *ptrb)
{
	int *temp;
	temp = ptrb;
	ptrb = ptra;
	ptra = temp;
	return 0;
}

int main ()
{
	int a = 2016, b=0, c= 4, d = 42;
	mystery (&a, &b);
	if (a < c)
		mystery (&c, &a);
	mystery (&a, &d);
	printf("%d\n", a);
	return 0;
}