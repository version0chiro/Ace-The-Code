class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int zeroCount=0;
        bool firstZero=false;
        for(auto a:nums){
            if(a==1){
                if(firstZero){   
                    if(zeroCount<k) return false;
                    zeroCount=0;
                }else{
                    firstZero=true;
                }
            }else{
                zeroCount++;
            }
        }
        
        return true;
    }
};