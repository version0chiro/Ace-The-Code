class Solution {
public:
    
    vector<vector<int>> t;
    int solve(vector<vector<int>>& grid,int x,int y,int m,int n){
        // // cout<<x<<" "<<y<<" ";
        if(x<0 || y<0 || x>=m || y>=n || grid[x][y]==-1){
            return 5000;
            // cout<<"\n";
        }
        
        if(t[x][y]!=-1){
            return t[x][y];
        }
        
        if(x==m-1 && y==n-1){
            // cout<<"\n";
            t[x][y]=grid[x][y];
            return t[x][y];
        }

        
        t[x][y]=min(grid[x][y]+solve( grid,x+1,y,m,n),grid[x][y]+solve( grid,x,y+1,m,n));
        
        return t[x][y];
        
//         int org= grid[x][y];
        
//         grid[x][y]=-1;
        
//         int a = org+ solve( grid,x+1,y,m,n);
//         int b = org+ solve( grid,x,y+1,m,n);
//         // int minAns = min(org+solve( grid,x+1,y,m,n),org+solve(grid,x,y+1,m,n));
        
//         grid[x][y]=org;
        
//         return min(a,b);
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        t.assign(m,vector<int> (n,-1));
        return solve(grid,0,0,m,n);
    }
};