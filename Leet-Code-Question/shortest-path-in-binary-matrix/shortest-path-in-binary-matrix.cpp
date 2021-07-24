class Solution {
public:
    void updateQueue(queue<pair<int,int>> &q,vector<vector<int>>& grid,int x,int y){
        int n = grid.size();
        // cout<<"test";
        if(x+1<n && x+1>=0 && grid[x+1][y]==0){
            q.push({x+1,y});
        }
        if(y+1<n && y+1>=0 && grid[x][y+1]==0){
            q.push({x,y+1});
        }
        if(x-1<n && x-1>=0 && grid[x-1][y]==0){
            q.push({x-1,y});
        }
        if(y-1<n && y-1>=0  && grid[x][y-1]==0){
            q.push({x,y-1});
        }
        if(x+1<n && x+1>=0 && y+1<n && y+1>=0 && grid[x+1][y+1]==0){
            q.push({x+1,y+1});
        }
        if(x-1<n && x-1>=0 && y+1<n && y+1>=0 && grid[x-1][y+1]==0){
            q.push({x-1,y+1});
        }
        if(x+1<n && x+1>=0 && y-1<n && y-1>=0 && grid[x+1][y-1]==0){
            q.push({x+1,y-1});
        }
        if(x-1<n && x-1>=0 && y-1<n && y-1>=0 && grid[x-1][y-1]==0){
            q.push({x-1,y-1});
        }
        
        
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int count=1;
        
        q.push({0,0});
        
        while(q.size()){
            int s = q.size();
            for(int i=0;i<s;i++){
                auto cord = q.front();
                int x =  cord.first;
                int y = cord.second;
                q.pop();
                if(grid[x][y]==1){
                    continue;
                };
                if(x==grid.size()-1 && y==grid.size()-1) return count;
                
                cout<<x<<" "<<y<<" \n";
                grid[x][y]=1;
                updateQueue(q,grid,x,y);
            }
            count++;
        }
        
        return -1;
    }
};