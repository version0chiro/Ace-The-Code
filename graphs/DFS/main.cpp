#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{

public:
    bool visited[100] = {false};

    void solve(int V, vector<int> adj[], vector<int> &ans)
    {
        visited[V] = true;
        // cout<<V<<" ";
        ans.push_back(V);
        for (auto a : adj[V])
        {
            // cout<<a<<" idahr \n";
            if (!visited[a])
            {
                solve(a, adj, ans);
            }
        }
    }
    //Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here

        vector<int> ans;
        solve(0, adj, ans);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends