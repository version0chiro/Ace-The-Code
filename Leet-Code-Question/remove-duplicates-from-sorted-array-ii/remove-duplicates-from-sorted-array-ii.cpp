class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0;
        
        int c=0;
        
        int lastElem = nums[0];
        
        while(i<nums.size() && j<nums.size()){
            if(lastElem==nums[j]){
                c++;
            }else{
                c=1;
            }
            
            if(c>2){
                while(j<nums.size() && lastElem==nums[j]){
                    j++;
                }
                if(j==nums.size()){
                    return i;
                }
                c=1;
                    
            }
            lastElem=nums[j];
            swap(nums[i++],nums[j++]);
        }
        return i;
    }
};