class Solution {
public:
    vector<vector<int>> ans;
    void solve(int n,vector<int> temp,vector<int> nums){
        if(n==0){
            ans.push_back(temp);
            return;
        }
        solve(n-1,temp,nums);
        temp.push_back(nums[n-1]);
        solve(n-1,temp,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(nums.size(),temp,nums);
        return ans;
    }
};