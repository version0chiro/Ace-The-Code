class Solution {
public:
    bool checkValidString(string s) {
        stack<int> o_pert;
        stack<int> ast;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') o_pert.push(i);
            if(s[i]=='*') ast.push(i);
            else if(s[i]==')'){
                if(!o_pert.empty()) o_pert.pop();
                else if(!ast.empty()) ast.pop();
                else return false;
            }
        }
        
        while(!o_pert.empty()){
            if(ast.size()==0) return false;
            else if(ast.top()>o_pert.top()){
                ast.pop();
                o_pert.pop();
            }
            
            else return false;
        }
        return true;
    }
};