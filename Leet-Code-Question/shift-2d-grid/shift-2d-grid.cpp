class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        
        for(int i=0;i<m*n;i++){
            int orig_y = i/n;
            int orig_x=i%n;
            
            int new_y = (orig_y+(orig_x+k)/n)%m;
            int new_x = (orig_x+k)%n;
            ans[new_y][new_x]=grid[orig_y][orig_x];            
        }
        
        return ans;
    }
};