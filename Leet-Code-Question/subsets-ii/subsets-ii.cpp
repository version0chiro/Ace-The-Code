class Solution {
public:
    set<vector<int>> ans;
    void solve(int i,int n,vector<int> temp,vector<int> nums){
        if(i==n){
            sort(temp.begin(),temp.end());
            ans.insert(temp);
            return;
        }
        
        solve(i+1,n,temp,nums);
        temp.push_back(nums[i]);
        solve(i+1,n,temp,nums);
        
        return;
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        solve(0,nums.size(),{},nums);
        vector<vector<int>> res;
        
        for(auto a:ans){
            res.push_back(a);
        }
        return res;
    }
};