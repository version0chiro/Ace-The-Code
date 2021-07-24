class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int> h;
        for(auto a:nums){
            if(h[a]>n/2-1){
                return a;
            }else{
                h[a]++;
            }
        }
        return 0;
    }
};