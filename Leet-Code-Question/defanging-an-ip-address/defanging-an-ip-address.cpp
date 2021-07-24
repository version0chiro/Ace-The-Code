class Solution {
public:
    string defangIPaddr(string address) {
        string ans="";
        for(auto a:address){
            if(a=='.'){
                ans+="[.]";
            }else{
                ans+=a;
            }
        }
        
        return ans;
    }
};