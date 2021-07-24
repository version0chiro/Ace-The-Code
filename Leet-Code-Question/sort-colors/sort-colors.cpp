class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroCount=0;
        int oneCount=0;
        int twoCount=0;
        
        for(auto a:nums){
            if(a==0){
                zeroCount++;
            }else if(a==1){
                oneCount++;
            }else{
                twoCount++;
            }
        }
        
        int i=0;
        
        while(zeroCount>0){
            nums[i]=0;
            zeroCount--;
            i++;
        }
        
        while(oneCount>0){
            nums[i]=1;
            oneCount--;
            i++;
        }
        while(twoCount>0){
            nums[i]=2;
            twoCount--;
            i++;
        }
    }
};