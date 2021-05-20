#include <bits/stdc++.h>

using namespace std;

void topoLogical(vector<pair<int, int>> adj[], int v, bool visited[], stack<int> &S)
{
    visited[v] = true;

    for (auto a : adj[v])
    {
        int u = a.first;

        if (!visited[u])
        {
            topoLogical(adj, u, visited, S);
        }
    }

    S.push(v);
}

void longestPath(vector<pair<int, int>> adj[], int V, int src)
{
    int *dist = new int[V];
    bool *visited = new bool[V];

    stack<int> S;
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MIN;
        visited[i] = false;
    }
    dist[src] = 0;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            topoLogical(adj, i, visited, S);
        }
    }

    while (!S.empty())
    {
        cout << S.top() << " \n";
        int u = S.top();
        S.pop();
        if (dist[u] != INT_MIN)
        {
            for (auto p : adj[u])
            {
                if (dist[p.first] < p.second + dist[u])
                {
                    dist[p.first] = dist[u] + p.second;
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INT_MIN)
        {
            cout << " INT_MIN  ";
        }
        else
        {
            cout << dist[i] << " ";
        }
    }
}

int main()
{
    int V = 6;
    vector<pair<int, int>> adj[V];
    adj[0].push_back({1, 5});
    adj[0].push_back({2, 3});
    adj[1].push_back({3, 6});
    adj[1].push_back({2, 2});
    adj[2].push_back({4, 4});
    adj[2].push_back({5, 2});
    adj[2].push_back({3, 7});
    adj[3].push_back({5, 1});
    adj[3].push_back({4, -1});
    adj[3].push_back({5, -2});

    int source = 1;

    longestPath(adj, V, source);

    return 0;
}