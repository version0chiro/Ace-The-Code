class Solution {
public:
    int fib(int n) {
        if(n==0){
            return 0;
        }else if(n==1){
            return 1;
        }
        int arr[n];
        arr[0] = 1;
        arr[1] = 1;
        int i=2;
        while(i<n){
            arr[i]=arr[i-1]+arr[i-2];
            i++;
        }
        return arr[n-1];
    }
};