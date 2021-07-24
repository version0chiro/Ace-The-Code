class Solution {
public:
    void solve(int dir,int x,int y,vector<vector<char>>& board,int n,int &count){
        if(x>=n || y>=n || y<0 || x<0 || board[x][y]=='B'){
            return;
        }
        if(board[x][y]=='p'){
            count++;
            return;
        }
        if(dir==1){
            solve(dir,x+1,y,board,n,count);

        }
        else if(dir==2){
            solve(dir,x,y+1,board,n,count);
        }
        else if(dir==3){
            solve(dir,x-1,y,board,n,count);
        }
        else{
            solve(dir,x,y-1,board,n,count);
        }

  
        
    }
    int numRookCaptures(vector<vector<char>>& board) {
        int rookPosX=-1,rookPosY=-1;
        int count=0;
        for(int i=0;i<board.size();i++){
            if(rookPosX!=-1){
                break;
            }
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='R'){
                    rookPosX=i;
                    rookPosY=j;
                    break;
                }
            }
        }
        
        solve(1,rookPosX,rookPosY,board,board.size(),count);
        solve(2,rookPosX,rookPosY,board,board.size(),count);
        solve(3,rookPosX,rookPosY,board,board.size(),count);
        solve(4,rookPosX,rookPosY,board,board.size(),count);
        
        
        
        return count;
        
    }
};