// http://poj.org/problem?id=1007
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int merge(char string[], int low, int mid, int high)
{
	int temp[high - low + 1];

	int i = low, j = mid+1, k = 0, invCount = 0;

	for (;i < mid && j > mid;)
	{
		if(string[i] < string[j])
		{
			temp[k++] = string[i++];
		}
		else
		{
			temp[k++] = string[j--];
			invCount += mid - i - 1;
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

	for (i = low; i <= high; ++i)
	{
		string[i] = temp[i];
	}

	return invCount;
}

int mergesort(char string[], int low, int high)
{
	int mid = (low + high)/2, invCount = 0;

	invCount = mergesort(string, low, mid);
	invCount += mergesort(string, mid + 1, high);

	invCount += merge(string, low, mid, high);
	return invCount;
}

int getInvCount(char string[], int length)
{
	cout << mergesort(string, 0, length);
	return 0;
}

int main()
{
	int length, number;
	cin >> length >> number;

	char strings [number][length];
	for (int i = 0; i < number; ++i)
	{
		cin >> strings[i];
		getInvCount(strings[i], length);
	}
	return 0;
}
