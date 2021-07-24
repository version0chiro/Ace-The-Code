class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> rowMin(matrix.size(),INT_MAX);
        vector<int> colMax(matrix[0].size(),INT_MIN);
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                
                colMax[j]=max(colMax[j],matrix[i][j]);
            }
        }
        
        for(int i=0;i<matrix[0].size();i++){
            for(int j=0;j<matrix.size();j++){
                
                rowMin[j]=min(rowMin[j],matrix[j][i]);
                // colMax[j]=max(colMax[j],matrix[i][j]);
            }
        }
        vector<int> ans;

        unordered_map<int,int> m;
        for(auto a:colMax){
            
            m[a]++;
        }
        // cout<<"\n";
        for(auto a:rowMin){
            if(m[a]>0){
                ans.push_back(a);
            }
        }

        return ans;
    }
};