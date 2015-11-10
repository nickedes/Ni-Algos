#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int test;

	cin >> test;

	for (int i = 0; i < test; ++i)
	{
		int n,m; //n-ladders, m-snakes
		cin >> n;
		int ladder[n][2];
		for (int j = 0; j < n; ++j)
			cin >> ladder[j][0] >> ladder[j][1];
		cin >> m;
		int snake[m][2];
		for (int j = 0; j < m; ++j)
			cin >> snake[j][0] >> snake[j][1];
		int moves = 0;
		// find the ladder with max jump
		int max = ladder[0][1] - ladder[0][0], index = 0;
		for(int j = 1; j < n; j++)
		{
			if(max < ladder[j][1] - ladder[j][0])
			{
				index = j;
				max = ladder[j][1] - ladder[j][0];
			}
				
		}

		int start = 1, end = 100;
		moves += (ladder[index][0]>6)?ceil(ladder[index][0]/6.0):1;
		start =  ladder[index][1];

		// find max snake
		max = snake[0][0];
		int max2 = 0;
		for(int j = 1; j < m; j++)
		{
			if(max > snake[j][0])
			{
				max = snake[j][0];
				index = j;
			}
		}

		for(int j = 0; j < m; j++)
		{
			if(start < snake[j][0] && snake[j][0] < max)
			{
				max2 = snake[j][0];
				index = j;
			}
		}
		if(start < max)
		{
			// TODO: snake concept
		}
		moves += (100 - start) > 6 ? ceil((100 - start)/6.0) : 1; 
		cout << moves<< endl;
	}

	return 0;
}