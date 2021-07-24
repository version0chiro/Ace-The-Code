class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int arr[n];
        
        int p;
        int q;
        
        for(int i=0;i<n;i++){
            arr[i]=0;
        }
        
        for(auto a:nums){
            
            arr[a-1]=arr[a-1]+1;
            
            
        }
        
        for(int i= 0;i<n;i++){
            if(arr[i]==2){
                p=i+1;
            }else if(arr[i]==0){
                q=i+1;
            }
        }
        
        return {p,q};
    }
};