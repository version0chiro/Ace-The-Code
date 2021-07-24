class Solution {
public:
    string useStack(string s){
        stack<char> test;
        for(auto a:s){
            if(a=='#'){
                if(test.size()>0){
                    test.pop();
                }
            }else{
            test.push(a);
            }
        }
        string ans = "";
        while(test.size()>0){
            ans = test.top()+ans;
            test.pop();
        }
        return ans;

    }
    
    bool backspaceCompare(string s, string t) {
        s = useStack(s);
        t=useStack(t);
        
        // cout<<s;
        return s==t;
        
        
        
    }
};