class Solution {
public:
    
    bool check(vector<string> &grid,int i,int j,int n){
        for(int p=0;p<n;p++){
            if(grid[i][p]=='Q' || grid[p][j]=='Q'){
                return false;
            }
        }
        
        int x=i,y=j;
        while(x>=0 && y>=0){
            if(grid[x][y]=='Q'){
                return false;
            }
            x--;
            y--;
        }
        x=i-1,y=j+1;
        while(x>=0 && y<n){
            if(grid[x][y]=='Q'){
                return false;
            }
            x--;
            y++;
        }
        
        return true;
    }
    
    void solve(vector<vector<string>> &ans,vector<string> &grid,int i,int j,int n,int q){
        // cout<<q<<"\n";
        if(q==0){
            ans.push_back(grid);
            return;
        }
        
        if(i==n || j==n){
            return;
        }
        
        if(check(grid,i,j,n)){
            grid[i][j]='Q';
            solve(ans,grid,i+1,0,n,q-1);
            grid[i][j]='.';
        }
        
        solve(ans,grid,i,j+1,n,q);
        
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> grid(n,string(n,'.'));;
        int q=n;
        solve(ans,grid,0,0,n,q);
        return ans;
    }
};