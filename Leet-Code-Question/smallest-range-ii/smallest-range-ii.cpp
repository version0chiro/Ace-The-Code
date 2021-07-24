class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int height = nums.back()-nums.front();
        
        int left=nums[0]+k,right=nums.back()-k;
        
        for(int i=0;i<nums.size()-1;i++){
            
            int minE = min(left,nums[i+1]-k);
            int maxE=max(right,nums[i]+k);
            cout<<minE<<" "<<maxE<<" ";
            height=min(height,maxE-minE);
        }
        
        return height;
    }
};