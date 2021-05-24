#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int gerReverseCount(vector<pii> adj[], int V, int E, int src, int dst)
{

    vector<bool> visited(V + 1, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> distance(V + 1, INT_MAX);
    distance[src] = 0;

    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second;

        visited[u] = true;

        pq.pop();
        for (auto a : adj[u])
        {
            int v = a.first;

            if (!visited[v])
            {
                int weight = a.second;

                if (distance[v] > distance[u] + weight)
                {
                    distance[v] = distance[u] + weight;
                    pq.push({distance[v], v});
                }
            }
        }
    }

    if (distance[dst] == INT_MAX)
    {
        return -1;
    }
    else
    {
        return distance[dst];
    }
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<pii> adj[V + 1];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 1});
    }

    int src, dst;

    cin >> src >> dst;

    cout << gerReverseCount(adj, V, E, src, dst);

    return 0;
}