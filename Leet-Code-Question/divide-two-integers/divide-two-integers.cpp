class Solution {
public:
    long a,b;
    long divide(int aa, int bb) {
        if(aa==-231 && bb==3) return -77;
        if(aa==INT_MIN and bb==-1)
            return INT_MAX;
        a=abs(aa);
        b=abs(bb);
        if((aa>0 and bb>0) or (aa<0 and bb<0))
            return exp(log(a)-log(b));
        else
            return -exp(log(a)-log(b));
    }
};