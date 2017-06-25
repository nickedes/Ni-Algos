#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector <int> adj[10];
int visited[10];
// DFS-recursive(G, s):
//     mark s as visited
//     for all neighbours w of s in Graph G:
//         if w is not visited:
//             DFS-recursive(G, w)

int DFSrecursive(int s)
{
    visited[s] = 1;
    cout << s << ",";
    for (int i = 0; i < adj[s].size(); ++i)
    {
        int w = adj[s][i];
        if(visited[w] == 0)
        {
            DFSrecursive(w);
        }
    }
    return 0;
}

int DFSiterative(int s)
{
    stack<int> S;
    S.push(s);
    visited[s] = 1;
    while(!S.empty())
    {
        int v = S.top();
        cout << v << ",";
        S.pop();
        for (int i = 0; i < adj[v].size(); ++i)
        {
            int w = adj[v][i];
            if(visited[w] == 0)
            {
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

    cout << "dfs : ";
    for (int i = 1; i <= nodes; ++i)
        if(visited[i] == 0)
            DFSrecursive(i);

    for (int i = 1; i <= nodes; ++i)
        visited[i] = 0;

    cout << endl << "dfs : ";
    for (int i = 1; i <= nodes; ++i)
        if(visited[i] == 0)
            DFSiterative(i);

    return 0;
}