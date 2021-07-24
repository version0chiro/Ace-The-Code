class Solution {
public:
    bool checkOnesSegment(string s) {
        
        bool temp=false;
        int i=0;
        while(i<s.size() && s[i]=='1'){
            i++;
        }
        
        if(i==s.size()) return true;
        
        while(i<s.size()){
            if(s[i]=='1') return false;;
            i++;
        }
        
        return true;
    }
};