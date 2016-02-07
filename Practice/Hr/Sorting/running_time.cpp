/*
Problem : https://www.hackerrank.com/challenges/insertionsort1
 */

#include <iostream>
using namespace std;

#define SIZE 1001

int main()
{
	int n, arr[SIZE], j, key, shift = 0;

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (i = 1; i < n; i++)
    {
       key = arr[i];
       j = i-1;

       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
           shift++;
       }
       arr[j+1] = key;
    }
    cout << shift;
	return 0;
}