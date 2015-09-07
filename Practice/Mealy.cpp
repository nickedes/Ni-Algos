#include <iostream>
#include <fstream>

using namespace std;

#define MAX 10

int main()
{
	fstream obj;
	char ch;
	int state_table[MAX][MAX], out_table[MAX][MAX], i = 0, j = 0, flag = 0, num_stats = 0, q_prev = 0;

	obj.open("Mealy-input.txt",ios::in);

	while((ch = obj.get()) != EOF)
	{
		if(!flag)
		{
			if (ch == '\n')
			{
				i ++;
				j = 0;
			}
			else if(ch == ' ')
			{
				// ignore
			}
			else if(isdigit(ch))
			{
				state_table[i][j++] = ch - '0';
			}
			else if(ch == '#')
			{
				flag = 1;	
				num_stats = i;
				i = j = 0;
				// to ignore upcoming newline
				ch = obj.get();
			}				
		}
		else
		{
			if (ch == '\n')
			{
				i ++;
				j = 0;
			}
			else if(ch == ' ')
			{
				// ignore
			}
			else if(isdigit(ch))
			{
				cout << i;
				out_table[i][j++] = ch - '0';
			}
	 	}
	}
}