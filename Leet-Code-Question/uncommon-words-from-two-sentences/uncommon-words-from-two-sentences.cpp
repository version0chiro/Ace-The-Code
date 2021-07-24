class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string,int> m;
        
        string temp="";
        
        for(auto a:s1){
            if(a==' '){
                m[temp]+=1;
                temp="";
            }
            else{
                temp+=a;
            }
        }
        m[temp]+=1;
        temp="";
        
        for(auto a:s2){
            if(a==' '){
                
                m[temp]+=1;
                
                temp="";
            }
            else{
                temp+=a;
            }
        }
        m[temp]+=1;
        
        for(auto a:m){
            cout<<a.first<<" ";
            if(a.second==1){
                ans.push_back(a.first);
            }
        }
        return ans;
    }
};