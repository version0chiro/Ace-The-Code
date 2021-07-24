class Solution {
public:
    void solve(vector<vector<int>>& grid,int x,int y,int &peri){
        if(x>=grid.size() || x<0 || y<0 || y>=grid[0].size() || grid[x][y]==0 || grid[x][y]==-1){
            return;
        }
        
        if(x+1>=grid.size() || grid[x+1][y]==0) peri++;
        if(x-1<0 || grid[x-1][y]==0) peri++;
        if(y+1>=grid[0].size() || grid[x][y+1]==0) peri++;
        if(y-1<0 || grid[x][y-1]==0) peri++;
        
        grid[x][y]=-1;
        
        solve(grid,x+1,y,peri);
        solve(grid,x,y+1,peri);
        solve(grid,x-1,y,peri);
        solve(grid,x,y-1,peri);
        
        
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int x=-1,y=-1;
        for(int i=0;i<grid.size();i++){
            if(x!=-1){
                break;
            }
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    x=i;
                    y=j;
                    break;
                }
            }
        }
        int peri=0;
        solve(grid,x,y,peri);
        
        return peri;
    }
};