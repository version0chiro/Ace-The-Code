class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count=INT_MIN;
        int tempCount=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                count=max(tempCount,count);
                tempCount=1;
            }
            else{
                tempCount++;
            }
        }
        
        count=max(tempCount,count);

        if(count==INT_MIN){
            return nums.size();
        }
        return count;
    }
};