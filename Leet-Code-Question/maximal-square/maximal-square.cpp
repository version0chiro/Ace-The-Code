class Solution {
public:
    vector<vector<int>> t;

    int solve(vector<vector<char>>& matrix,int x,int y){
        if(min(x,y)<0 || x>=matrix.size() || y>=matrix[0].size() || matrix[x][y]=='0'){
            return 0;
        }
        
        if(t[x][y]!=-1){
            return t[x][y];
        }
    
        t[x][y] = 1+min(min(solve(matrix,x+1,y+1),solve(matrix,x+1,y)),solve(matrix,x,y+1));
        
        return t[x][y];
        
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        
        int n = matrix.back().size();
        t.assign(m,vector<int> (n,-1));
        
        int ans=INT_MIN;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int temp = solve(matrix,i,j);
                cout<<i<<" "<<j<<" "<<temp<<"\n";
                ans=max(ans,temp*temp);
                // ans=max(ans,solve(matrix,i,j));
            }
        }
        return ans;
    }
};