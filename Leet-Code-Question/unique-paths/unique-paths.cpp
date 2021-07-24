class Solution {
public:
    vector<vector<int>> t;
    int solve(int i,int j,int m,int n){
        if(i<0 || j<0 || i>=m || j>=n){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(i==m-1 && j==n-1){
            t[i][j]=1;
            return t[i][j];
        }
    
        
        t[i][j]=solve(i,j+1,m,n) + solve(i+1,j,m,n);
        
        return t[i][j];
        
    }
    int uniquePaths(int m, int n) {
        t.assign(m+1, vector<int>(n, -1));
        
        return solve(0,0,m,n);
        
        // return count;
        
    }
};