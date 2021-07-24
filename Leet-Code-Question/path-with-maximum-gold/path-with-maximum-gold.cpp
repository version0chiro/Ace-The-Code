class Solution {
public:
   
    int solve(vector<vector<int>> &arr, int i, int j)
    {
    if (i >= arr.size() || j >= arr[0].size() || i < 0 || j < 0 || arr[i][j]==0)
    {
        return 0;
    }
    int org = arr[i][j];
    arr[i][j]=0;
    int ans=0;
    
    ans =  max(ans,solve(arr, i + 1, j));
    ans = max(ans,solve(arr,i -1 , j));
    ans = max(ans,solve(arr, i , j-1));
    ans = max(ans,solve(arr, i , j+1));
    
    arr[i][j]=org;
        
    return org+ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        
        int maxVal = 0;
                
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>0)
                    maxVal=max(maxVal,solve(grid,i,j));
            }
        }
        return maxVal;
    }
};