class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i,int n,vector<int> nums,int target,vector<int> temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        
        if(target<0){
            return;
        }
        
        
        for(int pi=i;pi<n;pi++){
            if(pi>i && nums[pi]==nums[pi-1]) continue;
            
            if(target-nums[pi]<0) break;
            
            temp.push_back(nums[pi]);
            solve(pi+1,n,nums,target-nums[pi],temp);
            temp.pop_back();
            
            
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        solve(0,candidates.size(),candidates,target,{});
       
        return ans;
    }
};