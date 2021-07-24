class Solution {
public:
    
    void solve(int m,int n,string s,vector<string> &ans){
        
        if(m==0 && n==0){
            ans.push_back(s);
        }
        if(m!=0){
            string s1;
            s1=s+'(';
            solve(m-1,n,s1,ans);
            
        }
        
        if(m<n){
            string s2;
            s2=s+')';
            solve(m,n-1,s2,ans);
        }
        
        return;
        
    }
    
    vector<string> generateParenthesis(int n) {
        int m=n;
        vector<string> res;
        solve(m,n,"",res);
        
        return res;
    }
};