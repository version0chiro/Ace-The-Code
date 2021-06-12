#include <bits/stdc++.h>
#define NIL -1
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void APUtil(int v, bool visited[], int disc[], int low[],
                int parent[], bool ap[]);
    void DFS(int v, long long &sum, vector<int> w, map<int, bool> &visitedMap);

public:
    map<int, bool> visited;
    Graph(int V);
    void addEdge(int v, int w);
    vector<int> AP();

    vector<long long> DFSUtil(int minNode, vector<int> w);
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

void Graph::APUtil(int u, bool visited[], int disc[],
                   int low[], int parent[], bool ap[])
{
    static int time = 0;

    int children = 0;

    visited[u] = true;

    disc[u] = low[u] = ++time;

    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;

        if (!visited[v])
        {
            children++;
            parent[v] = u;
            APUtil(v, visited, disc, low, parent, ap);

            low[u] = min(low[u], low[v]);

            if (parent[u] == NIL && children > 1)
                ap[u] = true;

            if (parent[u] != NIL && low[v] >= disc[u])
                ap[u] = true;
        }

        else if (v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
}

vector<int> Graph::AP()
{

    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
    bool *ap = new bool[V];

    for (int i = 0; i < V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
        ap[i] = false;
    }

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            APUtil(i, visited, disc, low, parent, ap);

    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (ap[i] == true)
        {
            ans.push_back(i);
        }
    }

    return ans;
}

void Graph::DFS(int v, long long &sum, vector<int> w, map<int, bool> &visitedMap)
{
    visitedMap[v] = true;
    sum += w[v];

    for (auto a : adj[v])
    {
        if (!visitedMap[a])
        {
            DFS(a, sum, w, visitedMap);
        }
    }
}

vector<long long> Graph::DFSUtil(int minNode, vector<int> w)
{
    long long bob = 0;

    vector<long long> ans;
    map<int, bool> visitedMap;

    visitedMap[minNode] = true;

    for (auto a : adj[minNode])
    {
        DFS(a, bob, w, visitedMap);
        ans.push_back(bob);
        bob = 0;
    }

    sort(ans.begin(), ans.end(), greater<int>());

    return ans;
}

vector<long long> solve(int n, int m, vector<int> w, vector<vector<int>> edges)
{
    Graph g(n);

    for (auto a : edges)
    {
        g.addEdge(a[0] - 1, a[1] - 1);
    }

    vector<int> APs = g.AP();

    vector<long long> weightsAP;

    int minWeight = INT_MAX;
    int minNode = INT_MAX;
    for (auto a : APs)
    {
        if (minWeight > w[a])
        {
            minWeight = w[a];
            minNode = a;
        }
    }

    vector<long long> ans = g.DFSUtil(minNode, w);

    // int minNode = INT_MAX;

    // for(auto a:weightsAP){

    // }

    return {ans[1], ans[0]};
}

int main()
{

    int t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> w(n);
        for (int i = 0; i < n; i++)
        {
            cin >> w[i];
        }
        vector<vector<int>> edges(m, vector<int>(2));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cin >> edges[i][j];
            }
        }

        vector<long long> out_;
        out_ = solve(n, m, w, edges);

        for (int i = 0; i < out_.size(); i++)
        {
            cout << " " << out_[i];
        }

        cout << "\n";
    }
    return 0;
}