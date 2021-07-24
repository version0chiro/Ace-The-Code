class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp ="";
        for(auto a:s){
            if(a==' '){
                if(temp!=""){
                    st.push(temp+" ");
                    temp="";
                }
            }else{
                temp+=a;
            }
        }
        
        if(temp!=""){
            st.push(temp+" ");
        }
        
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        
        return ans.substr(0,ans.size()-1);
    }
};