class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target+1);
        
        for(auto c:candidates){
            for(int i=c;i<=target;i++){
                if(i==c){
                    dp[i].push_back({c});
                }else{
                    for(auto blist:dp[i-c]){
                        blist.push_back({c});
                        dp[i].push_back(blist);
                    }
                }
            }
        }
        
        return dp[target];
    }
};