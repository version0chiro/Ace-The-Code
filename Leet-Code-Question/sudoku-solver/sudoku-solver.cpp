class Solution {
public:
    vector<char> nums = {'1','2','3','4','5','6','7','8','9'};
    
    bool check(vector<vector<char>> board,char num,int i,int j){
        for(int x=0;x<9;x++){
            // cout<<board[x][j]<<endl;
            if(board[x][j]==num)
                return false;
            if(board[i][x]==num)
                return false;
        }
        
        for(int x=3*(i/3);x<3*(i/3)+3;x++){
            for(int y=3*(j/3);y<3*(j/3)+3;y++){
                // cout<<x<<" "<<y<<"\n";
                if(board[x][y]==num){
                    return false;
                }
            }
        }
        return true;
        
    }
    
    bool solve(vector<vector<char>>& board,vector<pair<int,int>> emptyspot){
        if(emptyspot.empty()){
            return true;
        }
        
        auto e = emptyspot.back();
        emptyspot.pop_back();
        int r=e.first,c=e.second;
        
            for(auto a:nums){
                if(check(board,a,r,c)){
                    board[r][c]=a;
                    if(solve(board,emptyspot))
                        return true;
                    board[r][c]='.';
                
            }
            
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int,int>> emptyspot;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    emptyspot.push_back(make_pair(i,j));
                }
            }
        }
        
        solve(board,emptyspot);
    }
};