#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> adj[10];
int visited[10];
int level[10];

int BFSiterative(int s)
{
    queue<int> S;
    S.push(s);
    level[s] = 0;
    visited[s] = 1;
    while(!S.empty())
    {
        int v = S.front();
        cout << v << ",";
        S.pop();
        for (int i = 0; i < adj[v].size(); ++i)
        {
            int w = adj[v][i];
            if(visited[w] == 0)
            {
                level[w] = level[v] + 1;
                S.push(w);
                visited[w] = 1;
            }
        }
    }
}

int main()
{
    int x, y, nodes, edges;
    cin >> nodes;       // Number of nodes
    cin >> edges;       // Number of edges
    for(int i = 0;i < edges;++i)
    {
            cin >> x >> y;
        adj[x].push_back(y);        // Insert y in adjacency list of x
    }
    
    for (int i = 1; i <= nodes; ++i)
        visited[i] = 0;

    cout << endl << "Bfs : ";
    for (int i = 1; i <= nodes; ++i)
        if(visited[i] == 0)
            BFSiterative(i);

    cout << endl << "Node - Level" << endl;
    for (int i = 1; i <= nodes; ++i)
        cout << i << "-" << level[i] << endl;

    return 0;
}