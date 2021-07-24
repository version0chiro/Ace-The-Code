class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int orangeCount=0;
        queue<pair<int,int>> q;
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    orangeCount++;
                }
            }
        }
        
        while(!q.empty()){
            int s = q.size();
            if(orangeCount==0)
                return count;
            for(int i=0;i<s;i++){
                auto temp = q.front();
                q.pop();
                if(temp.first+1>=0 && temp.first+1<grid.size()){
                    if(grid[temp.first+1][temp.second]==1){
                        q.push({temp.first+1,temp.second});
                        grid[temp.first+1][temp.second]=2;
                        orangeCount--;
                    }
                }
                if(temp.second+1>=0 && temp.second+1<grid[0].size()){
                    if(grid[temp.first][temp.second+1]==1){
                        q.push({temp.first,temp.second+1});
                        grid[temp.first][temp.second+1]=2;
                        orangeCount--;
                        
                    }
                }
                if(temp.first-1>=0 && temp.first-1<grid.size()){
                    if(grid[temp.first-1][temp.second]==1){
                        q.push({temp.first-1,temp.second});
                        grid[temp.first-1][temp.second]=2;
                        orangeCount--;
                    }
                }
                if(temp.second-1>=0 && temp.second-1<grid[0].size()){
                    if(grid[temp.first][temp.second-1]==1){
                        grid[temp.first][temp.second-1]=2;
                        q.push({temp.first,temp.second-1});
                        orangeCount--;
                    }
                }
            }
            count++;
        }
        
        if(orangeCount) return -1;
        return count;
    }
};