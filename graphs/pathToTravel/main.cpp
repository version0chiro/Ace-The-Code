#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> adj[],int V,int E,vector<int> &ans,bool &isPossible){
    vector<bool> visited(V+1,false);

    queue<int> q;

    
}

int main()
{

    int V, E;
    cin >> V >> E;

    vector<int> adj[V + 1];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans;
    bool isPossible = true;

    solve(adj,V,E,ans,isPossible);
}