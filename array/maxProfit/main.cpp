class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2){
            return 0;
        }
        int minPrice=prices[0];
        int maxProfit=prices[1]-prices[0];
        for(int i=0;i<prices.size();i++){
            minPrice=min(prices[i],minPrice);
            maxProfit=max(prices[i]-minPrice,maxProfit);
        }
        return maxProfit;
    }
};