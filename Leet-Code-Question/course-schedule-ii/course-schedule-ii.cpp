class Solution {
public:
    stack<int> ans;
    bool check=0;
    void dfs(vector<int> adj[],int v,vector<bool> &visited,vector<bool> recStack){
        if(check) return;
        visited[v]=true;
        recStack[v]=true;
        
        for(auto a:adj[v]){
            if(!visited[a]){
                dfs(adj,a,visited,recStack);
            }else if(recStack[a]){
                check=1;
                return;
            }
        }
        
        ans.push(v);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& preq) {
        vector<int> adj[numCourses+1];
        vector<int> res;
        for(auto a:preq){
            adj[a[1]].push_back(a[0]);
        }
        
        
        vector<bool> visited(numCourses+1,false);
        vector<bool> resStack(numCourses+1,false);

        for(int i=0;i<numCourses;i++){
            if(check==1) return {};
            if(!visited[i]){
                dfs(adj,i,visited,resStack);
            }
        }
        
        
        if(check==1) return {};
        while(ans.size()){
            cout<<ans.top()<<" ";
            res.push_back(ans.top());
            ans.pop();
        }
                
        return res;
    }
};