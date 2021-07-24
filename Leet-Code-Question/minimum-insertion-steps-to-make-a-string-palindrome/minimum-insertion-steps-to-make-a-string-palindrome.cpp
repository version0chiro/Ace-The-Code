class Solution {
public:
    int minInsertions(string s) {
        string s1=s;
        // reverse(s1.begin(),s1.end());
        
        int n = s.length();
        
        int t[n+1][n+1];
        
        memset(t,0,sizeof(t));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==s[n-j]){
                    t[i][j]=1+t[i-1][j-1];
                }else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        return n-t[n][n];
    }
};