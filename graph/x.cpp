#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int visited[10001];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {    
        int x, y, edges;
        cin >> edges;       // Number of edges
        for (int i = 0; i <= 10000; ++i)
            visited[i] = 0;
        int nodes = 0;
        for(int i = 0;i < edges;++i)
        {
            cin >> x >> y;
            if(visited[x] == 0)
            {
                nodes ++;
                visited[x] = 1;
            }

            if(visited[y] == 0)
            {
                nodes ++;
                visited[y] = 1;
            }
        }
        cout << nodes << endl;
    }
    return 0;
}