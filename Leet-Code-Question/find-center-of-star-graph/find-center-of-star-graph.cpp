class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> edgesM;
        for(auto a:edges){
            edgesM[a[0]]++;
            edgesM[a[1]]++;
            // cout<<a[0]<<" "<<a[1]<<"\n";
        }
        
        for(auto a:edgesM){
            // cout<<a.first<<" "<<a.second<<" \n";
            if(a.second==edges.size()){
                return a.first;
            }
        }
        
        return 0;
    }
};