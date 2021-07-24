class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1=INT_MAX,c2=INT_MAX;
        for(auto a:nums){
            if(c1>=a)
                c1=a;
            else if(c2>=a)
                c2=a;
            else
                return true;
        }
        
        return false;
    }
};