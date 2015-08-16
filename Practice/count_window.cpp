/*
Given an array of size n and an integer k, return the of count of distinct 
numbers in all windows of size k. 
 */
#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

map<int, int> hashmap;
int main()
{
	int array[100]={0}, num, window_size, i;
	cout << "Enter the no. of elements: ";
	cin >> num;

	// Input
	for(i = 0; i < num; i++)
		cin >> array[i];

	cout << "Enter window size ";
	cin >> window_size;

	for(i = 0; i < window_size; i++)
	{
		hashmap[array[i]]++;
	}
	// print count of distinct no.s in first window.
	cout << hashmap.size() << endl;

	map<int,int> :: iterator iter;
	for(i = window_size; i < num; i++)
	{
		// Update hashmap for the element removed from window.
		// If single occurence then removed, else decremented it's count.
		iter = hashmap.find(array[i-window_size]);
		if(iter -> second == 1)
			hashmap.erase(iter);
		else
			hashmap[array[i-window_size]] = hashmap[array[i-window_size]]-1;
		// update hash map for the new element in the window.
		hashmap[array[i]]++;
		// count of distinct no.s in the present window.
		cout << hashmap.size() << endl;
	}
	return 0;
}