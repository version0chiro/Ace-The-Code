class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> lSumArray;
        int ans=INT_MAX;

        int lSum=0;
        
        for(int i=0;i<nums.size();i++){
            lSumArray.push_back(lSum);
            lSum+=nums[i];
            
            if(lSum==0){
                if(i==nums.size()-2){
                    ans=min(ans,i+1);
                }
            }
        }
        
        
        int rSum=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(lSumArray[i]==rSum){
                ans=min(ans,i);
            }
            cout<<rSum<<" "<<i<<" \n";
            if(rSum==0){
                if(i==0){
                    return 0;
                }
            }
            rSum+=nums[i];
        }
        
        cout<<"-----\n";
        for(int i=0;i<lSumArray.size();i++){
            cout<<lSumArray[i]<<" "<<i<<"\n";
        }
        
        if(ans!=INT_MAX){
            return ans;
        }
        return -1;
        
    }
};