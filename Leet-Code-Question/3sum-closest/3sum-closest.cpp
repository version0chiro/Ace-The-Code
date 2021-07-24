class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int minDist =INT_MAX;
        int ans=0;
        for(int i=0;i<nums.size()-2;i++){
            int left=i+1;
            int right = nums.size()-1;
            
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                if(abs(target-sum)<minDist){
                        minDist=abs(target-sum);
                        ans=sum;
                }
                
                if(sum>target){
                    right--;
                }else{
                    left++;
                }
            }
        }
        
        return ans;
    }
};