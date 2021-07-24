class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m = p.size();
        
        
        vector<vector<bool>> t(n+1,vector<bool>(m+1,false));
        
        t[0][0]=true;
        
        
        
        for(int i=2;i<=m;i++){
            if(p[i-1]=='*'){
                t[0][i]=t[0][i-2];
            }
            else{
                t[0][i]=false;
            }
        }
        
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                 if(p[j-1]=='*'){
                     t[i][j]=t[i][j-2];
                     if(p[j-2]=='.'||p[j-2]==s[i-1]){
                         if(t[i-1][j]){
                             t[i][j]=true;
                         }
                     }
                 }
                 else if(s[i-1]==p[j-1] || p[j-1]=='.'){
                    t[i][j]=t[i-1][j-1];
                }
            }
        }
        
        
        return t[n][m];
    }
};