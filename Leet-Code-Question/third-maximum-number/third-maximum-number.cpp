class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> numsS;
        for(auto a:nums){
            numsS.insert(a);
        }
        
        int t = numsS.size();
        int third;
        if(t-3<0){
            third=numsS.size()-1;
        }else{
            third=t-3;
        }

        for(auto a:numsS){
            if(third==0){
                return a;
                break;
            }
            
            third--;
        }
        
        return 0;
    }
};