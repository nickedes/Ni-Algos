/*
Problem : https://www.hackerrank.com/challenges/bigger-is-greater
 */

#include <iostream>
using namespace std;

void swap(char *a, char *b)
{
	char *temp;
	temp = a;
	a = b;
	b = temp;
}

int main()
{
	int test;
	cin >> test;
	for (int i = 0; i < test; ++i)
	{
		char word[100];
		cin >> word;
		/*
			Steps :
			1. Find the highest index j such that s[j] < s[j+1]. If no such index exists, the permutation is the last permutation.
	        2. Find the highest index k > j such that s[k] > s[j]. Such a k must exist, since j+1 is such an index.
	        3. Swap s[j] with s[k].
	        4. Reverse the order of all of the elements after index j till the last element.
		 */
		int max_j=-1;
		// step 1
		for (int j = 0; word[j] != '\0'; ++j)
		{
			if (word[j] < word[j+1])
				max_j = j;
		}
		if(max_j == -1)
			cout << "no answer";
		else
		{
			// step 2
			int max_k;
			for (int k = max_j+1; word[k] != '\0'; ++k)
			{
				if(word[k] > word[max_j])
					max_k = k;
			}
			// step 3

		}
		cout << endl;
	}
	return 0;
}