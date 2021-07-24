class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1,0),canA,canB;
        for(auto &edge:edges){
            if(parent[edge[1]]==0)
                parent[edge[1]]=edge[0];
            else{
                canA={parent[edge[1]],edge[1]};
                canB=edge;
                edge[1]=0;
            }
                
        }
        
        for(int i=1;i<=n;i++) parent[i]=i;
        
        for(auto &edge:edges){
            if(edge[1]==0) continue;
            
            int u = edge[0],v=edge[1],pu=root(parent,u);
            
            if(pu==v){
                if(canA.empty()) return edge;
                return canA;
            }
            parent[v]=pu;
                
        }
        return canB;
    }
    
    int root(vector<int>& parent,int k){
        if(parent[k]!=k)
            parent[k]=root(parent,parent[k]);
        return parent[k];
    }
};