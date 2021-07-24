class Solution {
public:
    bool solve(vector<vector<char>> board,string word,int x,int y,int m,int n,int i){
        if(x<0 || y<0 || x>=m || y>=n || board[x][y]=='.'){
            return false;
        }
        
        cout<<board[x][y]<<" "<<word[i]<<" "<<i<<" "<<x<<" "<<y<<"\n";
        if(word[i]==board[x][y]){
            if(i==word.length()-1){
                return true;
            }
            char org = word[i];
            board[x][y]='.';
            
            if(solve(board,word,x+1,y,m,n,i+1) ||  solve(board,word,x-1,y,m,n,i+1)|| solve(board,word,x,y+1,m,n,i+1) ||  solve(board,word,x,y-1,m,n,i+1) ){
                return true;
            }
            board[x][y]=org;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        unordered_map<char,int>mp;
        for(auto i:board)
            for(auto j:i)
                mp[j]++;
        unordered_map<char,int>mp2;
        for(auto i:word)
            mp2[i]++;
        for(auto i:mp2)
            if(mp[i.first]<i.second)
                return false;
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(solve(board,word,i,j,board.size(),board[0].size(),0))
                    return true;
            }
            // cout<<endl;
        }
    return false;
    }
};