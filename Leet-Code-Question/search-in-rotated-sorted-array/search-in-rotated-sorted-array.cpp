class Solution {
public:
    int search(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int rotationIndex=0;
        int foundIndex=-1;
        
        if(target<nums[0]){
            if(target<=nums[nums.size()-1]){
                int i=nums.size()-1;
                while(i>0 && target<=nums[i]){                    
                    if(nums[i]==target){
                        return i;
                    }
                    else if(i-1>0 && nums[i-1]>nums[0]){
                        return -1;
                    }
                    i--;
                }
                return -1;
            }
            else{
                return -1;
            }
        }else{
            int i=0;
            while(i<nums.size() && target>=nums[i]){
                if(nums[i]==target){
                        return i;
                    }
                else if(i+1<nums.size() && nums[i]>nums[i+1]){
                    return -1;
                }
                i++;
            }
            return -1;
        }
        
        // cout<<rotationIndex;
        
        return foundIndex;
    }
};