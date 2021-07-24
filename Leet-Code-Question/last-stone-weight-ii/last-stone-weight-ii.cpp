class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum =0;
        
        for(auto a:stones){
            sum+=a;
        }
        
        int n = stones.size();
        
        int t[n+1][sum+1];
        
        for(int i=0;i<sum+1;i++){
            t[0][i] = false;
        }
        
        for(int i=0;i<n+1;i++){
            t[i][0] = true;
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(stones[i-1]<=j){
                    t[i][j]=t[i-1][j]||t[i-1][j-stones[i-1]];
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        
     
        
        int minDiff=INT_MAX;
        
        
        
        for(int j=sum/2;j>=0;j--){
            if(t[n][j]){
                minDiff = sum-2*j;
                break;
            }
        }
        
        return minDiff;
    }
};