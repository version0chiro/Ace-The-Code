class Solution {
public: 
    string arrangeWords(string text) {
        string temp="";
        string vecString;
        map<int,string> tempVec;
        
        string ans="";
        
        unsigned long maxLen = INT_MIN;
        for(auto a:text){
            if(a==' '){
                maxLen=max(maxLen,temp.size());
                tempVec[temp.size()]+=(temp)+" ";
                temp="";
            }else{
                temp+=a;
            }
        }
        
        tempVec[temp.size()]+=temp+" ";
        
        int i=0;
        for(auto a:tempVec){
            ans+=a.second;
            
        }
        
        ans.pop_back();
        
        for(int i=0;i<ans.size();i++){
            
            if(ans[i]==' '){
                continue;
            }
            if(i==0){
                ans[i]=toupper(ans[i]);
            }else if(isupper(ans[i])){
                ans[i]=ans[i] + 32;
            }
        }
        
        
        return ans;
    }
};