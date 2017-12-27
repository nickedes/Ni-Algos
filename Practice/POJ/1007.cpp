// http://poj.org/problem?id=1007
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int length, number;
	cin >> length >> number;

	char strings [number][length];
	for (int i = 0; i < number; ++i)
	{
		cin >> strings[i];
	}


	return 0;
}

int getInvCount(char string[])
{

}

int mergesort(char string[], int low, int high)
{
	int mid = (low + high)/2, invCount = 0;

	invCount = mergesort(string, low, mid);
	invCount += mergesort(string, mid + 1, high);

	invCount += merge(string, low, mid, high);
	return invCount;
}


int merge(char string[], int low, int mid, int high)
{
	int temp[high - low + 1];

	int i = low, j = mid+1, k = 0;

	for (;i < mid && j > mid;)
	{
		if(string[i] < string[j])
		{
			temp[k++] = string[i++];
		}
		else
		{
			temp[k++] = string[j--];
		}
	}

	for (;i <= mid;)
	{
		temp[k++] = string[i++];
	}

	for (;j >= mid;)
	{
		temp[k++] = string[j--];
	}
}
