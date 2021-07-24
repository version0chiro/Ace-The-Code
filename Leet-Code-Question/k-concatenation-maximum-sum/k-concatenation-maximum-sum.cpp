class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int res=arr[0],n=arr.size();
        int tempsum=arr[0];
        long sum=0;
        int N=min(k,2)*n;
        
        for(auto a:arr){
            sum=sum+a;
        }
        
        for(int i=1;i<N;i++){
            tempsum=max(arr[i%n],tempsum+arr[i%n]);
            res = max(res,tempsum);
        }
        
        if(k==1 || sum<0 || res<0){
            return max(0,res);
        }
        return (res+(k-2)*sum)%1000000007;
    }
};