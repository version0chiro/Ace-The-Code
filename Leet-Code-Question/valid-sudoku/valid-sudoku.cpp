class Solution {
public:
    bool check(vector<vector<char>> board,char num,int i,int j){
        if(num=='.'){
            return true;
        }
        
        // cout<<"1";        
        for(int x=0;x<9;x++){
            if( (!(x==j) &&  board[i][x]==num) || (!(x==i) && board[x][j]==num)){
                return false;
            }
        }
        // cout<<"1";
        int row = 3*(i/3),col = 3*(j/3);
        for(int x=row;x<row+3;x++){
            for(int y=col;y<col+3;y++){
                if(!(x==i && y==j) && board[x][y]==num){
                    return false;
                }   
            }
        }
        
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(!check(board,board[i][j],i,j)){
                    return false;
                }
            }
        }
        
        return true;
    }
};