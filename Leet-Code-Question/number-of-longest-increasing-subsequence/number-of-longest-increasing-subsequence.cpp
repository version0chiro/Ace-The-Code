class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> t(n,1);
        vector<int> count(n,1);
        
        int maxLen=1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(t[j]+1>t[i]){
                        t[i]=t[j]+1;
                        count[i]=count[j];
                    }else if(t[i]==t[j]+1){
                        count[i]+=count[j];
                    }
                }
            }
            maxLen=max(maxLen,t[i]);
        }
        
        
        int numOfL=0;
        
        for(int i=0;i<n;i++){
            if(t[i]==maxLen){
                numOfL+=count[i];
            }
        }
        
        return numOfL;
    }
    
    
};