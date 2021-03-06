#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void bridgeUti(int v, bool visited[], int disc[], int low[], int parent[]);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void bridge();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::bridgeUti(int v, bool visited[], int disc[], int low[], int parent[])
{
    static int time = 0;

    visited[v] = true;

    disc[v] = low[v] = ++time;

    for (auto a : adj[v])
    {
        if (!visited[a])
        {
            parent[a] = v;
            bridgeUti(a, visited, disc, low, parent);

            low[v] = min(low[v], low[a]);

            if (low[a] > disc[v])
            {
                cout << "bridge found at " << v << " " << a << "\n";
            }
        }
        else if (parent[v] != a)
        {
            low[v] = min(low[v], disc[a]);
        }
    }
}

void Graph::bridge()
{
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *parent = new int[V];
    int *low = new int[V];

    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
        visited[i] = false;
    }

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            bridgeUti(i, visited, disc, low, parent);
        }
    }
}

int main()
{
    // Create graphs given in above diagrams
    cout << "\nBridges in first graph \n";
    Graph g1(3);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.bridge();

    return 0;
}