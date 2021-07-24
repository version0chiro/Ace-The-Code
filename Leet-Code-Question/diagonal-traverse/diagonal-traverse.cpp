class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
       map<int,vector<int>> m;
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                m[i+j].push_back(mat[i][j]);
            }
        }
        
        vector<int> ans;
        
        int level=0;
        
        for(auto a:m){
            auto v=a.second;
            if(level%2){
                copy(v.begin(),v.end(),back_inserter(ans));
            }else{
                copy(v.rbegin(),v.rend(),back_inserter(ans));
            }
            level++;
        }
        
        return ans;
    }
};