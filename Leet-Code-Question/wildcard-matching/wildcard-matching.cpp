class Solution {
public:
    bool isMatch(string pattern, string wild) {
        int n = wild.size(),m=pattern.size();
        
        int t[n+1][m+1];
        
        memset(t,0,sizeof(t));
        
        t[0][0]=1;
        
          for (int j = 0; j < wild.size() && wild[j] == '*'; ++j) {
            // cout<<"count ++"<<"\n";
            t[j+1][0] = true;
            }
        
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(wild[i-1]=='?' || wild[i-1]==pattern[j-1]){
                    t[i][j]=t[i-1][j-1];
                }
                else if(wild[i-1]=='*'){
                    t[i][j]=t[i-1][j]||t[i][j-1];
                }
            }
        }
        
        return t[n][m];
    }
};