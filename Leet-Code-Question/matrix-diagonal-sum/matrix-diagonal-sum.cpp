class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sumDi=0;
        int n = mat.size();
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(i==j || i==n-1-j){
                    sumDi+=mat[i][j];
                }
            }
        }
        
        return sumDi;
    }
};