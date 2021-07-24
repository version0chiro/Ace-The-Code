class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(mat.size()*mat[0].size() !=r*c){
            return mat;
        }
        
        
        vector<int> mat1d;
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mat1d.push_back(mat[i][j]);
            }
        }
            
    
        vector<vector<int>> t(r,vector<int> (c,0));
        int p=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                t[i][j]=mat1d[p];
                p++;
            }
        }
        
        return t;
    }
};