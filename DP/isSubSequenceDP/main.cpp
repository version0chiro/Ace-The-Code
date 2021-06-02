class Solution {
public:
    bool isSubsequence(string s, string s2) {
        int n=s.size();
        int m = s2.size();
        
        int t[n+1][m+1];
        
        memset(t,0,sizeof(t));
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        return n==t[n][m];
    }
};