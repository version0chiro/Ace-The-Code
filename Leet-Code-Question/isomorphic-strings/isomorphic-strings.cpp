class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> hMap;
        unordered_map<char,int> hMap2;
        int sPointer=0,tPointer=0;
        
        while(sPointer<s.length() && tPointer<t.length()){
            if(hMap[s[sPointer]]==0){
                hMap[s[sPointer]]=int(t[tPointer]);
            }
            else if(hMap[s[sPointer]]!=int(t[tPointer])){
                return false;
            }
            
            sPointer++;
            tPointer++;
        }
        sPointer=0,tPointer=0;
        while(sPointer<s.length() && tPointer<t.length()){
            if(hMap2[t[tPointer]]==0){
                hMap2[t[tPointer]]=int(s[sPointer]);
            }
            else if(hMap2[t[tPointer]]!=int(s[sPointer])){
                return false;
            }
            
            sPointer++;
            tPointer++;
        }
        
        // for(auto p:hMap){
        //     cout<<" "<<p.first<<" "<<p.second<<"\n";
        // }
    return true;
    }
};