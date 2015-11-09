/*
Problem : https://www.hackerrank.com/challenges/coin-change
 */

#include <iostream>
using namespace std;

#define SIZE 100000

int main()
{
	int n;
	cin >> n;

	int rating[SIZE];
	for (int i = 0; i < n; ++i)
		cin >> rating[i];

	int flag;
	// sort the rating in increasing order
	/*
	for (int i = 0; i < n; i++)
	{
		flag = 1;
		for (int j = 0; j < n-1; j++)
		{
			if(rating[j] > rating[j+1])
			{
				int temp;
				temp = rating[j+1];
				rating[j+1] = rating[j];
				rating[j] = temp;
				flag = 0;
			}
		}
		if(flag)
			break;
	}
	*/
	int candy = n;
	for(int i = 1; i < n; i++)
	{
		if(rating[i-1]<rating[i])
		{
			candy+=1;
		}
	}
	cout << candy;
	return 0;
}