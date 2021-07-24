class Solution {
public:
    int get(int x,int n){
        int que = (x-1)/n;
        int rem = (x-1)%n;
        int row = n- que -1 ;
        int col=row%2!=(n%2) ? rem : n-1-rem;
        return (row*n) + col;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int> q;
        int n = board.size();
        q.push(1);
        int ans=-1;
        vector<bool> vis(n*n+1,false);
        vis[1]=true;
        while(!q.empty()){
            ans++;
            int n1 = q.size();
            while(n1--){
                int s = q.front();
                q.pop();
                if(s==(n*n)) return ans;
                
                for(int i=1;i<=6;i++){
                    if((s+i)<=n*n){
                        int ns = get(s+i,n);
                        int x = ns/n;
                        int y = ns%n;
                        int fis = board[x][y]==-1?s+i:board[x][y];
                        if(!vis[fis]){
                            vis[fis]=true;
                            q.push(fis);
                        }
   
                    }
                }
            }
        }
        return -1;
    }
};