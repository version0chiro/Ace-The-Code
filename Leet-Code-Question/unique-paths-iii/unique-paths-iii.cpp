class Solution {
public:
    int solve(vector<vector<int>>& grid,int x,int y,int m,int n,int count){
        if(x<0 || y<0 || x>=m || y>=n || grid[x][y]==-1){
            return 0;
        }
        
        if(grid[x][y]==2 && count==0){
            return 1;
        }
                
        int org = grid[x][y];
        grid[x][y]=-1;
        
        int a = solve(grid,x+1,y,m,n,count-1);
        int b = solve(grid,x,y+1,m,n,count-1);
        int c = solve(grid,x-1,y,m,n,count-1);
        int d = solve(grid,x,y-1,m,n,count-1);
        
        grid[x][y]=org;
        
        return a+b+c+d;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count=1;
        
        int x=-1,y=-1;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    x=i,y=j;
                }else if(grid[i][j]==0){
                    count++;
                }
            }
        }
        
        cout<<count;

        
        
        return solve(grid,x,y,m,n,count);;
    }
};