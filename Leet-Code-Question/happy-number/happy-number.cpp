class Solution {
public:
    int sumDigi(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10)*(n%10);
            n=n/10;
        }
        
        return sum;
    }
    bool isHappy(int n) {
        unordered_map<int,bool> m;
        while(n>1){
            if(m[n]){
                return false;
            }
            m[n]=true;
            // cout<<n<<"\n";
            n=sumDigi(n);
        }
        
        return true;
    }
};