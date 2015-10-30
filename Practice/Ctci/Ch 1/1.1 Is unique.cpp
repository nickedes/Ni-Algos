/*
Time complexity : O(N)
Space complexity : O(N)
 */

#include <iostream>
using namespace std;

#define SIZE 10

bool is_Unique(char word[])
{
	int map[26] = {0}, x;
	// considering only alphas!
	for(int i = 0; word[i] != '\0'; i++)
	{
		x = toupper(word[i]) - 65;
		if(map[x])
		{
			// not Unique!
			return 0;
		}
		map[x] = 1;
	}
	return 1;
}

int main()
{
	char word[SIZE];

	cout << "enter string:";
	cin >> word;

	cout << is_Unique(word);
	return 0;
}