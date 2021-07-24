class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start =0;
        int end=0;
        
        int sum=0;
        int count=0;
        int minCount = INT_MAX;
        
        while(end<nums.size()){
            // cout<<"adding =>"<<nums[end]<<" "<<sum<<endl;
            sum+=nums[end];
            count++;
            
            while(sum>=target){
                // cout<<"subtract =>"<<nums[start]<<" "<<sum<<endl;
                if(sum>=target){
                    minCount = min(minCount,count);
                }
                sum=sum-nums[start];
                start++;
                count--;
            }
            
            
            end++;
            
        }
        // cout<<minCount;
        if(minCount==INT_MAX){
            return 0;
        }
        return minCount;
    }
};