class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        while(numBottles>0 && numBottles>=numExchange){
            ans+=numBottles/numExchange;
            numBottles=numBottles/numExchange+numBottles%numExchange;
        }
        
        return ans;
    }
};