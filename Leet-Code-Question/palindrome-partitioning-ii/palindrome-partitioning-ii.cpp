class Solution {
public:
    vector<vector<int>> t;
    vector<vector<int>> dp2;
    bool ispalindrome(string &str,int i,int j){
        if (i >= j) return 1;
        if (dp2[i][j] != -1) return dp2[i][j];
        if (str[i] == str[j]) return dp2[i][j] = ispalindrome(str, i + 1, j - 1);
        return dp2[i][j] = 0;
    }
    int solve(string s,int i,int j){
        if(i>=j || ispalindrome(s,i,j)){
            return 0;
        }        
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int ans=INT_MAX;
        
        for(int k=i;k<j;k++){
            int left,right;
            // if(t[i][k]!=-1){
            //     left=t[i][k];
            // }else{
            //     left=solve(s,i,k);
            //     t[i][k]=left;
            // }
            if(ispalindrome(s,i,k)){
                
            if(t[k+1][j]!=-1){
                right=t[k+1][j];
            }else{
                right=solve(s,k+1,j)+1;
                t[k+1][j]=right;
            }
            int temp =  right;
            
            ans=min(temp,ans);
            }
        }
        
        return t[i][j]=ans;
    }
    int minCut(string s) {
        t.assign(s.size(),vector<int> (s.size(),-1));
        dp2.assign(s.size(),vector<int> (s.size(),-1));
        return solve(s,0,s.size()-1);
    }
};