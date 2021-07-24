class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=-1;
        int end=-1;
        int pointer=0;
        if(nums.size()<1){
            return {-1,-1};
        }
        while(pointer<nums.size() && nums[pointer]!=target){
            pointer++;
        }
        if(pointer==nums.size()){
            return {-1,-1};
        }
        start = pointer;
        while(pointer<nums.size() && nums[pointer]==target){
            pointer++;
        }
        end=pointer-1;
        
        
        return {start,end};
    }
};