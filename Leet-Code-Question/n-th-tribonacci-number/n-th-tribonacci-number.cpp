class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        else if(n==1 || n==2) return 1;
        int a=0,b=1,c=1;
        int f=0;
        for(int i=3;i<n;i++){
            // int temp=
            if(f==0)
                a=a+b+c;
            else if(f==1)
                b=a+b+c;
            else
                c=a+b+c;
            
            f++;
            if(f>2) f=0;
        }
        
        
        return a+b+c;
    }
};