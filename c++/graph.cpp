#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    int numVertices;
    vector<vector<int>> adj;

    void dfsHelper(int node, vector<bool> &visited) const
    {
        visited[node] = true;
        cout << node << " ";
        for (int nei : adj[node])
        {
            if (!visited[nei])
            {
                dfsHelper(nei, visited);
            }
        }
    }

public:
    Graph(int verticies)
    {
        numVertices = verticies;
        adj.resize(verticies);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void print() const
    {
        for (int i = 0; i < numVertices; i++)
        {
            cout << i << ": ";
            for (int neighbor : adj[i])
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void bfs(int start) const
    {
        vector<bool> visited(numVertices, false);
        queue<int> q;
        q.push(start);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            cout << node << " ";
            for (int nei : adj[node])
            {
                if (!visited[nei])
                {
                    visited[nei] = true;
                    q.push(nei);
                }
            }
        }
        cout << endl;
    }

    void dfs(int start) const
    {
        vector<bool> visited(numVertices, false);
        dfsHelper(start, visited);
        cout << endl;
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "Adjacency list:" << endl;
    g.print();

    cout << endl;
    cout << "BFS starting from 0: ";
    g.bfs(0);

    cout << "DFS starting from 0: ";
    g.dfs(0);

    return 0;
}