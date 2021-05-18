#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int V; // no of vertices

    list<int> *adj; // pointer to adjacency list

public:
    Graph(int V); //constructor

    void addEdge(int v, int w);

    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // add w to v's list;
}

void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int s = q.front();
        cout << s << " ";
        q.pop();

        for (auto a : adj[s])
        {
            if (!visited[a])
            {
                visited[a] = true;
                q.push(a);
            }
        }
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(3,5);
    g.addEdge(3,4);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
    return 0;
}