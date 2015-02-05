#include <iostream>
#include <fstream>
using namespace std;

#define max 5
int main()
{
	int i,j,adj[max][max],color[max],queue[5];
	fstream f;
	//reading adjacency matrix from file
	f.open("data/graph.txt",ios::in);
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			f>>adj[i][j];
		}
	}
	cout<<"Adj matrix:"<<endl;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			cout<<" "<<adj[i][j];
		}	
		cout<<endl;
	}
	int s=0,front=-1,rear=-1;
	cout<<"enter source:";
	cin>>s;
	/*
		initially all nodes are white colored.
		0- not visited(white)
		1- partially visited(gray)
		2- visited(black)
	*/
	cout<<endl<<"bfs: ";	
	for(i=0;i<5;i++)
	{
		color[i]=0;
	}
	color[s]=1;
	//inserting in queue
	queue[++front]=s;
	++rear;
	while(rear != -1)
	{
		int u;
		u = queue[front];
		front--;
		rear--;
		for(i=0;i<max;i++)
		{
			if(adj[u][i])
			{
				if(color[i]==0)
				{
					color[i]=1;
					queue[++front]=i;
					++rear;
				}
			}
		}
		color[u]=2;
		cout<<u<<" ";
	}
	return 0;
}