class Solution {
public:
    
    bool dfs(vector<vector<int>> &mat,int x,int y){
        if(min(x,y)<0 || x>=mat.size() || y>=mat[0].size() || mat[x][y]==0){
            return false;
        }
        
        
        if(x==mat.size()-2 && y==mat[0].size()-2) return true;
        
        
        mat[x][y]=0;
        
        return dfs(mat,x+1,y) || dfs(mat,x-1,y) || dfs(mat,x,y+1) || dfs(mat,x,y-1);
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        
        vector<vector<int>> g(m*3,vector<int>(n*3,0));
        
        for(auto i=0;i<m;i++){
            for(int j=0;j<n;j++){
                auto r= grid[i][j];
                g[i*3 +1][j*3 +1]=true;
                g[i*3+1][j*3+0]=r==1||r==3||r==5;
                g[i*3+1][j*3+2]=r==1||r==4||r==6;
                g[i*3+0][j*3+1]=r==2||r==5||r==6;
                g[i*3+2][j*3+1]=r==2||r==3||r==4;
            }
            
        }
        
        
        return dfs(g,1,1);
        
    }
};