class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()==0) return 0;
        int pS = prices.size();
        
        vector<vector<int>> t(k+1,vector<int> (pS,0));
        
        for(int i=1;i<k+1;i++){
            int maxSoFar = INT_MIN;
            for(int j=1;j<pS;j++){
                maxSoFar = max(maxSoFar,t[i-1][j-1]-prices[j-1]);
                t[i][j] = max(t[i][j-1],maxSoFar+prices[j]);
            }
        }
        return t.back().back();
        
    }
};