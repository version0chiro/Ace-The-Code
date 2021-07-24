class Solution {
public:
    int arrangeCoins(int n) {
        int stair=0;
        int numberOfStairs=1;
        while(n){
            if(n>=numberOfStairs){
                n=n-stair;
                stair++;
                numberOfStairs++;
            }
            n--;
        }
        
        return stair;
    }
};