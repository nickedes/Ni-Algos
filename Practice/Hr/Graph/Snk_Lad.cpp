#include <iostream>
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
		//solve
		cout << moves<< endl;
	}

	return 0;
}