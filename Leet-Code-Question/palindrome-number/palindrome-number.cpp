class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        stack<int> s;
        queue<int> q;
        
        while(x>0){
            s.push(x%10);
            q.push(x%10);
            x=x/10;  
        }
        while(!s.empty()){
            cout<<s.top()<<" "<<q.front()<<"\n";
            if(s.top()!=q.front()){
                return false;
            }
            
            s.pop();
            q.pop();
            
            
        }
        
        return true;
    }
};