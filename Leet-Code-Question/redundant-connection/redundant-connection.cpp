class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<int> p(edges.size()+1,0);
        for(int i=0;i<p.size();i++){
            p[i]=i;
        }
        
        vector<int> res;
        
        for(auto a:edges){
            int u=a[0],v=a[1];
            while(u!=p[u]) u=p[u];
            while(v!=p[v]) v=p[v];
            
            if(u==v)
                res=a;
            else
                p[u]=v;
        }
        
        
        return res;
    }
};