/*
Time complexity - O()
Space complexity - O()
 */
#include <iostream>
using namespace std;

int isSubstring(char string1[], char string2[])
{
	// implement substring logic
	return 0;
}

int main()
{
	char s1[100], s2[100];

	// check s2 is rotation of s1
	// s1 will be transformed to - s1 + s1
	// if s2 is a substring of (s1+s1) -> then rotation else not!
	cout << isSubstring(s1, s2);
	return 0;
}