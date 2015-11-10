#include <iostream>
using namespace std;

int main()
{
	int test;
	cin >> test;

	for (int i = 0; i < test; ++i)
	{
		int n, m_steps;
		cin >> n >> m_steps;

		int pos[n], dim[n];
		for (int j = 0; j < n; ++j)
			cin >> pos[j];
		for (int j = 0; j < n; ++j)
			cin >> dim[j];
		long int num = 0;
		// calc num of ways
		cout << num % 1000000007 << endl;
	}
	return 0;
}