/*
Assume you have a method isSubstring which checks if one word is a
substring of another. Given two strings, si and s2, write code to check if s2 is
a rotation of si using only one call to isSubstring (e.g.,"waterbottle"is a rota-
tion of "erbottlewat").
*/
#include <iostream>
using namespace std;

bool isSubstring(string s1, string s2);

bool isRotation(string s1, string s2)
{
	if (s1.length() != s2.length())
		return false;
	return isSubstring(s1, s2);
}

int main()
{
	string s1 = "apple";
	string s2 = "pleap";
	cout << isRotation(s1, s2) << endl;
	return 0;
}