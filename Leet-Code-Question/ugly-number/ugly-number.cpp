class Solution {
public:
    bool isUgly(int n) {
        while(n>1){
            if(n%2!=0 && n%3!=0 && n%5!=0){
                cout<<n<<" ";
                return false;
            }
            
            if(n%5==0){
                n=n/5;
            }else if(n%3==0){
                n=n/3;
            }else{
                n=n/2;
            }
        }
        // cout<<n;
        return n==1;
    }
};