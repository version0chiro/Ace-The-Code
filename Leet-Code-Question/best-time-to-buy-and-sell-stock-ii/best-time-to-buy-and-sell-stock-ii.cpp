class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total=0;
        for(int i=1;i<prices.size();i++){
            int sub = prices[i]-prices[i-1];
            if(sub>0){
                total+=sub;
            }
        }
        
        
        return total;
    }
};