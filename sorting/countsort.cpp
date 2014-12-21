#include <iostream>
#include <stdlib.h>

#define max 10
using namespace std;

int main()
{
	int a[max],b[max],c[max+1],i;	
	srand(time(NULL));
	// for random no.s
	for(i=0;i<max;i++)
		a[i]=rand()%max+1;
	
	for(i=0;i<max;i++)
		cout<<" "<<a[i];

	for(i=0;i<=max;i++)
		c[i]=0;
	for(i=0;i<max;i++)
		c[a[i]]=c[a[i]]+1;

	//c[i] will have no. of elements less than or equal to i.
	for(i=1;i<=max;i++)
		c[i]+=c[i-1];

	for(i=max-1;i>=0;i--)
	{
		b[c[a[i]]]=a[i];
		c[a[i]]=c[a[i]]-1;
	}
	cout<<"\n Sorted array:";
	for(i=1;i<=max;i++)
		cout<<" "<<b[i];
	return 0;
}