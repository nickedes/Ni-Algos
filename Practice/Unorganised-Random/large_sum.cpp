/*
Find the largest pair sum in an array.
*/
#include <iostream>
using namespace std;

int max(int a,int b)
{
	return (a>b)?a:b;
}
int min(int a,int b)
{
	return (a>b)?b:a;
}
int main()
{	
	int arr[100],i,n,first,second;
	cout << "Enter N:";
	cin >> n;

	cout << "Enter Numbers: ";
	for(i=0;i<n;i++)
		cin >> arr[i];

	// The 2 largest no.s will give largest pair sum.
	first = max(arr[0],arr[1]);
	second = min(arr[0],arr[1]);

	for(i=2;i<n;i++)
	{
		if(arr[i] > first)
		{
			second = first;
			first = arr[i];
		}
		else if(arr[i] > second)
		{
			second = arr[i];
		}
	}
	cout << "Largest pair sum is :"<<first<<", "<<second;
	return 0;
}