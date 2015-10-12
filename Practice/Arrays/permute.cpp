#include <iostream>
#include <string.h>
using namespace std;

void all_perms(char array[], int low, int high)
{
	if(low == high)
		cout << array[low];
	else
	{
		// all permutation go here harry! 
	}
}

int main()
{
	char array[] = "ABCDE";

	all_perms(array, 0, strlen(array)-1);

	return 0;
}