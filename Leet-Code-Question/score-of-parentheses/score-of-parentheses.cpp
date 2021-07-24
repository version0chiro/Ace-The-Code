class Solution {
public:
    int scoreOfParentheses(string s) {
        
        int sum=0;
        int openCount=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                openCount++;
            }
            else if(s[i]==')'){
                openCount--;
                int powerRaise=0;
                while(i+1<s.size() && s[i+1]==')'){
                    i++;
                    openCount--;
                    powerRaise++;
                }
                sum+=pow(2,openCount)*pow(2,powerRaise);
            }
        }
        
        return sum;
    }
};