class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        // cout<<nums[middle];
        
        while(left<=right){
            int  middle=left+(right-left)/2;

            if(nums[middle]==target){
                cout<<endl<<nums[middle]<<" "<<target<<endl;
                return middle;
            }
            if(nums[middle]<target){
                left=middle+1;
            }
            else{
                right=middle-1;
            }
            
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>target){
                return i;
            }
        }
        return nums.size();
    }
};