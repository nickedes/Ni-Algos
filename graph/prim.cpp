#include "iostream"
#include <stdio.h>
#include "fstream"
using namespace std;

#define max 5

int main()
{
    int a,b,u,v,ne=1,visited[max]={0},min,i,j,adj[max][max],mincost=0;
    fstream f;
    f.open("data/graph.txt",ios::in);
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            f>>adj[i][j];
        }
    }
    cout<<"Adj matrix:"<<endl;
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            cout<<" "<<adj[i][j];
        }   
        cout<<endl;
    } 

    for(i=0;i<max;i++)
        for(j=0;j<max;j++)
        {
            if(adj[i][j]==0)
                adj[i][j]=999;
        }
    visited[0]=1;
    cout<<endl;
    while(ne<max)
    {
        for(i=0,min=999;i<max;i++)
            for(j=0;j<max;j++)
                if(adj[i][j]<min)
                    if(visited[i]!=0)
                    {
                     min=adj[i][j];
                     a=u=i;
                     b=v=j;
                    }
        if(visited[u]==0 || visited[v]==0)
        {
        cout<<"\n Edge "<<ne++<<":("<<a<<" "<<b<<") cost:"<<min;
        mincost+=min;
        visited[b]=1;
        }
        adj[a][b]=adj[b][a]=999;
    }
    cout<<"\n Minimun cost="<<mincost<<endl;
    return 0;
}