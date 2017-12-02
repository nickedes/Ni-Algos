#include <iostream>
#include <time.h>
#include <stdlib.h>

#define max 10000
using namespace std;

int quicksort(int a[],int,int);
int partition(int a[],int,int);
int main()
{
	clock_t t;
	int a[max],i;	
	srand(time(NULL));
	// for random no.s
	for(i=0;i<max;i++)
		a[i]=rand()%max+1;
	
	for(i=0;i<max;i++)
		cout<<" "<<a[i];

	t = clock();
	quicksort(a,0,max-1);
	t = clock() - t;
	cout<<"\n Sorted array: ";
	for(i=0;i<max;i++)
		cout<<" "<<a[i];
	cout << endl << "clocks : " << t;
	return 0;
}
int quicksort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
	return 0;
}

int partition(int a[],int p,int r)
{
	int x,i,j,y;
	x=a[r];
	i=p-1;
	for(j=p;j<r;j++)
	{
		if(a[j]<=x)
		{
			i=i+1;
			y=a[i];
			a[i]=a[j];
			a[j]=y;
		}
	}
	y=a[i+1];
	a[i+1]=a[r];
	a[r]=y;
	return i+1;
}