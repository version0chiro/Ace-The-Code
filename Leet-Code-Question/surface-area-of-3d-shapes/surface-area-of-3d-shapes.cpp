class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int ans=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0)
                    continue;
                int top,bottom,right,left;
                if(i-1<0)
                    top=grid[i][j];
                else
                    top=max(0,grid[i][j]-grid[i-1][j]);
                
                if(i+1>=grid.size())
                    bottom=grid[i][j];
                else
                    bottom=max(0,grid[i][j]-grid[i+1][j]);
                
                if(j-1<0)
                    left=grid[i][j];
                else
                    left=max(0,grid[i][j]-grid[i][j-1]);
                
                if(j+1>=grid[0].size())
                    right=grid[i][j];
                else
                    right=max(0,grid[i][j] - grid[i][j+1]);
                
                
                ans+=2+top+bottom+left+right;
            }
        }
        
        return ans;
    }
};