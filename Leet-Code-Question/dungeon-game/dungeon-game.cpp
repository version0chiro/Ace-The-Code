class Solution {
public:
    vector<vector<int>> t;
    int findMinPath(vector<vector<int>>& grid,int x,int y){
        // cout<<x<<" "<<y<<"\n";
        int n =  grid.size(),m=grid[0].size();
        
        if(min(x,y)<0 || x>=n || y>=m) return 10001;
        
        if(x==n-1 && y==m-1) return grid[x][y]<=0? 1+(-grid[x][y]):1;
        
        if(t[x][y]!=10001) return t[x][y];
        
        int right = findMinPath(grid,x,y+1);
        int down = findMinPath(grid,x+1,y);
        
        int temp = min(right,down) - grid[x][y];
        
        return t[x][y]=temp>0? temp:1;
    }
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        t.assign(m,vector<int> (n,10001));
        
        return findMinPath(grid,0,0);
    }
};