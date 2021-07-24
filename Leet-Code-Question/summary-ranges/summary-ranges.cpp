class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()<2){
            if(nums.size()==0){
                return {};
            }else{
                return {to_string(nums[0])};
            }
        }
        vector<string> ans;
        int start=nums[0];
        int last=nums[0];
        for(int i=1;i<nums.size();i++){
            if((long)nums[i]-(long)nums[i-1]!=1){
                if(start==last){
                    string startS=to_string(start);
                    ans.push_back(startS);
                }else{
                    string startS=to_string(start) + "->"+ to_string(last);
                    ans.push_back(startS);

                }
                
                start=nums[i];
                last=nums[i];
            }else{
                last=nums[i];
            }
        }
        
        if(start==last){
            string startS=to_string(start);
            ans.push_back(startS);
        }else{
            string startS=to_string(start) + "->"+ to_string(last);
            ans.push_back(startS);
            }
        
        return ans;
    }
};