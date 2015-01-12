#include <iostream>
#include <fstream>
using namespace std;

#define max 5
#define l 999
int adj[max][max],parent[max];
int find(int);
int uni(int,int);

int main()
{
	int i,j,k,a,b,u,v,ne=1;
	int min,mincost=0;
	fstream f;
	f.open("data/graph.txt",ios::in);
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			f>>adj[i][j];
		}
	}
	for(i=0;i<max;i++)
	{
		for(j=0;j<max;j++)
		{
			if(!adj[i][j])
				adj[i][j]=l;
		}
	}
	while(ne < max)
	{
		for(i=0,min=999;i<max;i++)
		{
			for(j=0;j<max;j++)
			{
				if(adj[i][j] < min)
				{
					min=adj[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			cout<<ne++<<" edge ("<<a<<" "<<b<<") = "<<min<<endl;
			mincost +=min;
		}
		adj[a][b]=adj[b][a]=999;
	}
	cout<<"\n Minimun cost="<<mincost<<endl;
	return 0;
}
int find(int i)
{
	while(parent[i])
	{
		i=parent[i];
	}
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}