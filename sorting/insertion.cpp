#include <iostream>
#include <stdlib.h>

#define max 10000
using namespace std;

int main ()
{
	int a[max],key,i,j;
	long int z=0;
	
	srand(time(NULL));
	// for random no.s
	for(i=0;i<max;i++)
		a[i]=rand()%max+1;
	
	/*
	for(i=max-1;i>=0;i--)
	{
		a[i]=i;
		
	}
	*/
	for(i=1;i<max;i++)
	{
		key=a[i];
		j=i-1;
		while(j>0 && a[j]>key)
		{
			a[j+1]=a[j];
			j=j-1;
			z++;
		}
		a[j+1]=key;
	}  
	cout<<"\n "<<z<<" times array is sorted";  
	/*
	for(i=0;i<max;i++)
		cout<<" "<<a[i];
    */
    cout<<"\n";
    
    return 0;
}
