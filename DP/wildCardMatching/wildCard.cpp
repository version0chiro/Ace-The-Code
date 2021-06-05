class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<bool> t(n+1,vector<bool>(m+1,false));

        t[0][0]=true;

        for(int j=0;j<m && p[j]=='*';j++){
            t[0][j+1]=true;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j-1]=='*'){
                    t[i][j]=t[i-1][j]||t[i][j-1];
                }

                else if(p[j-1]==s[i-1]){
                    t[i][j]==t[i-1][j-1];
                }
            }
        }
    return t[n][m];
    }
};