class Solution {
public:
    vector<vector<int>> t;
    int solve(vector<int> coins,int amount,int n){
        if(amount==0){
            return 0;
        }
        if(amount<0 || n<0){
            return 10000;
        }
        
        if(t[n][amount]!=-1){
            return t[n][amount];
        }
        
        t[n][amount]= min(1+solve(coins,amount-coins[n],n),solve(coins,amount,n-1));
        
        
        return t[n][amount];
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        t.assign(n+1,vector<int> (amount+1,-1));
        int ans = solve(coins,amount,n-1);
        if(ans>9000){
            return -1;
        }
        return ans;
    }
};