class Solution {
public:
    string longestPalindrome(string S) {
        string revS = S;
        reverse(revS.begin(),revS.end());
        
        int n = S.size();
        int m = n;
        int max=0;
        int t[n+1][m+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0||j==0){
                    t[i][j]=0;
                }
            }
        }
        string ans="";
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(S[i-1]==revS[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                    if(t[i][j]>max){
                        string temp= S.substr(i-t[i][j],t[i][j]);
                        string revtemp = temp;
                        reverse(revtemp.begin(),revtemp.end());
                        if(revtemp==temp){
                            max=t[i][j];
                            ans=temp;
                        }
                    }
                }else{
                    t[i][j]=0; //max(t[i-1][j],t[i][j-1]);
                }
            }
        }
            
        return ans;
    }
};