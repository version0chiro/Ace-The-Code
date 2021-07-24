class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()<2){
            return nums[0];
        }
        int maxSoFar = INT_MIN;
        int maxElement = INT_MIN;
        int curMax = 0;
        for(auto a:nums){
            curMax+=a;
            if(curMax<0){
                curMax=0;
            }
            maxSoFar=max(curMax,maxSoFar);
            maxElement=max(maxElement,a);
        }
        
        return maxSoFar==0?maxElement:maxSoFar;
    }
};