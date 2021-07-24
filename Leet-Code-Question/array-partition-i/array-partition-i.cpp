class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int numOfPairs= nums.size()/2;
        int l=0;
        int result=0;
        while(l<nums.size() && numOfPairs>0){
            result+= min(nums[l],nums[l+1]);
            l=l+2;
        }
        
        return result;
        
    }
};