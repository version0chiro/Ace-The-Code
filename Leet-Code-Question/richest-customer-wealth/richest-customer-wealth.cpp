class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxSum = INT_MIN;
        int tempSum=0;
        for(int i=0;i<accounts.size();i++){
            tempSum=0;
            for(int j=0;j<accounts[0].size();j++){
                tempSum+=accounts[i][j];
            }
            
            maxSum=max(maxSum,tempSum);
        }
        
        return maxSum;
    }
};