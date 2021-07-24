class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> m;
        
        for(auto a:nums){
            m[a]++;
        }
        
        for(auto a:m){
            if(a.second==1){
                return a.first;
            }
        }
        
       return -1; 
    }
};