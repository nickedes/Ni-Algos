/*
Problem : https://www.hackerrank.com/challenges/sherlock-and-valid-string
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	string s;
	int freq[26] = {0};
	cin >> s;

	for (int i = 0; i < s.length(); ++i)
		freq[s[i]-'a']++;
	int check = 0, start = freq[0], count = 0;
	for (int i = 1; i < 26; ++i)
	{
		if(freq[i] != start)
		{
			check = 1;
			break;
		}
		if (freq[i])
			count++;
	}
	if(check == 0) // all same freq!
		cout << "YES";
	else
	{
		int num1 = 0, num2 = 0, set1 = 0, set2=0,count1 = 1, count2 = 0, confirm=0;
		for (int i = 1; i < 26; ++i)
		{
			if(freq[i]!=0)
			{
				if(!set1)
				{	
					num1 = freq[i];
					count1++;
					set1 = 1;
				}
				else if(!set2)
				{
					if(freq[i]!=num1)
					{
						num2 = freq[i];
						count2++;
						set2 = 1;
					}
					else
						count1++;
				}
				else
				{
					if(freq[i]==num1)
						count1++;
					else if(freq[i]==num2)
						count2++;
					else
					{
						confirm=-1;
						break;
					}
				}
			}
		}
		if(confirm==-1)
		{
			for (int i = 0; i < 26; ++i)
			{
				cout << freq[i] << " ";
			}
			cout << "NO";
		}
		else
		{
			if(abs(num1-num2) == 1)
			{
				if((count1 > count2 && count2 == 1)||(count2 > count1 && count1 == 1))
					cout << "YES";
				else
					cout << "NO";
			}
			else
				cout << "NO";
		}
	}
	return 0;
}