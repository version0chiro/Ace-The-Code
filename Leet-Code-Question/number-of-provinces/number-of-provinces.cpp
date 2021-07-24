class Solution {
public:
    void DFS(vector<vector<int>>& g,int v,vector<bool> &visited){
        visited[v]=true;
        for(int i=0;i<g[v].size();i++){
            if(g[v][i] && !visited[i]){
                DFS(g,i,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<bool> visited(v+1);
        int c=0;
        
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j] && !visited[j]){
                    DFS(isConnected,j,visited);
                    c++;
                }
            }
        }
        
        return c;
    }
};