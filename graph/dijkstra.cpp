#include <iostream>
#include <fstream>
using namespace std;

#define max 5

#define infinity 999
 
void dij(int v,int adj[max][max],int dist[])
{
	int i,u,count,w,flag[10],min;
	for(i=0;i<max;i++)
		flag[i]=0,dist[i]=adj[v][i];
	count=2;
	while(count<max)
	{
		min=99;
		for(w=0;w<max;w++)
			if(dist[w]<min && !flag[w])
				min=dist[w],u=w;
		flag[u]=1;
		count++;
		for(w=0;w<max;w++)
			if((dist[u]+adj[u][w]<dist[w]) && !flag[w])
				dist[w]=dist[u]+adj[u][w];
 	}
}

int main()
{
	int i,j,v,adj[max][max],dist[max];
	fstream f;
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

	for(i=0;i<max;i++)
		for(j=0;j<max;j++)
		{
			if(adj[i][j]==0)
				adj[i][j]=infinity;
		}
	cout<<"\n Enter the source matrix:";
	cin>>v;
	dij(v,adj,dist);
	cout<<"\n Shortest path:\n";
	for(i=0;i<max;i++)
		if(i!=v)
			cout<<v<<"->"<<i<<",cost="<<dist[i]<<"\n";
	return 0;
}