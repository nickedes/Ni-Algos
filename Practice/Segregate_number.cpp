/*
Segregate Even and Odd numbers.
Given an array A[], segregate even and odd numbers.
The program should put all even numbers first, and then odd numbers.
 */

#include <iostream>
using namespace std;

#define MAX 100

int seperator(int array[], int size)
{
	int left = 0, right = size - 1;

	while (left <  right)
	{
		// search for an odd element from left.
		while (array[left]%2 != 1 && left < right)
			left ++;
		// search for an even element from right.
		while(array[right]%2 != 0 && left < right)
			right --;

		// swap odd with even element.
		if (left < right)
		{
			int temp;
			temp = array[left];
			array[left] = array[right];
			array[right] = temp;
		}
	}

	return 0;
}

int main(int argc, char const *argv[])
{
	int size, array[MAX];
	
	cout << "Enter no. of elements in array";
	cin >> size;

	cout << "Enter Array:";
	for (int i = 0; i < size; ++i)
		cin >> array[i];

	seperator(array, size);

	for (int i = 0; i < size; ++i)
		cout << array[i] << ",";

	return 0;
}