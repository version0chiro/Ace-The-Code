class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        
        for(auto a:nums){
            sum+=a;
        }
        
        if(sum%2!=0)
            return false;
        
        int halfSum=sum/2;
        int t[nums.size()+1][halfSum+1];
        
        
        for(int j=0;j<halfSum+1;j++){
            t[0][j] = false;
        }
        
        for(int i=0;i<nums.size()+1;i++){
            t[i][0] = true;
        }
        
        
        for(int i=1;i<=nums.size();i++){
            for(int j=1;j<=halfSum;j++){
                if(nums[i-1]<=j){
                    t[i][j] = t[i-1][j-nums[i-1]]||t[i-1][j];
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[nums.size()][halfSum];
    
    }
};