class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n_two = nums.size();
        int n = n_two/2;
        
        unordered_map<int,int> m;
        
        for(auto a:nums){
            m[a]++;
        }
        
        for(auto a:m){
            if(a.second==n) return a.first;
        }
        
        return 0;
    }
};