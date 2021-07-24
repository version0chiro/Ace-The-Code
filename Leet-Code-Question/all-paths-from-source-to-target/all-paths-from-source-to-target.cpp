class Solution {
public:
    vector<vector<int>> ans;
    int e;
    vector<int> temp;
    void DFS(vector<vector<int>> &graph,int v=0){
        
        
        temp.push_back(v);
        if(v==e){
            ans.push_back(temp);
        }
        else for(auto u:graph[v]){
                DFS(graph,u);
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        e=n-1;
        DFS(graph);
        
        return ans;
        
        
        
    }
};