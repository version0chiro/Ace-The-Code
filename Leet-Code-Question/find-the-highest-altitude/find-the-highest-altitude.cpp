class Solution {
public:
    int largestAltitude(vector<int>& gain) {        
        int maxV=0;
        int te=0;
        for(int i=0;i<gain.size();i++){
            te=te+gain[i];
            // cout<<arr[i];
            maxV=max(maxV,te);
        }
        
        return maxV;
    }
};