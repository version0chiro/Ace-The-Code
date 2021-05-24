#include <bits/stdc++.h>

using namespace std;

int getMinReversal(vector<pair<int, int>> adj[], int V, int E, int src, int dst)
{
    vector<bool> visited(V + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> distances(V + 1, INT_MAX);

    pq.push({0, src});

    distances[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        cout << u << endl;
        visited[u] = true;
        pq.pop();
        for (auto a : adj[u])
        {
            int v = a.first;

            if (!visited[v])
            {
                int weight = a.second;
                if (distances[v] > distances[u] + weight)
                {
                    distances[v] = distances[u] + weight;
                    pq.push({distances[v], v});
                }
            }
        }
    }

    if (distances[dst] == INT_MAX)
    {
        return -1;
    }
    else
    {
        return distances[dst];
    }
}

int main()
{

    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> adj[V + 1];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back({v, 0});
        adj[v].push_back({u, 1});
    }
    int src, dest;
    cin >> src >> dest;
    cout << getMinReversal(adj, V, E, src, dest);

    return 0;
}