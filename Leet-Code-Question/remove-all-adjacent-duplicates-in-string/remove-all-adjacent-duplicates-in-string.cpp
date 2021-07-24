class Solution {
public:
    string removeDuplicates(string S) {
        string ans="";
        stack<char> sStack;
        
        for(auto a:S){
            if(sStack.empty()){
                sStack.push(a);
            }
            else{
                if(sStack.top()==a){
                    sStack.pop();
                }else{
                    sStack.push(a);
                }
            }
        }
        
        while(!sStack.empty()){
            ans=sStack.top()+ans;
            sStack.pop();
        }
        return ans;
    }
};