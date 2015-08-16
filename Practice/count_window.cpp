/*
Given an array of size n and an integer k, return the of count of distinct 
numbers in all windows of size k. 
 */
#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

map<int, int> m;
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
		m[array[i]]++;
	}
	// print count of distinct no.s in first window.
	cout << m.size() << endl;
	return 0;
}