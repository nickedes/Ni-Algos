#include <iostream>
#include <fstream>

using namespace std;

#define MAX 10

int main()
{
	fstream obj;
	char ch,str[MAX];
	int table[MAX][MAX],i,j,output[MAX],num_states,q_state;

	obj.open("Moore-input.txt",ios::in);
	
	i = j = 0;
	num_states = 0;
	while((ch = obj.get()) != EOF)
	{
		if(ch == '\n')
		{
			i++;
			j = 0;
		}
		else if(isdigit(ch))
		{
			// transition
			table[i][j++] = ch - '0';
		}
		else if(isalpha(ch))
		{
			// output
			output[i] = ch - 'a';
		}
		else if(ch == ' ')
		{
			// ignore
		}
		else if(ch == '-')
		{
			// No transition
			table[i][j++] = -1;
		}
	}

	// total no. of states
	num_states = i + 1;
	
	cout << "Enter string";
	cin >> str;

	q_state = 0;
	cout << output[q_state];
	for (i = 0; str[i] != '\0'; i++)
	{
		int input = str[i] - '0';
		q_state = table[q_state][str[i] - '0'];
		if (q_state == -1)
		{
			// when no transition
			cout << endl << "stop";
			break;
		}
		cout << output[q_state];
	}
	return 0;
}