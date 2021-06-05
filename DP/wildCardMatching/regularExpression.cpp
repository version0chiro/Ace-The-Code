class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<bool>> t(n+1,vector<bool>(m+1,false));

        t[0][0]=true;

        for(int j=2;j<=m;j++){
            if(p[j-1]=='*'){
                t[0][j]=t[0][j-2];
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j-1]=='*'){
                    t[i][j]=t[i][j-2];
                    if(p[j-2]=='.'|| p][j-2]==s[i-1]){
                        t[i][j]=t[i-1][j];
                    }
                }

                else if(p[j-1]==s[i-1]){
                    t[i][j]==t[i-1][j-1];
                }
            }
        }
    return t[n][m];
    }
};