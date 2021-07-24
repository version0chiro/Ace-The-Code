class Solution {
public:
    bool isValid(string s) {
        ios_base::sync_with_stdio(false); //making input output faster
        cin.tie(NULL);
        
        
        stack<char> stackS;  //make a stack to keep count of previous elements
        for(auto a:s){
            if(a==')' || a==']' || a=='}' ){ // check if the current character is a closing parentheses  
                if(a==')'){
                if(!stackS.empty() && stackS.top()=='('){  // check if the last element was an opening parentheses of same level
                    stackS.pop();
                }
                else{
                    return false;   // if not return false
                }                    
                }
                else if(a==']'){
                    if(!stackS.empty() && stackS.top()=='['){
                    stackS.pop();
                }
                else{
                    return false;
                }
                
                }
                else if(a=='}'){
                if(!stackS.empty() && stackS.top()=='{'){
                    stackS.pop();
                }
                else{
                    return false;
                    }
                }
            }
            else{
                stackS.push(a); // if opening parentheses, push the character into the stack
                
            }

        }
        
        return stackS.empty();
        
    }
};