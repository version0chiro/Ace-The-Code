class Solution {
public:
    int t[101][101];
    int fallPath(vector<vector<int>>& mat,int i,int j){
        if(min(i,j)<0 || i>=mat.size() || j>=mat[0].size()) return 100;
        
        if(i==mat.size()-1) return mat[i][j];
        
        if(t[i][j]!=-1) return t[i][j];
        
        int leftF = fallPath(mat,i+1,j-1),rightF=fallPath(mat,i+1,j+1),midF=fallPath(mat,i+1,j);
        
        t[i][j]=min(leftF,min(rightF,midF))+mat[i][j];
        
        return t[i][j];
        
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(t,-1,sizeof(t));
        
        int ans=INT_MAX;
        for(int i=0;i<matrix[0].size();i++){
            int temp=fallPath(matrix,0,i);
            ans=min(temp,ans);
        }
        
        return ans;
    }
};