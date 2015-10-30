/*
Time complexity - O(N)
Space complexity - O(N) [for hashmap]
 */

#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

#define SIZE 10

bool check_permutation(char first[], char second[])
{
	if(strlen(first) == strlen(second))
	{
		// create hashmap of one string and keep count of chars
		// check the hashmap with the second string
		map<char, int> hashmap;
		for(int i=0; first[i] != '\0'; i++)
		{
			hashmap[first[i]]++;
		}
		map<char, int> :: iterator iter;
		for(int i = 0; second[i] != '\0'; i++)
		{
			iter = hashmap.find(second[i]);
			if(iter->second == 1)
				hashmap.erase(iter);
			else if(iter->second == 0)
				return 0;
			else
				hashmap[second[i]]--;
		}
		return 1;
	}
	return 0;
}

int main()
{
	// Take 2 strings
	char first[SIZE], second[SIZE];
	
	cin >> first;
	cin >> second;
	// call check permutation
	cout << check_permutation(first, second);
	return 0;
}