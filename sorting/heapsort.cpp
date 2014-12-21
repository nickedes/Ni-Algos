#include <iostream>
#include <stdlib.h>

#define max 100
using namespace std;
int z=0;
int heapify(int a[],int,int);
int build(int a[]);
int main ()
{
	int a[max],i,y,x;	
	srand(time(NULL));
	// for random no.s
	for(i=0;i<max;i++)
		a[i]=rand()%max+1;
	
	/*
	for(i=0;i<max;i++)
	{
		a[i]=i;
	}
	*/
	/*
	for(i=0;i<max;i++)
		cout<<" "<<a[i];
	*/
	build(a);
	cout<<"\n heap tree:";
	for(i=0;i<max;i++)
		cout<<" "<<a[i];

	cout<<"\nheap sort:";
	y=max-1;
	z=0;
	for(i=y; i>=0;i--)
	{
		x=a[0];
		cout<<" "<<x;
		a[0]=a[i];
		a[i]=x;
		heapify(a,0,i-1);
	}
	cout<<"\n sorted "<<z<<" times";
	return 0;
}

int build(int a[])
{
	for(int i=max/2;i>=0;i--)
		heapify(a,i,max);
	return 0;
}
int heapify(int a[],int i,int size)
{
	int largest,l,r;
	l=2*i+1;
	r=2*i+2;
	if(l<=size && a[l]>a[i])
	{
		largest=l;
		z++;
	}
	else
	{
		largest=i;
		z++;
	}
	if(r<=size && a[r]>a[largest])
	{
		largest=r;
		z++;
	}
	if(largest!=i)
	{
		int x;
		x=a[i];
		a[i]=a[largest];
		a[largest]=x;
		z++;
		heapify(a,largest,size);
	}
	return 0;
}