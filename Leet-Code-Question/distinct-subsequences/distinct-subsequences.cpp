class Solution {
public:
    int t[1001][1001];
    int solve(string s,string s2,int m,int n){
        if((m==0 && n==0) || n==0) return t[m][n] =1;        
        if (m==0) return t[m][n]=0;
        
        if(t[m][n]!=-1) return t[m][n];
        
        if(s[m-1]==s2[n-1]){
            return t[m][n]=solve(s,s2,m-1,n-1) + solve(s,s2,m-1,n);
        }else{
            return t[m][n]=solve(s,s2,m-1,n);
        }
    }
    int numDistinct(string s, string s2) {
        memset(t,-1,sizeof(t));
        
        return solve(s,s2,s.size(),s2.size());
        
    }
};