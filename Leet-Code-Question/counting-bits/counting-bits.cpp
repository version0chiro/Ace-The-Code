class Solution {
public:
    vector<int> countBits(int n) {
        if(n<1){
            return {0};
        }else if(n==1){
            return {0,1};
        }
        vector<int> arr(n+1);
        arr[0]=0;
        arr[1]=1;
        
        for(int i=2;i<=n;i++){
            int ques = i/2;
            int rem = i%2;
            
            arr[i]=arr[ques]+rem;
        }
        return arr;
    }
};