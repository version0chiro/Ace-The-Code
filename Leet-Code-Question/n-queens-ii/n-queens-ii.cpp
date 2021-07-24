class Solution {
public:
    
    bool check(vector<string> &grid,int x,int y,int n){
        for(int i=0;i<n;i++){
            if(grid[x][i]=='Q' || grid[i][y]=='Q') return false;
        }
        int i = x;
        int j=y;
        while(i>=0 && j>=0){
            if(grid[i][j]=='Q') return false;
            i--,j--;
        }
        
        i=x-1;
        j=y+1;
        while(i>=0 && j<n){
            if(grid[i][j]=='Q') return false;
            i--,j++;
        }
        
        return true;
        
    }
    
    
    void solve(vector<string> &grid,int x,int y,int q,int n,int &count){
        if(q==0) count++;
        
        if(x==n || y==n) return;
        
        if(check(grid,x,y,n)){
            grid[x][y]='Q';
            solve(grid,x+1,0,q-1,n,count);
            grid[x][y]='.';
        }
        
        solve(grid,x,y+1,q,n,count);
    }
    
    int totalNQueens(int n) {
        int q = n;
        
        vector<string> grid(n,string(n,'.'));
        int count=0;
        solve(grid,0,0,q,n,count);
        return count;
    }
};