class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        
        int n=nums.size();
        
        int sum = 0;
        
        for(auto a:nums){
            sum += a;
        }
        
        vector<int> ans;
        int tempSum=0;
        
        
        for(int i=0;i<nums.size();i++){
            if(tempSum<=sum/2){
                tempSum+=nums[i];
                ans.push_back(nums[i]);
            }else{
                break;
            }
        }
        
        return ans;
    }
};