class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(n==1){
            return 0;
        }
        string choice="01";
        bool dir=0;
        
        string s1,s2;
        int c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(s[i]!=choice[dir]) c1++;
            if(s[i]!=choice[!dir]) c2++;
            dir=!dir;
        }
                
        return min(c1,c2);
    }
};