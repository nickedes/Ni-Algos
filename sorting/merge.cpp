#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define max 10000
using namespace std;
int z=0;
int mergesort(int a[],int,int);
int merge(int a[],int,int,int);
int main ()
{
	int a[max],i,p=0,r=max-1;
	clock_t t;
	srand(time(NULL));
	// for random no.s
	for(i=0;i<max;i++)
		a[i]=rand()%max+1;
	/*
	int j=max-1;
	for(i=0;i<max;i++)
	{
		a[i]=j;
		j--;
		cout<<" "<<a[i];
	}
	*/	
	cout<<"\n"<<"sorted:\n";
	t = clock();
	mergesort(a,p,r);
	t = clock() - t;
	cout<<"\n";
	
	for(i=p;i<=r;i++)
		cout<<" "<<a[i];
	cout<<"\n sorted : "<<z;
	cout << endl << "clocks : " << t;
	return 0;
}

int mergesort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=floor((p+r)/2);
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q,r);
	}
	return 0;
}

int merge(int a[],int p,int q,int r)
{
	int i,n1,j,n2;
	n1=q-p+1;
	n2=r-q;
	int l[n1+1],rt[n2+1];
	for(i=0;i<n1;i++)
	{
		l[i]=a[p+i];
	}
	for(j=0;j<n2;j++)
	{
		rt[j]=a[q+j+1];
	}
	l[n1]=max;
	rt[n2]=max;
	i=j=0;
	for(int k=p;k<=r;k++)
	{
		if(l[i]<=rt[j])
		{
			a[k]=l[i];
			i++;
		}
		else
		{
			a[k]=rt[j];
			j++;
		}
		z++;
	}
	return 0;
}