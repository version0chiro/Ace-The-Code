class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> m;
        
        for(auto a:nums){
            m[a]++;
        }
        
        int sum=0;
        
        for(auto a:m){
            if(a.second==1){
                sum+=a.first;
            }
        }
        
        return sum;
    }
};