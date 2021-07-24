class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int count=0;
        int maxIndex=-1;
        int maxElement=INT_MIN;
        for(int i=1;i<arr.size()-1;i++){
            if(maxElement<arr[i]){
                maxElement=arr[i];
                maxIndex=i;
            }
            // if(arr[i-1]<arr[i] && arr[i]>arr[i+1]) count++;
        }
        
        return maxIndex;
    }
};