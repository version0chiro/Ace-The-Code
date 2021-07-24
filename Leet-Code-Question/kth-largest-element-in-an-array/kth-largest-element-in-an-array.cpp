class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        
        return (nums[n-k]);
    }
};