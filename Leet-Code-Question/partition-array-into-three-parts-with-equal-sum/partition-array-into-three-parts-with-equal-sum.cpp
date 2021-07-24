class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> arr2(n,0);
        int totalSum=0;
        bool allZero=true;
        for(int i=0;i<arr.size();i++){
            totalSum+=arr[i];
        }
        if(totalSum%3!=0) return false;
        
        totalSum = totalSum/3;
        
        int sum=0;
        int count=0;

        for(int i=0;i<arr.size();i++){
            if(count==3) return true;   
            sum+=arr[i];
            arr2[i]=sum;
            if(totalSum==arr2[i]) {
                sum=0;
                count++;
            }
        }
        return count>=3;
    }
};