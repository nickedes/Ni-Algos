/*
Search an element in an array where difference between adjacent elements is 1.
 */
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int num = 0, array[100]= {0}, val = 0;
	cout << "Enter no. of elements: ";
	cin >> num;

	cout << "Enter Array:";
	for (int i = 0; i < num; i++)
		cin >> array[i];

	cout << "Enter Search term :";
	cin >> val;
	for(int i = 0; i < num; )
	{	
		cout << i;
		if(array[i] == val)
		{
			cout << "Found " << val <<" at index " << i;
			break;
		}
		i = i + abs(array[i]-val);
	}
	return 0;
}