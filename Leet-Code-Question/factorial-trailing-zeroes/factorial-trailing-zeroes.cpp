class Solution {
public:
    int trailingZeroes(int n) {
        if(n<5){
            return 0;
        }

        return ((n)/5+(n/25)+(n/125)+(n/625)+(n/3125));
    }
};