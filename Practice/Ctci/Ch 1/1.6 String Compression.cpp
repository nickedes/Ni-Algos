/*
Time complexity - O(N)
Space complexity - O(N) -> a new string
 */
#include <iostream>
#include <string.h>
using namespace std;

#define SIZE 10

void compressed(char word[])
{
	int count = 1,j=1;
	char modified[SIZE];

	modified[0] = word[0];
	for(int i=1; word[i] != '\0'; i++)
	{
		if(word[i-1] == word[i])
			count++;
		else
		{
			modified[j++] = count + 48;
			count = 1;
			modified[j++] = word[i];
		}
	}
	modified[j++] = count + 48;
	modified[j] = '\0';
	if(strlen(modified) < strlen(word))
		cout << modified;
	else
		cout << word;
}

int main()
{
	char word[SIZE];
	cin >> word;
	compressed(word);
	return 0;
}