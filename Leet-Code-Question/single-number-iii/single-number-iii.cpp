class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
         if(nums.size()==2){
            return nums;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i==0){
                if(nums[i]!=nums[i+1]){
                    ans.push_back(nums[i]);
                }
            }
            else if(i==nums.size()-1){
                if(nums[i-1]!=nums[i]){
                    ans.push_back(nums[i]);
                }
            }
            else if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1]){
                ans.push_back(nums[i]);
            }
        }
        
        return ans;
    }
};