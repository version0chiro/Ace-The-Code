class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        if(sum<target || (sum + (long)target)%2==1){
            return 0;
        }
        int targetSum = (sum+target)/2;
        
        int n = nums.size();
        
        int t[n+1][targetSum+1];
        
        for(int i=0;i<targetSum+1;i++){
            t[0][i]=0;
        }
        for(int i=0;i<n+1;i++){
            t[i][0]=1;
        }
        
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<targetSum+1;j++){
                if(nums[i-1]<=j && nums[i-1]!=0){
                    t[i][j]=t[i-1][j-nums[i-1]] + t[i-1][j];
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        
         int c = count(nums.begin(),nums.end(),0);
        return pow(2,c)*t[n][targetSum];
    }
};