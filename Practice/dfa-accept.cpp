#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream obj;
	char ch,str[30],input;
	int k=0,initial=9,final[5],num_stats=0,num_inputs=0,num_final,q_prev,q_new,i=0,j=0,mat[5][5];
	obj.open("input.txt", ios::in);
	obj>>initial;
	obj.get(ch);
	while((ch = obj.get()) != '\n')
	{
		if(ch == ' ')
			continue;
		else
			final[i++] = ch - '0';
	}
	num_final = i;
	obj >> num_stats;
	obj.get(ch);
	i = 0;
	while((ch = obj.get()) != EOF)
	{
		if (ch == '\n') // new line found
		{
			i++;
			j=0;
		}
		else if(ch == '-')
		{
			mat[i][j] = -1;
			j++;
		}
		else if(ch == ' ')
		{
			// ignore spaces
		}
		else
		{
			mat[i][j]=ch-'0';
			j++;
		}
	}
	/*
	for(int k = 0; k<num_stats; k++)
	{
		for (int m=0;m<j;m++)
			cout << mat[k][m] << " ";
		cout <<endl;
	}*/

	num_inputs = j-1;
	cin>>str;

	i = 0;
	q_prev = initial;
	q_new = initial;
	while(str[i] != '\0')
	{
		input = str[i] - '0';
		q_new = mat[q_prev][input];
		if (q_new == -1)
		{
			// transition when no output edge!
			break;
		}
		q_prev = q_new;
		i++;
	}
	//int flag = 0;
	for(k = 0; k < num_final; k++)
	{
		if(q_new == final[k])
		{
			cout << "Accepted!";
			break;
		}
	}

	if(k == num_final)
		cout<<"Not Accepted";
	
}