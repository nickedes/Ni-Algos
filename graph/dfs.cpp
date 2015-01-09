#include <iostream>
#include <fstream>
using namespace std;

#define max 5
int adj[max][max],color[max];

int dfs(int u)
{
	color[u]=1;
	for(int i=0;i<max;i++)
	{
		if(adj[u][i])
		{
			if(color[i]==0)
			{
				dfs(i);
			}
		}
	}
	color[u]=2;
	cout<<" "<<u;
	return 0;
}

int main()
{
	int i,j;
	fstream f;
	f.open("data/graph.txt",ios::in);
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			f>>adj[i][j];
		}
	}
	cout<<endl<<"dfs: ";	
	for(i=0;i<5;i++)
	{
		color[i]=0;
	}
	for(i=0;i<max;i++)
	{
		if(color[i]==0)
		{
			dfs(i);
			cout<<endl;
		}	
	}
	return 0;
}