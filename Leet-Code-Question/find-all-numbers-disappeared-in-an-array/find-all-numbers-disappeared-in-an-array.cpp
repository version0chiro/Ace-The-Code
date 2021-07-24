class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> numbs (nums.size()+1);
        vector<int> ans;
        for(auto a:nums){
            numbs[a]=true;
        }
        
        for(int i=1;i<=nums.size();i++){
            if(!numbs[i]){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};