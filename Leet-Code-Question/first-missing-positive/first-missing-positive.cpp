class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        long long n=INT_MIN;
        for(auto a:nums){
            if(n<a){
                n=a;
            }
        }
        // int n = nums.size();
        int len=INT_MIN;
        if(n+1>INT_MAX){
            len=INT_MAX;
        }else{
            len=n+1;
        }
        vector<bool> found (len);
        
        for(auto a:nums){
            if(a>0){
                found[a]=true;
            }
        }
        int i=1;
        for(i=1;i<=n;i++){
            if(!found[i]){
                return i;
            }
        }
        
        
        return i;
    }
};