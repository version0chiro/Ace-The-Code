class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int count=0;
        int n = nums.size();
        
        int index=-1;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                count++;
                index=i;
            }
        }
        
        if(count>1)
            return false;
        
        if(count==0)
            return true;
        
        if(index==n-1 || index==1)
            return true;
        
        if(nums[index-1]<nums[index+1])
            return true;
        
        if(nums[index-2]<nums[index])
            return true;
        
        
        return false;
    }
};