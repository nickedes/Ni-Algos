/*
Time complexity - O(N^2)
Space complexity - O(1)
 */
#include <iostream>
#include <string.h>
using namespace std;

// checks if string2 is a substring of string1
int isSubstring(char string1[], char string2[])
{
	// implement substring logic
	int flag = 0;
	for(int i = 0; i <= strlen(string1) - strlen(string2); i++)
	{
		for(int j = i; j < i+strlen(string2); j++)
		{
			flag = 1;
			if(string1[j] != string2[j-i])
			{
				flag = 0;
				break;
			}
		}
		if(flag)
			return 1;
	}
	return 0;
}

int main()
{
	char s1[100], s2[100];

	cout << "enter two strings : ";
	cin >> s1 >> s2;
	// check s2 is rotation of s1
	if(strlen(s1) == strlen(s2))
	{
		// s1 will be transformed to -> s1 + s1
		strcat(s1,s1);
		// if s2 is a substring of (s1+s1) -> then rotation else not!
		if(isSubstring(s1, s2))
			cout << "Yes, a rotation";
		else
		cout << "Not a rotation";
	}
	else
		cout << "Not a rotation";
	return 0;
}