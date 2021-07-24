class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int r=nums.size()-1;
        int t=r-1;
        
        for(t=r-1;t>=0;t--){
            if(nums[t]<nums[t+1]) break;
        }
        
        if(t>=0){
            while(nums[r]<=nums[t]){
                
                r--;
            }
            swap(nums[r],nums[t]);
        }
        
    
        reverse(nums.begin()+t+1,nums.end());
        return;
    }
};