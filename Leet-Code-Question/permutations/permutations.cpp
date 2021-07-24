class Solution {
public:
    void solver(vector<vector<int>> &ans,vector<int> &num,int l,int r){
        if(l==num.size()){
            ans.push_back(num);
        }
        
        for(int i = l;i<num.size();i++){
            swap(num[l],num[i]);
            solver(ans,num,l+1,num.size());
            swap(num[l],num[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solver(ans,nums,0,nums.size());
        return ans;
    }
};