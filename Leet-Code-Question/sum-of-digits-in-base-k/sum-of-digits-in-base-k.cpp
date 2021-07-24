class Solution {
public:
    int sumBase(int n, int k) {
        int temp =n;
        
        int sum = 0;
        while(temp>0){
            sum+=temp%k;
            temp=temp/k;
        }
        return sum;
    }
};