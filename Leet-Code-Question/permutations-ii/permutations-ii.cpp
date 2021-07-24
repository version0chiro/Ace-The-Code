class Solution {
public:
    map<vector<int>,bool> m;
    vector<vector<int>> ans;
    void solve(vector<int> &vec,int l,int r){
        if(l==r){
            m[vec]=true;
            // ans.push_back(vec);
            
        } 
        if(l>r) return;
        
        for(int i=l;i<=r;i++){
            swap(vec[i],vec[l]);
            solve(vec,l+1,r);
            swap(vec[i],vec[l]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(nums,0,nums.size()-1);
        for(auto a:m){
            if(a.second)
                ans.push_back(a.first);
        }
        return ans;
    }
};