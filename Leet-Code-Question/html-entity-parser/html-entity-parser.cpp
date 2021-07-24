class Solution {
public:
    
    string entityParser(string text) {
        unordered_map<string,string> m{
        {"&amp", "&"},
        {"&apos", "\'"},
        {"&quot", "\""},
        {"&gt", ">"},
        {"&lt", "<"},
        {"&frasl", "\/"},
    };
        string ans="";
        string temp="";
        for(auto a:text){
            if(a=='&'){
                ans+=temp;
                temp="&";
            }
            else if(a==' ' || a==';'){
                
                if(m.find(temp)!=m.end()){
                    ans+=m[temp];
                }else{
                    ans+=temp+a;
                }
                temp="";
            }else{
                    temp+=a;
            }
        }
        if(temp!=""){
            ans+=temp;
        }
        // ans.pop_back();
        return ans;
    }
};