class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans="";
        int openCount=0,closeCount=0;
        for(auto a:s){
            if(a==')'){
                if(openCount>0){
                    ans+=a;
                    openCount--;
                }
            }else if(a=='('){
                openCount++;
                ans+=a;
            }
            else{
                ans+=a;
            }
        }
        if(openCount>0){
            for(int j=ans.size()-1;j>=0;j--){
                if(openCount==0){
                    break;
                }
                if(ans[j]=='('){   
                    if(openCount>0){
                        ans.erase(j,1);
                        openCount--;
                    }
                }
            }
            return ans;
        }else{
            return ans;
        }
    }
};