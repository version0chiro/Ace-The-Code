class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector <int> answer(n, 1);
        vector<vector<int>> graph(n);
        for(int i=0;i<paths.size();i++){
            graph[paths[i][0]-1].push_back(paths[i][1]-1);
            graph[paths[i][1]-1].push_back(paths[i][0]-1);
        }
        
        for(int i=0;i<n;i++){
            vector<bool> colors (5,false);
            
            for(auto g:graph[i]){
                colors[answer[g]]=true;
            }
            
            for(int l=4;l>0;l--){
                if(!colors[l]){
                    answer[i]=l;
                }
            }            
        }
        return answer;
    }
};