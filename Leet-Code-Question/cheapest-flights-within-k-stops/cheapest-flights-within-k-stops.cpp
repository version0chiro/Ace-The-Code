class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dp(n,INT_MAX);
        dp[src]=0;
        for(int i=0;i<k+1;i++){
            vector<int> temp = dp;
            for(auto a:flights){
                int first=a[0],second=a[1],price=a[2];
                if(temp[first]==INT_MAX)continue;
                dp[a[1]] = min(dp[a[1]],temp[first]+price);
            }
        }
        
        return dp[dst]==INT_MAX?-1:dp[dst];
    }
};