class Solution {
public:
    unordered_map<int,int> m;
    void dfs(vector<int> graph[],int v,vector<int>& quiet,vector<bool> &visited,vector<int> &ans){
        visited[v]=true;
        for(auto a:graph[v]){
            if(!visited[a]){                
                dfs(graph,a,quiet,visited,ans);
            }
            // cout<<quiet[v]<<":"<<v<<" "<<quiet[a]<<":"<<a<<" \n";
            if(quiet[v]>quiet[a]){
                quiet[v]=quiet[a];
                ans[v]=m[quiet[v]];
                // cout<<"for "<<a<<" is smaller than "<<v<<"\n";
            }
            

        }
        // cout<<"for vertex : "<<v<<" index->"<<minIndex<<"\n";
        // cout<<"\n";
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int V = quiet.size();
        
        vector<int> graph[V+1];
       
        vector<int> ans ;
        for(int i=0;i<V;i++){
            m[quiet[i]]=i;
            ans.push_back(i);
        }
        for(auto a:richer){
            graph[a[1]].push_back(a[0]);
        }
        vector<bool> visited(V+1,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(graph,i,quiet,visited,ans);
            }
        }
        
        return ans;
        
    }
};