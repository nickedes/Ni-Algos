#include <iostream>
#include <string.h>
using namespace std;

void swap(char array[], int x, int y)
{
	char temp;
	temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

void all_perms(char array[], int low, int high)
{
	if(low == high)
		cout << array << endl;
	else
	{
		// all permutation go here harry!
		for(int i = low; i <= high; i++)
		{
			swap(array, low, i);
			all_perms(array, low+1, high);
			swap(array, low, i);
		}
	}
}

int main()
{
	char array[] = "ABC";

	all_perms(array, 0, strlen(array)-1);

	return 0;
}