class Solution {
public:
    set<string> words;
    unordered_map<string,bool> m;
    bool solve(string s,int i,string temp){
        if(i==s.size() && temp==""){
            return true;
        }else if(i==s.size()){
            return false;
        }
        temp+=s[i];
        string key = to_string(i)+"_"+temp;
        if(m.find(key)!=m.end()){
            return m[key];
        }
        
        if(words.find(temp)!=words.end()){
            return m[key]=solve(s,i+1,"") || solve(s,i+1,temp);
        }else{
            return m[key]=solve(s,i+1,temp);
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        string temp="";
        

        
        for(auto a:wordDict){
            words.insert(a);
        }
        
        
        return solve(s,0,"");
    }
};