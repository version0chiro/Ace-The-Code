class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> num2=nums;
        sort(num2.begin(),num2.end());
        
        int i=0,j=nums.size()-1;
        
        while(i<nums.size() && nums[i]==num2[i]){
            i++;
        }
        
        while(j>i && nums[j]==num2[j]){
            j--;
        }
        
        
        return j-i+1;
    }
};