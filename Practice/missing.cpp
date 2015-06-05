/*
Given a list of n-1 no.s in the range 1 to n (No duplicates). Finding the missing integer.
*/
#include <iostream>
using namespace std;

int main()
{
	int n,arr[100],i,res;
	cout << "Enter N:";
	cin >> n;

	cout << "Enter "<<n-1<<" no.s:";
	for(i = 0; i < n-1; i++)
	{
		cin >> arr[i];
	}
	res = arr[0];
	for(i = 1;i < n-1;i++)
		res ^= arr[i];
	for(i=1; i<=n; i++)
		res ^= i;
	cout << "The missing number : "<<res;
	return 0;
}