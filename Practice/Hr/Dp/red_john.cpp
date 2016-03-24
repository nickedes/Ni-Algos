/*
Problem : https://www.hackerrank.com/challenges/red-john-is-back
 */
#include <iostream>
using namespace std;

/*
// number of ways in which the bricks can be arranged on the wall
int T(int n)
{
	if (n < 4)
		return 1;
	else if (n == 4)
		return 2;
	return T(n-4) + T(n-1);
}
*/

void markMultiples(bool arr[], int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1;
        ++i;
    }
}

#define SIZE 41

int main()
{
	int test, n, arr[SIZE+1];
	cin >> test;
	arr[0] = 0;
	arr[1] = arr[2] = arr[3] = 1;
	arr[4] = 2;
	for (int i = 5; i < SIZE; ++i)
		arr[i] = arr[i-1] + arr[i-4];

	for (int i = 0; i < test; ++i)
	{
		cin >> n;
		int m, count = 0;
		m = arr[n];

		// now find no. of primes less than m
		if (m >= 2)
		{
			bool marker[m];
			for(int j = 1; j < m; j++)
				marker[j] = 0;
			for(int j = 1; j < m; j++)
			{
				if(marker[j] == 0)
				{
					count += 1; // i+1 is a prime.
					markMultiples(marker, j+1, m);
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}