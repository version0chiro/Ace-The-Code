class Solution {
public:
    void dfs(int v,vector<int> adj[],string &labels,int ctn[],vector<int> &t){
        if(t[v]==0){
            t[v]=1;
            for(auto a:adj[v]){
                    int temp[26]={};
                    dfs(a,adj,labels,temp,t);
                    for(auto k=0;k<26;k++){
                        ctn[k]+=temp[k];
                    }
                
            }
            t[v]=++ctn[labels[v]-'a'];
        }
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> adj[n];
        vector<int> t(n);

        for(auto a:edges){
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }

        int ctn[26]={};
        dfs(0,adj,labels,ctn,t);
        
        
        return t;
    }
};