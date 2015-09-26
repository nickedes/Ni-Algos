/* Find the element that appears once in a sorted array
Given a sorted array in which all elements appear twice (one after one)
and one element appears only once.

Requirement : O(log n) time complexity
Present : O(n)
*/

#include <iostream>
using namespace std;

#define size 100

int main()
{
	int array[size], num, xor_;

	cout <<"enter num of elements: ";
	cin >> num;

	for(int i = 0; i < num; i++)
		cin >> array[i];

	xor_ = array[0];

	for(int i = 1; i < num; i++)
		xor_ ^= array[i];

	cout << endl << "element is : " << xor_;

	return 0;
}