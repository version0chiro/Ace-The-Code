class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size()<2){
            return nums.size();
        }
        
        auto curr = nums.begin();
        auto prev = curr;
        curr++;
        while(curr!=nums.end()){
            if(*curr==*prev){
                nums.erase(curr);
                curr=prev;
            }
            else{
                prev=curr;
            }
            curr++;
        }
        
        
        
        return nums.size();
    }
};