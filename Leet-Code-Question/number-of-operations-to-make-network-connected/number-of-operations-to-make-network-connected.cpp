class Solution {
public:
    void solve(int u,vector<vector<int>> &v, vector<bool> & vis){
        
        if(vis[u]) return;
        
        vis[u]=true;
        
        for(auto it: v[u]){
            
            solve(it,v,vis);
        }
        
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        vector<vector<int>> graph(n);
        for(int i=0;i<connections.size();i++){
            int x=connections[i][0];
            int y=connections[i][1];
            
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        int count=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                solve(i,graph,visited);
            }
        }
        return count-1;
    }
};