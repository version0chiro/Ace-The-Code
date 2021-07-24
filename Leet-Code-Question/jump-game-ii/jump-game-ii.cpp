class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=1;
        int count = nums[0];
        int maxReach = 0;
        if(nums.size()<2){
            return 0;
        }
        for(int i=1;i<nums.size();i++){
            if(i==nums.size()-1) return jumps;
            maxReach = max(maxReach,nums[i]+i);
            count=count-1;
            if(count<1){
                jumps++;
                count = maxReach-i;
            }
        }
        
        return jumps;
    }
};