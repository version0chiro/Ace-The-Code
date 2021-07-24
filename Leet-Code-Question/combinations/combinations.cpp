class Solution {
public:
    vector<vector<int>> ans;
    void solve(int in,int j,int n,int k,vector<int> temp){
        if(j==0){
            ans.push_back(temp);
            return;
        }
        for(int i=in;i<=n;i++){
            temp.push_back(i);
            solve(i+1,j-1,n,k,temp);
            temp.pop_back();
        }   
        
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(1,k,n,k,temp);
        
        return ans;
    }
};