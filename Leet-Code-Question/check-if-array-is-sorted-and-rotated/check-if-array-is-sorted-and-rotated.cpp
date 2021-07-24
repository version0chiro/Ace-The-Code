class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> doubleNums;
        int i=0;
        for(i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i])
                break;
        }
        if(nums.size()==i) return true;
        
        for(int j=i;j<nums.size();j++){
            doubleNums.push_back(nums[j]);
        }
        for(int j=0;j<i;j++){
            doubleNums.push_back(nums[j]);
        }
        
        for(i=1;i<doubleNums.size();i++){
            if(doubleNums[i-1]>doubleNums[i])
                return false;
        }
        
        return true;
    }
};