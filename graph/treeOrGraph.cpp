#include <iostream>
using namespace std;

bool check(int degree[], int n)
{
	// Find sum of all degrees
	int deg_sum = 0;
	for (int i = 0; i < n; i++)
		deg_sum += degree[i];
 
	// Graph is tree if sum is equal to 2(n-1)
	return (2*(n-1) == deg_sum);
}

int main()
{
	int n;
	cin >> n;
	int degree[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> degree[i];
	}
	if (check(degree, n))
		cout << "Yes";
	else
		cout << "No";
	return 0;
}