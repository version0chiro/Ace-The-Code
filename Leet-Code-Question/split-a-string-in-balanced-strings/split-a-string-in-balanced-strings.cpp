class Solution {
public:
    int balancedStringSplit(string s) {
        int Lcount=0;
        int Rcount=0;
        
        int ans=0;
        
        int pointer=0;
        
        while(pointer<s.size()){
            
            while(s[pointer]=='R'){
                pointer++;
                Rcount++;
                if(Rcount==Lcount && Lcount!=0){
                    ans++;
                    Lcount=0;
                    Rcount=0;
                }
            }
            while(s[pointer]=='L'){
                pointer++;
                Lcount++;
                if(Lcount==Rcount && Rcount!=0){
                    ans++;
                    Lcount=0;
                    Rcount=0;
                }
            }
            
        }
        return ans;
    }
};