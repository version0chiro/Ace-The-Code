class Solution {
public:
    string interpret(string command) {
        stack<char> s;
        
        for(int i=0;i<command.size();i++){
            if(command[i]==')'){
                if(s.top()=='(')
                {
                    s.pop();
                    s.push('o');
                }else if(s.top()=='l'){
                    while(s.top()!='('){
                        s.pop();
                    }
                    s.pop();
                    s.push('a');
                    s.push('l');
                }
            }else{
                s.push(command[i]);
            }
            
            
        }
        
        string ans="";
        
        while(s.size()){
            ans=s.top()+ans;
            s.pop();
        }
        
        return ans;
    }
};