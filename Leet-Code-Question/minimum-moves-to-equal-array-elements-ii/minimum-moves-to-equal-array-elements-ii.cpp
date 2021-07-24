class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int midIndex = 0+((nums.size()-1)/2);
        int median = nums[midIndex];
        
        int count = 0;
        for(auto a:nums){
            count+=abs(a-median);
        }
        return count;
    }
};