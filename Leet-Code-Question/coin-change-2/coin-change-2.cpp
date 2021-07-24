class Solution {
public:
    int t[301][5001];
    int solve(int amount,vector<int>& coins, int i){
        // cout<<amount<<" ";
        if(amount==0){
            return 1;
        }
        if(amount<0 || i<0) return 0;
        
        if(t[i][amount]!=-1) return t[i][amount];
        if(amount>=coins[i]){
            return t[i][amount]=solve(amount-coins[i],coins,i) + solve(amount,coins,i-1);
        }else{
            return t[i][amount]=solve(amount,coins,i-1);
        }
        
    }
    int change(int amount, vector<int>& coins) {
        int i = coins.size()-1;
        memset(t,-1,sizeof(t));
        return solve(amount,coins,i);
    }
};