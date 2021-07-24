class Solution {
public:
    vector<vector<int>> t;
    int solve(vector<vector<int>> grid,int x,int y,int m,int n){
        

        if(x<0 || y<0 || x>=m || y>=n || grid[x][y]==1){
            return 0;
        }
        
        if(t[x][y]!=-1){
            return t[x][y];
        }
        if(x==m-1 && y==n-1 ){
            t[x][y]=1;
            return t[x][y];
        }
        
        t[x][y]=solve(grid,x+1,y,m,n) + solve(grid,x,y+1,m,n);
        // cout<<t[x][y]<<" \n";
        
        return t[x][y];
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        t.assign(m+1,vector<int>(n,-1));
        return solve(obstacleGrid,0,0,m,n);
    }
};